#include <bits/stdc++.h>
#define INF (1ll << 60)
#define INFLL (ll)(4e18)
// #define MOD 998244353
#define MOD 1000000007
#define PI acosl(-1)
#define lb lower_bound
#define ub upper_bound
#define bs binary_search
#define ciN cin
#define npos string::npos
#define nextp next_permutation
#define maxe max_element
#define mine min_element
#define nall(A) A.begin(), A.end()
#define rall(A) A.rbegin(), A.rend()
#define rep(i, n) for(int i = 0; i < (n); i++) 
#define rrep(i, n) for(int i = (n)-1; i >= 0; i--)
#define each(i, a) for(auto& i : a)
#define out(x, y) (!(0 <= x && x < H && 0 <= y && y < W))
#define yes cout<<"Yes"<<endl
#define no cout<<"No"<<endl
#define yesno(a) cout<<(a?"Yes":"No")<<endl
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
template<class T> using pq = priority_queue<T>;
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, -1, 0, 1};
const int dx8[] = { 1, 1, 0, -1, -1, -1, 0, 1 };
const int dy8[] = { 0, -1, -1, -1, 0, 1, 1, 1 };
template<typename T> bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<typename T> bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<typename T> T nC2(T n) { return (n*n-n)/2; }
template<typename T> T nC3(T n) { return n*(n-1)*(n-2)/6; }
template<typename T> T fact(T n) { ll res = 1; for (ll i = 1; i <= n; i++) res *= i; return res; }
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
ll modpow(ll a, ll e, ll mod){
    if (e == 0) return 1;
    ll res = 1;
    while (e){
        if (e&1) res = res*a%mod;
        a = a*a%mod;
        e >>= 1;
    }
    return res;
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
};
template<class T> class lazy_segtree {
private:
    int n;
    vector<T> seg, lazy;
    T e;
    function<T(T, T)> op;

    void build(int node, int l, int r, const vector<T>& A){
        if (r - l == 1) {
            seg[node] = A[l];
            return;
        }
        int mid = (l + r) / 2;
        build(node*2, l, mid, A);
        build(node*2+1, mid, r, A);
        seg[node] = op(seg[node*2], seg[node*2+1]);
    }

    void push(int node){
        if (lazy[node] != 0) {
            seg[node*2] += lazy[node];
            seg[node*2+1] += lazy[node];
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
            lazy[node] = 0;
        }
    }

    void update(int node, int l, int r, int ql, int qr, T val){
        if (qr <= l || r <= ql) return;
        if (ql <= l && r <= qr) {
            seg[node] += val;
            lazy[node] += val;
            return;
        }
        push(node);
        int mid = (l+r)/2;
        update(node * 2, l, mid, ql, qr, val);
        update(node * 2 + 1, mid, r, ql, qr, val);
        seg[node] = op(seg[node*2], seg[node*2+1]);
    }

    T query(int node, int l, int r, int ql, int qr){
        if (qr <= l || r <= ql) return e;
        if (ql <= l && r <= qr) return seg[node];
        push(node);
        int mid = (l+r)/2;
        return op(
            query(node*2, l, mid, ql, qr),
            query(node*2+1, mid, r, ql, qr)
        );
    }

public:
    lazy_segtree(const vector<T>& A, T id, function<T(T, T)> op) : e(id), op(op){
        n = A.size();
        seg.assign(4*n, e);
        lazy.assign(4*n, 0);
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

#ifndef ONLINE_JUDGE
signed limit = 10;
#else
signed limit = 1;
#endif
#define int long long

#if 1
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // cin >> limit;

    while (limit--){
    }
}
#else
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
#endif
