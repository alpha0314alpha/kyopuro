#include <bits/stdc++.h>
#define INF (1ll<<60)
// #define MOD 998244353
#define MOD 1000000007
#define EPS 1e-14
#define PI acosl(-1)
#define lb lower_bound
#define ub upper_bound
#define bs binary_search
#define ciN cin
#define npos string::npos
#define nextp next_permutation
#define maxe max_element
#define mine min_element
#define accu accumulate
#define popc __builtin_popcount
#define elif else if 
#define nall(A) A.begin(), A.end()
#define rall(A) A.rbegin(), A.rend()
#define rep(i, n) for(int i = 0; i < (n); i++) 
#define rrep(i, n) for(int i = (n)-1; i >= 0; i--)
#define each(i, a) for(auto& i : a)
#define out(x, y) (!(0 <= x && x < H && 0 <= y && y < W))
#define yes cout<<"Yes"<<endl
#define no cout<<"No"<<endl
#define yesno(a) cout<<(a?"Yes":"No")<<endl
#define sanko(a, b, c) (a? b: c)
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
template<typename T> using pq = priority_queue<T>;
template<typename T> using pqg = priority_queue<T, vector<T>, greater<T>>;
template<typename T> using vv = vector<vector<T>>;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, -1, 0, 1};
const int dx8[] = { 1, 1, 0, -1, -1, -1, 0, 1 };
const int dy8[] = { 0, -1, -1, -1, 0, 1, 1, 1 };
const string abcdefghijklmnopqrstuvwxyz = "abcdefghijklmnopqrstuvwxyz";
const string ABCDEFGHIJKLMNOPQRSTUVWXYZ = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
template<typename T> bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<typename T> bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<typename T> T nc2(T n){ return n*(n-1)/2; }

template<typename T> istream& operator>>(istream& is, vector<T>& v) {
    for (T& x : v) is >> x;
    return is;
}

vector<pair<char, int>> to_rle(const string& S) {
	vector<pair<char, int>> res;
	for (char i : S) {
		if (res.empty() || res.back().first != i) res.push_back({ i, 1 });
		else res.back().second++;
	}
	return res;
}

template<typename T> vector<pair<T, int>> to_rle(const vector<T>& A){
    vector<pair<T, int>> res;
    for (T i : A){
        if (res.empty() || res.back().first != i) res.push_back({i, 1});
        else res.back().second++;
    }
    return res;
}

template<typename T> vector<int> zaatu(const vector<T>& A){
    int N = (int)A.size();
    vector<T> B = A;
    sort(B.begin(), B.end());
    B.erase(unique(B.begin(), B.end()), B.end());
    vector<int> res(N);
    for (int i = 0; i < N; i++){
        res[i] = lower_bound(B.begin(), B.end(), A[i])-B.begin();
    }

    return res;
}

template<typename T> void output(const vector<T>& A, bool ln){
    int N = (int)A.size();
    for (int i = 0; i < N; i++){
        cout << A[i] << (ln || i == N-1? '\n': ' ');
    }
}

template<typename T> map<T, int> prime_factor(T N){
    map<T, int> res;
    for (T i = 2; i*i <= N && N > 1; i++){
        while (N%i == 0){
            res[i]++;
            N /= i;
        }
    }
    if (N > 1) res[N]++;
    return res;
}

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

bool iskaibun(string s){
    string t = s;
    reverse(t.begin(), t.end());
    return s == t;
}

class dsu{
private:
    vector<int> parent;
    vector<int> sz;
public:
    dsu(int n){
        parent.resize(n);
        sz.assign(n, 1);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int root(int x){
        if (parent[x] == x) return x;
        return parent[x] = root(parent[x]);
    }

    void merge(int x, int y){
        x = root(x);
        y = root(y);
        if (x == y) return;

        if (sz[x] < sz[y]) swap(x, y);
        parent[y] = x;
        sz[x] += sz[y];
    }

    bool same(int x, int y){
        return root(x) == root(y);
    }

    int size(int x){
        return sz[root(x)];
    }
};
template<typename T> class wdsu{
private:
    vector<int> parent, rankv;
    vector<T> weight;
public:
    wdsu(int n){
        parent.resize(n);
        rankv.assign(n, 0);
        weight.assign(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int root(int x){
        if (parent[x] == x) return x;
        int r = root(parent[x]);
        weight[x] += weight[parent[x]];
        return parent[x] = r;
    }

    T potential(int x){
        root(x);
        return weight[x];
    }

    bool merge(int x, int y, T w){
        int rx = root(x), ry = root(y);
        if (rx == ry) return false;
        if (rankv[rx] < rankv[ry]){
            swap(rx, ry);
            swap(x, y);
            w = -w;
        }
        parent[ry] = rx;
        weight[ry] = weight[x]+w-weight[y];
        if (rankv[rx] == rankv[ry]) rankv[rx]++;
        return true;
    }

    T diff(int x, int y){
        return potential(y)-potential(x);
    }

    bool same(int x, int y){
        return root(x) == root(y);
    }
};
template<typename T> class fenwicktree{
private:
    int n;
    vector<T> bit, a;

public:
    fenwicktree(int n) : n(n), bit(n, T()), a(n, T()) {}

    void add(int i, T x){
        while(i < n){
            bit[i] += x;
            i |= i + 1;
        }
    }

    void set(int i, T x){
        add(i, x - a[i]);
        a[i] = x;
    }

    T sum(int i) const{
        T res = T();
        while(i >= 0){
            res += bit[i];
            i = (i&(i+1))-1;
        }
        return res;
    }

    T range_sum(int l, int r) const{
        if(l > r) return T();
        return sum(r)-(l? sum(l-1): T());
    }
};
template<class T> class segtree{
private:
    int n;
    vector<T> seg;
    T e;
    function<T(T, T)> op;

    void build(int node, int l, int r, const vector<T>& A){
        if (r-l == 1){
            seg[node] = A[l];
            return;
        }
        int mid = (l+r)/2;
        build(node*2, l, mid, A);
        build(node*2+1, mid, r, A);
        seg[node] = op(seg[node*2], seg[node*2+1]);
    }

    T query(int node, int l, int r, int ql, int qr) const{
        if (qr <= l || r <= ql) return e;
        if (ql <= l && r <= qr) return seg[node];
        int mid = (l+r)/2;
        return op(query(node*2, l, mid, ql, qr), query(node*2+1, mid, r, ql, qr));
    }

    int find_first(int node, int nl, int nr, int l, T val){
        if (nr <= l) return -1;
        if (seg[node] < val) return -1;
        if (nr-nl == 1) return nl;

        int mid = (nl+nr)/2;
        int res = -1;

        if (l < mid){
            res = find_first(node*2, nl, mid, l, val);
            if (res != -1) return res;
            return find_first(node*2+1, mid, nr, l, val);
        }
        else{
            return find_first(node*2+1, mid, nr, l, val);
        }
    }

    void update(int node, int l, int r, int idx, T val){
        if (r-l == 1){
            seg[node] = val;
            return;
        }
        int mid = (l+r)/2;
        if (idx < mid) update(node*2, l, mid, idx, val);
        else update(node*2+1, mid, r, idx, val);
        seg[node] = op(seg[node*2], seg[node*2+1]);
    }

    T get(int node, int l, int r, int idx) const{
        if (r-l == 1) return seg[node];
        int mid = (l+r)/2;
        if (idx < mid) return get(node*2, l, mid, idx);
        else return get(node*2+1, mid, r, idx);
    }
public:
    segtree(const vector<T>& A, T id, function<T(T, T)> op) : e(id), op(op){
        n = A.size();
        seg.assign(4*n, e);
        build(1, 0, n, A);
    }

    T query(int l, int r) const{
        return query(1, 0, n, l, r);
    }

    void update(int idx, T val){
        update(1, 0, n, idx, val);
    }

    int find_first(int l, T val){
        return find_first(1, 0, n, l, val);
    }

    T get(int idx) const{
        return get(1, 0, n, idx);
    }

    void add(int idx, T val){
        update(idx, get(idx) + val);
    }
};
template<class T> class lazy_segtree {
private:
    int n;
    vector<T> seg, lazy;
    vector<bool> flag;
    T e;
    function<T(T, T)> op;

    void build(int node, int l, int r, const vector<T>& A){
        if (r-l == 1){
            seg[node] = A[l];
            return;
        }
        int mid = (l+r)/2;
        build(node*2, l, mid, A);
        build(node*2+1, mid, r, A);
        seg[node] = op(seg[node*2], seg[node*2+1]);
    }

    void push(int node, int l, int r){
        if (!flag[node]) return;
        int mid = (l+r)/2;
        apply(node*2, l, mid, lazy[node]);
        apply(node*2+1, mid, r, lazy[node]);
        flag[node] = false;
    }

    void apply(int node, int l, int r, T val){
        seg[node] = val*(r-l);
        lazy[node] = val;
        flag[node] = true;
    }

    void update(int node, int l, int r, int ql, int qr, T val){
        if (qr <= l || r <= ql) return;
        if (ql <= l && r <= qr){
            apply(node, l, r, val);
            return;
        }
        push(node, l, r);
        int mid = (l+r)/2;
        update(node*2, l, mid, ql, qr, val);
        update(node*2+1, mid, r, ql, qr, val);
        seg[node] = op(seg[node*2], seg[node*2+1]);
    }

    T query(int node, int l, int r, int ql, int qr){
        if (qr <= l || r <= ql) return e;
        if (ql <= l && r <= qr) return seg[node];
        push(node, l, r);
        int mid = (l+r)/2;
        return op(
            query(node*2, l, mid, ql, qr),
            query(node*2+1, mid, r, ql, qr)
        );
    }

public:
    lazy_segtree(const vector<T>& A, T id, function<T(T,T)> op) : e(id), op(op){
        n = A.size();
        seg.assign(4*n, e);
        lazy.assign(4*n, 0);
        flag.assign(4*n, false);
        build(1, 0, n, A);
    }

    void update(int l, int r, T val){
        update(1, 0, n, l, r, val);
    }

    T query(int l, int r){
        return query(1, 0, n, l, r);
    }
};
class lca{
public:
    int n, log;
    vector<vector<int>> parent;
    vector<vector<int>> graph;
    vector<int> depth;

    lca(int n) : n(n){
        log = 1;
        while ((1 << log) <= n) log++;
        graph.resize(n);
        parent.assign(n, vector<int>(log, -1));
        depth.resize(n);
    }

    void add_edge(int u, int v){
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    void build(int root = 0){
        dfs(root, -1, 0);
        for (int k = 1; k < log; k++){
            for (int v = 0; v < n; v++){
                if (parent[v][k-1] < 0){
                    parent[v][k] = -1;
                }
                else{
                    parent[v][k] = parent[parent[v][k-1]][k-1];
                }
            }
        }
    }

    void dfs(int v, int p, int d){
        parent[v][0] = p;
        depth[v] = d;
        for (int nv : graph[v]){
            if (nv == p) continue;
            dfs(nv, v, d+1);
        }
    }

    int lca_query(int u, int v){
        if (depth[u] < depth[v]) swap(u, v);
        int diff = depth[u]-depth[v];
        for (int k = 0; k < log; k++){
            if (diff & (1 << k)){
                if (u == -1) break;
                u = parent[u][k];
            }
        }
        if (u == v) return u;
        for (int k = log-1; k >= 0; k--){
            if (parent[u][k] != parent[v][k]){
                u = parent[u][k];
                v = parent[v][k];
            }
        }
        return parent[u][0];
    }

    int dist(int u, int v){
        int w = lca_query(u, v);
        return depth[u]+depth[v]-2*depth[w];
    }
};
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
        if (r < 0 || r > n || n > size) return 0;
        return ncr(n+r-1, r);
    }
};
class scc{
public:
    int N;
    vector<vector<int>> graph;
    vector<int> ord, low, comp;
    vector<bool> in_stack;
    stack<int> st;
    int noword = 0, compcount = 0;

    scc(int n) : N(n), graph(n) {}

    void add_edge(int u, int v){
        graph[u].push_back(v);
    }

    void dfs(int v){
        noword++;
        ord[v] = noword;
        low[v] = noword;
        st.push(v);
        in_stack[v] = true;
        for (int to : graph[v]){
            if (ord[to] == -1){
                dfs(to);
                low[v] = min(low[v], low[to]);
            }
            else if (in_stack[to]){
                low[v] = min(low[v], ord[to]);
            }
        }
        if (ord[v] == low[v]){
            while (true){
                int u = st.top();
                st.pop();
                in_stack[u] = false;
                comp[u] = compcount;
                if (u == v) break;
            }
            compcount++;
        }
    }

    int build(){
        ord.assign(N, -1);
        low.resize(N);
        comp.resize(N);
        in_stack.assign(N, false);
        for (int i = 0; i < N; i++){
            if (ord[i] == -1) dfs(i);
        }
        return compcount;
    }
};
class modint{
public:
    static const int mod = 998244353;
    int v;
    
    modint(ll _v = 0){
        v = int((_v%mod+mod)%mod);
    }

    modint& operator += (const modint& o){
        v += o.v;
        if (v >= mod) v -= mod;
        return *this;
    }

    modint operator -= (const modint& o){
        v -= o.v;
        if (v < 0) v += mod;
        return *this;
    }

    modint& operator *= (const modint& o){
        v = (ll)v*o.v%mod;
        return *this;
    }

    friend modint operator + (modint a, const modint& b){
        return a += b;
    }

    friend modint operator - (modint a, const modint& b){
        return a -= b;
    }

    friend modint operator * (modint a, const modint& b){
        return a *= b;
    }

    modint pow(ll n) const {
        modint res = 1, a = *this;
        while (n){
            if (n&1) res *= a;
            a *= a;
            n >>= 1;
        }
        return res;
    }

    modint inv() const{
        return pow(MOD-2);
    }

    friend modint operator / (modint a, const modint& b){
        return a *= b.inv();
    }
};

#ifndef ONLINE_JUDGE
signed testcases = 10;
#else
signed testcases = 1;
#endif
#define int long long

#if 1
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // cin >> testcases;

    while (testcases--){
    }
}
#else
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // cin >> testcases;

    while (testcases--){
    }
}
#endif
