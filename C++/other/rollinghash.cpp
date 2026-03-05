class rollinghash{
private:
    const ll mod = 1000000007;
    const ll BASE = 100;
    vector<ll> hash;
    vector<ll> power;

public:
    rollinghash(const string& S){
        int N = S.size();
        hash.resize(N+1);
        power.resize(N+1);
        power[0] = 1;
        for (int i = 0; i < N; i++) power[i+1] = (power[i]*BASE)%mod;
        hash[0] = 0;
        for (int i = 0; i < N; i++) hash[i+1] = (hash[i]*BASE+S[i])%mod;
    }

    ll get(int l, int r){
        ll res = hash[r]-(hash[l]*power[r-l])%mod;
        if (res < 0) res += mod;
        return res;
    }
};