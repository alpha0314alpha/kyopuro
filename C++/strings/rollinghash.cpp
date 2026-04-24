class rollinghash{
private:
    const array<ll, 5> mod = {998244353, 1000000007, 1000000009, 1000000021, 1000000033};
    const ll base = 100; 
    vector<array<ll, 5>> hash, power;

public:
    rollinghash(const string& S){
        int N = S.size();
        hash.resize(N+1);
        power.resize(N+1);
        power[0] = {1, 1, 1, 1, 1};
        hash[0] = {0, 0, 0, 0, 0};
        for (int i = 0; i < N; i++) for (int j = 0; j < 5; j++){
            power[i+1][j] = (power[i][j]*base)%mod[j];
        }
        for (int i = 0; i < N; i++) for (int j = 0; j < 5; j++){
            hash[i+1][j] = (hash[i][j]*base+S[i])%mod[j];
        }
    }

    array<ll, 5> get(int l, int r){
        array<ll, 5> res;
        for (int i = 0; i < 5; i++){
            ll num = hash[r][i]-(hash[l][i]*power[r-l][i])%mod[i];
            if (num < 0) num += mod[i];
            res[i] = num;
        }
        return res;
    }
};

