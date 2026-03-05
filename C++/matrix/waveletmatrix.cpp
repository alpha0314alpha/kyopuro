class waveletmatrix{
private:
    int n, LOG;
    vector<vector<int>> bit;
    vector<int> mid;

public:
    waveletmatrix(const vector<ll>& v, ll maxv = (1LL<<60)){
        n = v.size();
        LOG = 0;
        while ((1LL<<LOG) <= maxv) LOG++;
        bit.assign(LOG, vector<int>(n+1));
        mid.resize(LOG);
        vector<ll> cur = v, nxt(n);
        for (int level = LOG-1; level >= 0; level--){
            for (int i = 0; i < n; i++){
                bit[level][i+1] = bit[level][i] + ((cur[i]>>level)&1);
            }
            int zero = 0;
            for (ll x: cur) if (!((x>>level)&1)) zero++;
            mid[level] = zero;
            int z = 0, o = zero;
            for (ll x: cur){
                if ((x>>level)&1) nxt[o++] = x;
                else nxt[z++] = x;
            }
            cur.swap(nxt);
        }
    }

    int rank(int l, int r, ll x){
        for (int level = LOG-1; level >= 0; level--){
            int b = (x>>level)&1;
            int l1 = bit[level][l];
            int r1 = bit[level][r];
            if (b){
                l = mid[level] + l1;
                r = mid[level] + r1;
            }
            else{
                l -= l1;
                r -= r1;
            }
        }
        return r-l;
    }

    ll kth(int l, int r, int k){
        if(k < 0 || k >= r-l) return -1;
        ll res = 0;
        for (int level = LOG-1; level >= 0; level--){
            int l1 = bit[level][l], r1 = bit[level][r];
            int zero = (r-l)-(r1-l1);
            if (k < zero){
                l -= l1;
                r -= r1;
            }
            else{
                res |= (1LL<<level);
                k -= zero;
                l = mid[level]+l1;
                r = mid[level]+r1;
            }
        }
        return res;
    }

    int less_than(int l, int r, ll x){
        int cnt = 0;
        for (int level = LOG-1; level >= 0; level--){
            int b = (x>>level)&1;
            int l1 = bit[level][l];
            int r1 = bit[level][r];
            if (b){
                cnt += (r-l)-(r1-l1);
                l = mid[level]+l1;
                r = mid[level]+r1;
            }
            else{
                l -= l1;
                r -= r1;
            }
        }
        return cnt;
    }

    int range_freq(int l, int r, ll a, ll b){
        return less_than(l, r, b)-less_than(l, r, a);
    }
};