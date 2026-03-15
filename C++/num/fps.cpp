    template<typename mint, ll g> struct fps : vector<mint> {
        using vector<mint>::vector;
        using FPS = fps;

        FPS &operator+=(const FPS &r){
            if(r.size()>this->size()) this->resize(r.size());
            for(int i=0;i<(int)r.size();i++) (*this)[i] += r[i];
            return *this;
        }

        FPS &operator*=(const FPS &r){
            *this = multiply_ntt<mint::mod, g>(*this, r);
            return *this;
        }

        FPS operator*(const FPS &r) const { return FPS(*this) *= r; }

        FPS diff() const {
            FPS res(max(0,(int)this->size()-1));
            for(int i=1;i<(int)this->size();i++) res[i-1] = (*this)[i]*mint(i);
            return res;
        }

        FPS integral() const {
            FPS res(this->size()+1);
            res[0] = mint(0);
            for(int i=0;i<(int)this->size();i++) res[i+1] = (*this)[i]/mint(i+1);
            return res;
        }

        FPS inv(int deg = -1) const {
            assert(!this->empty() && (*this)[0]!=0);
            if(deg==-1) deg=this->size();
            FPS r(1);
            r[0] = (*this)[0].inv();
            int n = 1;
            while(n < deg){
                n <<= 1;
                FPS f(this->begin(), this->begin()+min((int)this->size(), n));
                FPS nr = multiply_ntt<mint::mod,g>(r, r);
                nr = multiply_ntt<mint::mod,g>(nr, f);
                nr.resize(n);
                for(int i=0;i<n;i++) nr[i] = r[i]*2 - nr[i];
                r = nr;
            }
            r.resize(deg);
            return r;
        }

        FPS log(int deg=-1) const {
            assert(!this->empty() && (*this)[0]==mint(1));
            if(deg==-1) deg=this->size();
            return (this->diff() * this->inv(deg)).integral().pre(deg);
        }

        FPS exp(int deg=-1) const {
            assert(!this->empty() && (*this)[0]==mint(0));
            if(deg==-1) deg=this->size();
            FPS r(1); r[0]=1;
            int n=1;
            while(n<deg){
                n<<=1;
                FPS ln = r.log(n);
                for(int i=0;i<n;i++) ln[i] = (*this)[i]-ln[i];
                ln[0] += mint(1);
                r = r*ln;
                r.resize(n);
            }
            r.resize(deg);
            return r;
        }

        FPS pow(int64_t k, int deg=-1) const {
            if(deg==-1) deg=this->size();
            if(k==0){
                FPS res(deg); if(deg) res[0]=1;
                return res;
            }
            int i0=0;
            while(i0<(int)this->size() && (*this)[i0]==mint(0)) i0++;
            if(i0>=deg) return FPS(deg);
            mint coeff = (*this)[i0];
            FPS f(this->begin()+i0,this->end());
            for(auto &x:f) x /= coeff;
            FPS res = (f.log(deg-i0*k) * k).exp(deg-i0*k);
            for(auto &x:res) x *= coeff.pow(k);
            FPS ret(deg);
            for(int i=0;i<(int)res.size();i++) ret[i+i0*k] = res[i];
            return ret;
        }

        FPS pre(int sz) const {
            FPS res(begin(*this), begin(*this)+min((int)this->size(),sz));
            res.resize(sz);
            return res;
        }
    };
