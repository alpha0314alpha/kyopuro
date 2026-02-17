ll modpow(ll a, ll e, ll mod = MOD){
    if (e == 0) return 1;
    ll res = 1;
    while (e){
        if (e&1) res = res*a%mod;
        a = a*a%mod;
        e >>= 1;
    }
    return res;
}

vector<bool> make_isprime(int N){
    vector<bool> isprime(N+1, true);
    isprime[0] = false, isprime[1] = false;
    for (int i = 2; i*i <= N; i++){
        if (!isprime[i]) continue;
        for (int j = i*i; j <= N; j += i){
            isprime[j] = false;
        }
    }
    return isprime;
}

template<typename T> map<T, T> prime_factor(T N){
    map<T, T> res;
    for (T i = 2; i*i <= N && N > 1; i++){
        while (N%i == 0){
            res[i]++;
            N /= i;
        }
    }
    if (N > 1) res[N]++;
    return res;
}

template<typename T> T nc2(T n){
    return n*(n-1)/2;
}


template<ll mod, ll g> void ntt(vector<num::modint<mod>> & a, bool invert) {
    int n = a.size();
    static vector<int> rev;
    static vector<num::modint<mod>> roots{ {0}, {1} };
    if ((int)rev.size() != n) {
        int k = __builtin_ctz(n);
        rev.assign(n, 0);
        for (int i = 0; i < n; i++) {
            rev[i] = (rev[i>>1] >> 1) | ((i&1) << (k-1));
        }
    }
    if ((int)roots.size() < n) {
        int k = __builtin_ctz(roots.size());
        roots.resize(n);
        while ((1 << k) < n) {
            auto e = num::modint<mod>(g).pow((mod - 1) >> (k + 1));
            for (int i = 1 << (k - 1); i < (1 << k); i++) {
                roots[2*i] = roots[i];
                roots[2*i+1] = roots[i] * e;
            }
            k++;
        }
    }
    for (int i = 0; i < n; i++) {
        if (i < rev[i]) swap(a[i], a[rev[i]]);
    }
    for (int len = 1; len < n; len <<= 1) {
        for (int i = 0; i < n; i += 2*len) {
            for (int j = 0; j < len; j++) {
                auto u = a[i+j];
                auto v = a[i+j+len] * roots[len + j];
                a[i+j] = u + v;
                a[i+j+len] = u - v;
            }
        }
    }
    if (invert) {
        reverse(a.begin() + 1, a.end());
        auto inv_n = num::modint<mod>(n).inv();
        for (auto &x : a) x *= inv_n;
    }
}

template<ll mod, ll g>
vector<num::modint<mod>> multiply_ntt( const vector<num::modint<mod>>& a, const vector<num::modint<mod>>& b) {
    if (a.empty() || b.empty()) return {};
    int need = a.size() + b.size() - 1;
    int n = 1;
    while (n < need) n <<= 1;
    vector<num::modint<mod>> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    fa.resize(n);
    fb.resize(n);
    ntt<mod, g>(fa, false);
    ntt<mod, g>(fb, false);
    for (int i = 0; i < n; i++) fa[i] *= fb[i];
    ntt<mod, g>(fa, true);
    fa.resize(need);
    return fa;
}

ull floor_sum_unsigned(ull n, ull m, ull a, ull b) {
    ull ans = 0;
    while (true){
        if (a >= m){ ans += n*(n-1)/2*(a/m); a %= m; }
        if (b >= m){ ans += n*(b/m); b %= m; }
        ull y_max = a*n+b;
        if (y_max < m) break;
        n = (ull)(y_max/m);
        b = (ull)(y_max%m);
        swap(m, a);
    }
    return ans;
}

ll safe_mod(ll x, ll m) {
    x %= m;
    if (x < 0) x += m;
    return x;
}

ll floor_sum(ll n, ll m, ll a, ll b) {
    assert(0 <= n && n < (1LL << 32));
    assert(1 <= m && m < (1LL << 32));
    ull ans = 0;
    if (a < 0){
        ull a2 = safe_mod(a, m);
        ans -= 1ULL*n*(n-1)/2*((a2-a)/m);
        a = a2;
    }
    if (b < 0){
        ull b2 = safe_mod(b, m);
        ans -= 1ULL*n*((b2-b)/m);
        b = b2;
    }
    return ans+floor_sum_unsigned(n, m, a, b);
}

ull floor_sqrt(ull n){
    ull x = sqrtl((ld)n);
    while ((x+1)*(x+1) <= n) x++;
    while (x*x > n) x--;
    return x;
}

bool is_square(ull n){
    ull x = floor_sqrt(n);
    return x*x == n;
}