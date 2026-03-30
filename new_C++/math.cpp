ll safe_mod(ll x, ll mod){
    x %= mod;
    if (x < 0) x += mod;
    return x;
}

ll modpow(ll x, ll n, ll mod){
    ll res = 1, y = x%mod;
    while (n){
        if (n&1) res = res*y%mod;
        y = y*y%mod;
        n >>= 1;
    }
    return res;
}

pair<ll, ll> inv_gcd(ll a, ll b){
    a = safe_mod(a, b);
    if (a == 0) return make_pair(b, 0);
    ll s = b, t = a, m0 = 0, m1 = 1;
    while (t){
        ll u = s/t;
        s -= t*u;
        m0 -= m1*u;
        swap(s, t);
        swap(m0, m1);
    }
    if (m0 < 0) m0 += b/s;
    return make_pair(s, m0);
}

bool isprime(int n){
    if (n <= 1) return false;
    if (n == 2 || n == 7 || n == 61) return true;
    if (n%2 == 0) return false;
    int d = n-1;
    while (d%2 == 0) d /= 2;
    for (int a : {2, 7, 61}){
        int t = d;
        int y = modpow(a, t, n);
        while (t != n-1 && y != 1 && y != n-1) y = y*y%n, t <<= 1;
        if (y != n-1 && t%2 == 0) return false;
    }
    return true;
}