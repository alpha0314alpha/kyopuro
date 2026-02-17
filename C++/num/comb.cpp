class comb{
private:
    vector<ll> fact, invfact;
    ll mod;
    int size;
public:
    comb(int n, ll m){
        mod = m, size = n;
        fact.resize(size+1);
        invfact.resize(size+1);
        for (int i = 0; i <= size; i++){
            if (i == 0) fact[i] = 1;
            else fact[i] = fact[i-1]*i%mod;
        }
        invfact[n] = modpow(fact[n], mod-2, mod);
        for (int i = size; i >= 1; i--){
            invfact[i-1] = invfact[i]*i%mod;
        }
    }

    ll factorial(int n){
        if (n > size) return -1;
        return fact[n];
    }

    ll npr(int n, int r){
        if (r < 0 || r > n || n > size) return 0;
        return fact[n]*invfact[n-r]%mod;
    }

    ll ncr(int n, int r){
        if (r < 0 || r > n || n > size) return 0;
        return fact[n]*invfact[r]%mod*invfact[n-r]%mod;
    }

    ll nhr(int n, int r){
        if (n <= 0 || r < 0 || n+r-1 > size) return 0;
        return ncr(n+r-1, r);
    }
};