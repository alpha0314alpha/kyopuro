namespace fps{
    using atcoder::convolution;
    using mint = atcoder::modint998244353;
    using vm = vector<mint>;
#define d (*this)
#define s int(vm::size())
    struct fps : vm{
        template<class...Args> fps(Args...args): vm(args...) {}
        fps(initializer_list<mint> a): vm(a.begin(), a.end()) {}
        fps(): vm() {}
        void rsz(int n){ if (s < n) resize(n); }
        fps& low_(int n){ resize(n); return d; }
        fps low(int n) const{ return fps(d).low_(n); }
        mint& operator[] (int i){ rsz(i+1); return vm::operator[](i); }
        mint operator[] (int i) const{ return i < s? vm::operator[](i): 0; }
        mint operator()(mint x) const{
            mint r;
            for (int i = s-1; i >= 0; i--) r = r*x+d[i];
            return r;
        }
        fps operator- () const{
            fps r(d);
            for (int i = 0; i < s; i++) r[i] = -r[i];
            return r;
        }
        fps& operator+= (const fps& a){
            rsz(a.size());
            for (int i = 0; i < (int)a.size(); i++) d[i] += a[i];
            return d;
        }
        fps& operator-= (const fps& a){
            rsz(a.size());
            for (int i = 0; i < (int)a.size(); i++) d[i] -= a[i];
            return d;
        }
        fps& operator*= (const fps& a){
            vm res = convolution(d, a);
            d = fps(res.begin(), res.end());
            return d;
        }
        fps& operator*= (mint a){
            for (int i = 0; i < s; i++) d[i] *= a;
            return d;
        }
        fps& operator/= (mint a){
            for (int i = 0; i < s; i++) d[i] /= a;
            return d;
        }
        fps operator+ (const fps& a) const{ return fps(d) += a; }
        fps operator- (const fps& a) const{ return fps(d) -= a; }
        fps operator* (const fps& a) const{ return fps(d) *= a; }
        fps operator* (mint a) const{ return fps(d) *= a; }
        fps operator/ (mint a) const{ return fps(d) /= a; }
        fps operator~ () const{
            fps r({d[0].inv()});
            for (int i = 1; i < s; i <<= 1) r = r*mint(2)-(r*r*low(i<<1)).low(i<<1);
            return r.low_(s);
        }
        fps& operator/= (const fps& a){ int w = s; d *= ~a; return d.low_(w); }
        fps operator/ (const fps& a) const{ return fps(d) /= a; }
        fps integ() const{
            fps r;
            for (int i = 0; i < s; i++) r[i+1] = d[i]/(i+1);
            return r;
        }
        friend ostream& operator<< (ostream& os, const fps& a){
            for (int i = 0; i < (int)a.size(); i++) os << (i? " ": "") << a[i].val();
            return os;
        }
        fps operator>> (int k) const{
            if (s <= k) return fps();
            return fps(this->begin()+k, this->end());
        }
        fps operator<< (int k) const{
            fps r(k, 0);
            r.insert(r.end(), this->begin(), this->end());
            return r;
        }
        fps log(int n) const{
            return (this->diff()*this->inv(n)).low(n-1).integ().low(n);
        }
        fps exp(int n) const{
            fps r({1});
            for (int i = 1; i < n; i <<= 1){
                r = r*(fps({1})-r.log(i<<1)+this->low(i<<1));
                r = r.low(i<<1);
            }
            return r.low(n);
        }
        fps diff() const{
            if (s == 0) return fps();
            fps r(max(0, s-1));
            for (int i = 1; i < s; i++) r[i-1] = d[i]*i;
            return r;
        }
        fps inv(int n) const{
            fps r({d[0].inv()});
            int m = 1;
            while (m < n){
                m <<= 1;
                fps f = this->low(m);
                fps nr = r*r*f;
                r = (r*mint(2)-nr).low_(m);
            }
            return r.low(n);
        }
        fps pow(ll k, int n) const{
            if (k == 0){
                fps r(n);
                r[0] = 1;
                return r;
            }
            int i = 0;
            while (i < s && d[i] == 0) i++;
            if (i == s) return fps(n);
            if ((ll)i*k >= n) return fps(n);
            mint c = d[i];
            fps g = this->low(n);
            g = g>>i;
            g /= c;
            fps res = (g.log(n)*mint(k)).exp(n);
            res *= c.pow(k);
            res = res<<(i*k);
            return res.low(n);
        }
        fps poly_pow(ll k, int n) const{
            fps res(n), f = this->low(n);
            res[0] = 1;
            while(k){
                if (k&1) res = (res*f).low(n);
                f = (f*f).low(n);
                k >>= 1;
            }
            return res;
        }
    };
#undef s
#undef d
} 
