#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#include "ac-library/atcoder/all"
int testcases = 10;
#else
#include <bits/stdc++.h>
#include <atcoder/all>
int testcases = 1;
#endif
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

#define MOD 1000000007ll
// #define MOD 998244353ll
// #define MOD 10007ll
#define INF (long long)4e18
#define EPS 1e-14
#define lb lower_bound
#define ub upper_bound
#define bs binary_search
#define ciN cin
#define npos string::npos
#define nextp next_permutation
#define prevp prev_permutation
#define maxe max_element
#define mine min_element
#define accu accumulate
#define popcount __builtin_popcount
#define clzll __builtin_clzll
#define elif else if 
#define nall(A) A.begin(), A.end()
#define rall(A) A.rbegin(), A.rend()
#define rep(i, n) for(int i = 0; i < (n); i++) 
#define replr(i, l, r) for (int i = l; i < r; i++)
#define rrep(i, n) for(int i = (n)-1; i >= 0; i--)
#define each(i, a) for(auto& i : a)
#define out(x, y) (!(0 <= x && x < H && 0 <= y && y < W))
#define yes cout<<"Yes"<<endl
#define no cout<<"No"<<endl
#define yesno(a) cout<<(a?"Yes":"No")<<endl
#define sanko(a, b, c) (a? b: c)
#define ci cin
#define func function
#define uniqueerase(A) A.erase(unique(A.begin(), A.end()), A.end())
using namespace std;
using cd = complex<long double>;
using ll = long long;
using ull = unsigned long long;
using lll = __int128;
using ld = long double;
template<typename T> using pq = priority_queue<T>;
template<typename T> using pqg = priority_queue<T, vector<T>, greater<T>>;
template<typename T> using vec = vector<T>;
template<typename T> using vv = vector<vector<T>>;
template<typename T> using vvv = vector<vv<T>>;
template<typename T> using vvvv = vector<vvv<T>>;
template<typename T> using vvvvv = vector<vvvv<T>>;
template<typename T> using arr2 = array<T, 2>;
// template<typename T> using uset = unorderd_set<T>;
// template<typename T> using umap = unorderd_map<T>;
template<typename T> using mset = multiset<T>;
static mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll ROOT = (MOD == 998244353ll? 3: 5);
const int dx[] = { 1, 0, -1, 0 };
const int dy[] = { 0, 1, 0, -1 };
const int dx8[] = { 1, 1, 0, -1, -1, -1, 0, 1 };
const int dy8[] = { 0, -1, -1, -1, 0, 1, 1, 1 };
const long double PI = acosl(-1);
const string abcdefghijklmnopqrstuvwxyz = "abcdefghijklmnopqrstuvwxyz";
const string ABCDEFGHIJKLMNOPQRSTUVWXYZ = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const string num0123456789 = "0123456789";
// const string atcoder = "atcoder";
// const string ATCODER = "ATCODER";
const string chokudai = "chokudai";
const string CHOKUDAI = "CHOKUDAI";
const ll tens[19] = {
    1ll,
    10ll,
    100ll,
    1000ll,
    10000ll,
    100000ll,
    1000000ll,
    10000000ll,
    100000000ll,
    1000000000ll,
    10000000000ll,
    100000000000ll,
    1000000000000ll,
    10000000000000ll,
    100000000000000ll,
    1000000000000000ll,
    10000000000000000ll,
    100000000000000000ll,
    1000000000000000000ll,
};

template<typename T> void chmin(T& x, T y){
    x = min(x, y);
}

template<typename T> void chmax(T& x, T y){
    x = max(x, y);
}

template<typename T> istream& operator >> (istream& is, deque<T>& v) {
	for (T& x : v) is >> x;
	return is;
}

template<typename T> ostream& operator << (ostream& os, const deque<T>& v){
	for (int i = 0; i < v.size(); i++){
		if (i < v.size()-1) os << v[i] << ' ';
		else os << v[i] << '\n';
	}
	return os;
}

template<typename T> istream& operator >> (istream& is, vector<T>& v) {
	for (T& x : v) is >> x;
	return is;
}

template<typename T> ostream& operator << (ostream& os, const vector<T>& v){
	for (int i = 0; i < v.size(); i++){
		if (i < v.size()-1) os << v[i] << ' ';
		else os << v[i] << '\n';
	}
	return os;
}

template<typename T, typename U> istream& operator >> (istream& is, pair<T, U>& p){
    is >> p.first >> p.second;
    return is;
}

template<typename T, typename U> istream& operator >> (istream& is, vector<pair<T, U>>& p){
    for (auto& i : p) cin >> i.first >> i.second;
    return is;
}

template<typename T, typename U> istream& operator >> (istream& is, deque<pair<T, U>>& p){
    for (auto& i : p) cin >> i.first >> i.second;
    return is;
}

vector<pair<char, int>> to_rle(const string& S){
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

ld radtodeg(ld x){
    return x*180.0/PI;
}

ld degtorad(ld x){
    return x*PI/180.0;
}

string to_base2(long long N){
    string res;
    while (N > 0){
        if (N%2 > 0) res += '1';
        else res += '0';
        N /= 2;
    }
    reverse(res.begin(), res.end());
    return res;
}

vector<int> zaatu(const string& A){
	int N = (int)A.size();
	string B = A;
	sort(B.begin(), B.end());
	B.erase(unique(B.begin(), B.end()), B.end());
	vector<int> res(N);
	for (int i = 0; i < N; i++){
		res[i] = lower_bound(B.begin(), B.end(), A[i])-B.begin();
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


class mos{
private:
    struct query{
        int l, r, idx;
    };
    int n, block;
    vector<query> qs;
public:

    mos(int n) : n(n){
        block = sqrt(n);
    }

    void add_query(int l, int r){
        qs.push_back({l, r, (int)qs.size()});
    }

    template<class ADD, class REMOVE, class OUTPUT>
    void run(ADD add, REMOVE remove, OUTPUT output){
        sort(qs.begin(), qs.end(), [&](query a, query b){
            int ablock = a.l/block, bblock = b.l/block;
            if (ablock != bblock) return ablock < bblock;
            if (ablock&1) return a.r > b.r;
            return a.r < b.r;
        });
        int l = 0, r = 0;
        for (auto& q : qs){
            while (l > q.l) add(--l);
            while (r < q.r) add(r++);
            while (l < q.l) remove(l++);
            while (r > q.r) remove(--r);
            output(q.idx);
        }
    }
};

template<typename T, typename V = long long> class intervalset{
private:
public:
    struct node{
        T l, r;
        V val;
        node(T l, T r, V val) : l(l), r(r), val(val) {}
        bool operator < (const node& other) const{
            if (l != other.l) return l < other.l;
            return r < other.r;
        }
        friend ostream& operator<< (ostream &s, node e){
            return s << "([" << e.l << ", " << e.r << "): " << e.val << ")";
        }
    };
    const V id;
    set<node> S;
    intervalset(V id = V()) : id(id) {}
    intervalset(const vector<V>& v, V id = V()) : id(id){
        vector<node> vec;
        for (int l = 0; l < (int)v.size(); l++){
            int r = l;
            while (r < (int)v.size() && v[r] == v[l]) r++;
            vec.emplace_back(l, r, v[l]);
            l = r;
        }
        S = set<node>(vec.begin(), vec.end());
    }

    typename set<node>::iterator begin(){ return S.begin(); }
    typename set<node>::iterator end(){ return S.end(); }
    typename set<node>::iterator get(T p){
        auto it = S.upper_bound(node(p, numeric_limits<T>::max(), 0));
        if (it == S.begin()) return S.end();
        it = prev(it);
        if (it->l <= p && p < it->r) return it;
        return S.end();
    }
    typename set<node>::iterator lower_bound(T p){
        auto it = get(p);
        if (it != S.end()) return it;
        return S.upper_bound(node(p, numeric_limits<T>::max(), 0));
    }

    bool covered(T p){
        return get(p) != S.end();
    }

    bool same(T p, T q){
        if (!covered(p) || !covered(q)) return false;
        return get(p) == get(q);
    }

    V get_val(T p){
        auto it = get(p);
        if (it != S.end()) return it->val;
        return id;
    }

    V operator[] (T p){
        return get_val(p);
    }

    T get_mex(T p = 0){
        auto it = S.upper_bound(node(p, numeric_limits<T>::max(), 0));
        if (it == S.begin()) return p;
        it = prev(it);
        if (it->l <= p && p < it->r) return it->r;
        return p;
    }

    template<typename ADDFUNC, typename DELFUNC> void update(T l, T r, V val, const ADDFUNC& add, const DELFUNC& del){
        auto it = S.lower_bound(node(l, numeric_limits<T>::max(), val));
        while (it != S.end() && it->l <= r){
            if (it->l == r){
                if (it->val == val){
                    r = it->r;
                    del(it->l, it->r, it->val);
                    it = S.erase(it);
                }
                break;
            }
            if (it->r <= r){
                del(it->l, it->r, it->val);
                it = S.erase(it);
            }
            else{
                if (it->val == val){
                    r = it->r;
                    del(it->l, it->r, it->val);
                    it = S.erase(it);
                }
                else{
                    node n = *it;
                    del(it->l, it->r, it->val);
                    it = S.erase(it);
                    it = S.emplace_hint(it, r, n.r, n.val);
                    add(it->l, it->r, it->val);
                }
            }
        }
        if (it != S.begin()){
            it = prev(it);
            if (it->r == l){
                if (it->val == val){
                    l = it->l;
                    del(it->l, it->r, it->val);
                    it = S.erase(it);
                }
            }
            else if (l < it->r){
                if (it->val == val){
                    l = min(l, it->l);
                    r = max(r, it->r);
                    del(it->l, it->r, it->val);
                    it = S.erase(it);
                }
                else{
                    if (r < it->r){
                        it = S.emplace_hint(next(it), r, it->r, it->val);
                        add(it->l, it->r, it->val);
                        it = prev(it);
                    }
                    node n = *it;
                    del(it->l, it->r, it->val);
                    it = S.erase(it);
                    it = S.emplace_hint(it, n.l, l, n.val);
                    add(it->l, it->r, it->val);
                }
            }
        }
        if (it != S.end()) it = next(it);
        it = S.emplace_hint(it, l, r, val);
        add(it->l, it->r, it->val);
    }

    void update(T l, T r, V val){
        update(l, r, val, [](T, T, V){}, [](T, T, V){});
    }

    template<typename ADDFUNC, typename DELFUNC> void insert(T l, T r, const ADDFUNC &add, const DELFUNC &del){
        update(l, r, V(), add, del);
    }

    void insert(const T &l, const T &r) {
        update(l, r, V(), [](T, T, V){}, [](T, T, V){});
    }

    template<class ADDFUNC, class DELFUNC> void erase(T l, T r, const ADDFUNC &add, const DELFUNC &del){
        auto it = S.lower_bound(node(l, 0, V()));
        while (it != S.end() && it->l <= r){
            if (it->l == r) break;
            if (it->r <= r){
                del(it->l, it->r, it->val);
                it = S.erase(it);
            }
            else{
                node n = *it;
                del(it->l, it->r, it->val);
                it = S.erase(it);
                it = S.emplace_hint(it, r, n.r, n.val);
                add(it->l, it->r, it->val);
            }
        }
        if (it != S.begin()){
            it = prev(it);
            if (l < it->r){
                if (r < it->r){
                    it = S.emplace_hint(next(it), r, it->r, it->val);
                    add(it->l, it->r, it->val);
                    it = prev(it);
                }
                node n = *it;
                del(it->l, it->r, it->val);
                it = S.erase(it);
                it = S.emplace_hint(it, n.l, l, n.val);
                add(it->l, it->r, it->val);
            }
        }
    }

    void erase(const T &l, const T &r){
        erase(l, r, [](T, T, V){}, [](T, T, V){});
    }

    friend ostream& operator<< (ostream &s, const intervalset &ins){
        for (auto e : ins.S){
            s << "([" << e.l << ", " << e.r << "): " << e.val << ") ";
        }
        return s;
    }
};

namespace graph{
    template<typename S, typename T> vector<T> dijkstra(const vector<vector<pair<S, T>>>& G, int root){
        vector<T> dist(G.size(), numeric_limits<T>::max());
        pqg<pair<T, int>> Q;
        dist[root] = 0;
        Q.push({0, root});
        while (!Q.empty()){
            auto [d, p] = Q.top();
            Q.pop();
            if (dist[p] < d) continue;
            for (auto [u, v] : G[p]){
                if (dist[u] > d+v){
                    dist[u] = d+v;
                    Q.push({dist[u], u});
                }
            }
        }
        for (auto &x : dist) if (x == numeric_limits<T>::max()) x = -1;
        return dist;
    }

    template<typename T> vector<int> tpsort(const vector<vector<T>>& G){
        int N = G.size();
        vector<int> indeg(N, 0), res;
        queue<int> Q;
        for (int i = 0; i < N; i++) for (int j : G[i]) indeg[j]++;
        for (int i = 0; i < N; i++) if (indeg[i] == 0) Q.push(i);
        while (!Q.empty()){
            int n = Q.front();
            res.push_back(n);
            Q.pop();
            for (int j : G[n]) if (--indeg[j] == 0) Q.push(j);
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
            return;
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
            if (rx == ry) return diff(x, y) == w;
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
            queue<int> q;
            q.push(root);
            parent[root][0] = -1;
            depth[root] = 0;
            while (!q.empty()){
                int v = q.front();
                q.pop();
                for (int nv : graph[v]){
                    if (nv == parent[v][0]) continue;
                    parent[nv][0] = v;
                    depth[nv] = depth[v]+1;
                    q.push(nv);
                }
            }
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

    class twosat{
    private:
    public:
        int N;
        vector<vector<int>> G, rG;
        vector<int> comp, order, used;
        vector<bool> answer;

        twosat(int n) : N(n){
            G.resize(2*n);
        }

        int var(int i, bool f){
            return 2*i+(f? 1: 0);
        }

        void add_implication(int u, int v){
            G[u].push_back(v);
        }

        void add_or(int i, bool f, int j, bool g){
            add_implication(var(i, !f), var(j, g));
            add_implication(var(j, !g), var(i, f));
        }

        void add_if(int i, bool f, int j, bool g){
            add_implication(var(i, f), var(j, g));
        }

        void set_true(int i, bool f){
            add_implication(var(i, !f), var(i, f));
        }

        void dfs1(int n){
            used[n] = 1;
            for (auto i : G[n]) if (!used[i]) dfs1(i);
            order.push_back(n);
        }

        void dfs2(int n, int c){
            comp[n] = c;
            for (int i : rG[n]) if (comp[i] == -1) dfs2(i, c);
        }

        bool satisfiable(){
            int n = 2*N;
            used.assign(n, 0);
            order.clear();
            for (int i = 0; i < n; i++) if (!used[i]) dfs1(i);
            rG.assign(n, {});
            for (int i = 0; i < n; i++) for (int j : G[i]) rG[j].push_back(i);
            comp.assign(n, -1);
            int k = 0;
            for (int i = n-1; i >= 0; i--) if (comp[order[i]] == -1) dfs2(order[i], k++);
            answer.assign(N, false);
            for (int i = 0; i < N; i++){
                if (comp[2*i] == comp[2*i+1]) return false;
                answer[i] = (comp[2*i] < comp[2*i+1]);
            }
            return true;
        }

        vector<bool> get_answer(){
            return answer;
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
            noword = 0, compcount = 0;
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

    template<typename T> class rerooting{
    private:
        int V;
        vector<vector<int>> G;
        vector<vector<T>> dp;
        function<T(T, int)> f, g;
        function<T(T, T)> merge;
        T id;
    public:
        rerooting(){}
        rerooting(int V, function<T(T, int)> f, function<T(T, T)> merge, T id, function<T(T, int)> g) : V(V), f(f), merge(merge), id(id), g(g){
            G.resize(V);
            dp.resize(V);
        }

        void add_edge(int u, int v){
            G[u].push_back(v);
            G[v].push_back(u);
        }

        T dfs1(int n, int p){
            T res = id;
            for (int i = 0; i < G[n].size(); i++){
                if (G[n][i] == p) continue;
                dp[n][i] = dfs1(G[n][i], n);
                res = merge(res, f(dp[n][i], G[n][i]));
            }
            return g(res, n);
        }

        void dfs2(int n, int p, T from_par){
            for (int i = 0; i < G[n].size(); i++){
                if (G[n][i] == p){
                    dp[n][i] = from_par;
                    break;
                }
            }
            vector<T> pr(G[n].size()+1);
            pr[G[n].size()] = id;
            for (int i = G[n].size(); i > 0; i--){
                pr[i-1] = merge(pr[i], f(dp[n][i-1], G[n][i-1]));
            }
            T pl = id;
            for (int i = 0; i < G[n].size(); i++){
                if (G[n][i] != p){
                    T val = merge(pl, pr[i+1]);
                    dfs2(G[n][i], n, g(val, n));
                }
                pl = merge(pl, f(dp[n][i], G[n][i]));
            }
        }

        void build(int root = 0){
            for (int i = 0; i < V; i++) dp[i].resize(G[i].size());
            dfs1(root, -1);
            dfs2(root, -1, id);
        }

        T solve(int n){
            T ans = id;
            for (int i = 0; i < G[n].size(); i++){
                ans = merge(ans, f(dp[n][i], G[n][i]));
            }
            return g(ans, n);
        }
    };
	
    template<typename T = long long> class maxflow{
        struct edge{
            int to;
            T cap;
            int rev;
        };

        int N;
        vector<int> level, it;

    public:
        vector<vector<edge>> G;

        maxflow(int n) : N(n), G(n), level(n), it(n) {}

        void add_edge(int u, int v, T cap){
            edge a = {v, cap, (int)G[v].size()};
            edge b = {u, 0, (int)G[u].size()};
            G[u].push_back(a);
            G[v].push_back(b);
        }

        bool bfs(int s, int t){
            fill(level.begin(), level.end(), -1);
            queue<int> q;
            level[s] = 0;
            q.push(s);

            while(!q.empty()){
                int v = q.front(); q.pop();
                for(auto &e : G[v]){
                    if(e.cap > 0 && level[e.to] < 0){
                        level[e.to] = level[v] + 1;
                        q.push(e.to);
                    }
                }
            }
            return level[t] >= 0;
        }

        T dfs(int v, int t, T f){
            if(v == t) return f;
            for(int &i = it[v]; i < (int)G[v].size(); i++){
                edge &e = G[v][i];
                if(e.cap > 0 && level[v] < level[e.to]){
                    T d = dfs(e.to, t, min(f, e.cap));
                    if(d > 0){
                        e.cap -= d;
                        G[e.to][e.rev].cap += d;
                        return d;
                    }
                }
            }
            return 0;
        }

        T max_flow(int s, int t){
            T flow = 0;
            T inf = numeric_limits<T>::max();

            while(bfs(s, t)){
                fill(it.begin(), it.end(), 0);
                T f;
                while((f = dfs(s, t, inf)) > 0){
                    flow += f;
                }
            }
            return flow;
        }
    };

    template<typename T, typename C> class mincostflow{
    private:
        struct edge{
            int to, rev;
            T cap;
            C cost;
        };

    public:
        int N;
        vector<vector<edge>> G;
        vector<C> dist, h;
        vector<int> prevv, preve;

        mincostflow(int n) : N(n), G(n), dist(n), prevv(n), preve(n), h(N, 0) {}

        void add_edge(int u, int v, T cap, C cost){
            G[u].push_back({v, (int)G[v].size(), cap, cost});
            G[v].push_back({u, (int)G[u].size()-1, 0, -cost});
        }

        pair<T, C> min_cost_flow(int s, int t, T maxf){
            const C inf = numeric_limits<C>::max()/4;
            T flow = 0;
            C cost = 0;
            while (maxf > 0){
                priority_queue<pair<C,int>, vector<pair<C,int>>, greater<>> pq;
                fill(dist.begin(), dist.end(), inf);
                dist[s] = 0;
                pq.push({0, s});
                while (!pq.empty()){
                    auto [d, v] = pq.top();
                    pq.pop();
                    if (dist[v] < d) continue;
                    for (int i = 0; i < G[v].size(); i++){
                        auto &e = G[v][i];
                        if (e.cap > 0){
                            C nd = d+e.cost+h[v]-h[e.to];
                            if (dist[e.to] > nd){
                                dist[e.to] = nd;
                                prevv[e.to] = v;
                                preve[e.to] = i;
                                pq.push({nd, e.to});
                            }
                        }
                    }
                }
                if (dist[t] == inf) break;
                for (int i = 0; i < N; i++) h[i] += dist[i];
                T d = maxf;
                for (int i = t; i != s; i = prevv[i]) d = min(d, G[prevv[i]][preve[i]].cap);
                maxf -= d;
                flow += d;
                cost += d*h[t];

                for (int i = t; i != s; i = prevv[i]){
                    auto &e = G[prevv[i]][preve[i]];
                    e.cap -= d;
                    G[i][e.rev].cap += d;
                }
            }
            return {flow, cost};
        }
    };

    class hld{
    private:
    public:
        int N, cur;
        vector<vector<int>> G;
        vector<int> parent, depth, heavy, head, pos, sz;

        hld(int n) : N(n), G(n), parent(n), depth(n), heavy(n, -1), head(n), pos(n), sz(n) {}

        void add_edge(int u, int v){
            G[u].push_back(v);
            G[v].push_back(u);
        }

        int dfs(int n, int p){
            parent[n] = p;
            sz[n] = 1;
            int maxsz = 0;
            for (int i : G[n]) if (i != p){
                depth[i] = depth[n]+1;
                int sub = dfs(i, n);
                sz[n] += sub;
                if (sub > maxsz){
                    maxsz = sub;
                    heavy[n] = i;
                }
            }
            return sz[n];
        }

        void decompose(int n, int h){
            head[n] = h, pos[n] = cur++;
            if (heavy[n] != -1) decompose(heavy[n], h);
            for (int to : G[n]) if (to != parent[n] && to != heavy[n]) decompose(to, to);
        }

        void build(int root = 0){
            cur = 0;
            depth[root] = 0;
            dfs(root, -1);
            decompose(root, root);
        }

        template<class F> void query(int u, int v, const F& f){
            while (head[u] != head[v]){
                if (depth[head[u]] < depth[head[v]]) swap(u, v);
                f(pos[head[u]], pos[u]);
                u = parent[head[u]];
            }
            if (depth[u] > depth[v]) swap(u, v);
            f(pos[u], pos[v]);
        }

        int lca(int u, int v){
            while (head[u] != head[v]){
                if (depth[head[u]] < depth[head[v]]) swap(u, v);
                u = parent[head[u]];
            }
            return depth[u] < depth[v]? u: v;
        }
    };
}

namespace tree{
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

        T get(int i) const{
            return a[i];
        }

		T _sum(int i) const{
			T res = T();
			while(i >= 0){
				res += bit[i];
				i = (i&(i+1))-1;
			}
			return res;
		}

		T sum(int l, int r) const{
            r--;
			if (l > r) return T();
			return _sum(r)-(l? _sum(l-1): T());
		}

        int lower_bound(T x){
            int i = -1, k = 1;
            while(k<<1 <= n) k <<= 1;
            for(; k > 0; k >>= 1){
                if(i+k < n && bit[i+k] < x){
                    x -= bit[i+k];
                    i += k;
                }
            }
            return i + 1;
        }
	};

    template<typename T> class lazy_fenwicktree{
    private:
        int n;
        vector<T> bit1, bit2;

        void add(vector<T>& bit, int i, T x){
            while (i < n){
                bit[i] += x;
                i |= i+1;
            }
        }

        T sum(const vector<T>& bit, int i) const{
            T res = T();
            while(i >= 0){
                res += bit[i];
                i = (i&(i+1))-1;
            }
            return res;
        }
    public:
        lazy_fenwicktree(int n) : n(n), bit1(n, T()), bit2(n, T()) {}

        void apply(int l, int r, T x){
            add(bit1, l, x);
            if (r < n) add(bit1, r, -x);
            add(bit2, l, x*l);
            if (r < n) add(bit2, r, -x*r);
        }

        T prefix_sum(int r) const{
            if (r <= 0) return T();
            return sum(bit1, r-1)*r-sum(bit2, r-1);
        }

        T sum(int l, int r) const{
            return prefix_sum(r)-prefix_sum(l);
        }

        T get(int i) const{
            return sum(i, i+1);
        }
    };

    template<class T> class segtree{
    private:
        int n, size;
        vector<T> seg;
        T e;
        function<T(T, T)> op;
    public:
        segtree(const vector<T>& A, T id, function<T(T, T)> op) : e(id), op(op){
            n = A.size();
            size = 1;
            while (size < n) size <<= 1;
            seg.assign(2*size, e);
            for (int i = 0; i < n; i++) seg[size+i] = A[i];
            for (int i = size-1; i > 0; i--) seg[i] = op(seg[i<<1], seg[i<<1|1]);
        }
        segtree(int sz, T id, function<T(T, T)> op) : e(id), op(op){
            n = sz;
            size = 1;
            while (size < n) size <<= 1;
            seg.assign(2*size, e);
            for (int i = 0; i < n; i++) seg[size+i] = e;
            for (int i = size-1; i > 0; i--) seg[i] = op(seg[i<<1], seg[i<<1|1]);
        }

        void set(int i, T val){
            i += size;
            seg[i] = val;
            while (i >>= 1) seg[i] = op(seg[i<<1], seg[i<<1|1]);
        }

        T prod(int l, int r){
            T L = e, R = e;
            for (l += size, r += size; l < r; l >>= 1, r >>= 1){
                if (l&1) L = op(L, seg[l++]);
                if (r&1) R = op(seg[--r], R);
            }
            return op(L, R);
        }

        T get(int i){
            return seg[size+i];
        }

        void add(int i, T val){
            set(i, get(i)+val);
        }

        template<typename F> int max_right(int l, F f){
            if (l == n) return n;
            l += size;
            T sm = e;
            do{
                while ((l & 1) == 0) l >>= 1;
                if (!f(op(sm, seg[l]))){
                    while (l < size){
                        l <<= 1;
                        if (f(op(sm, seg[l]))){
                            sm = op(sm, seg[l]);
                            l++;
                        }
                    }
                    return l-size;
                }
                sm = op(sm, seg[l]);
                l++;
            }while((l&-l) != l);
            return n;
        }

        template<typename F> int min_left(int r, F f){
            if (r == 0) return 0;
            r += size;
            T sm = e;
            do{
                r--;
                while (r > 1 && (r&1)) r >>= 1;
                if (!f(op(seg[r], sm))){
                    while (r < size){
                        r = r<<1|1;
                        if (f(op(seg[r], sm))){
                            sm = op(seg[r], sm);
                            r--;
                        }
                    }
                    return r+1-size;
                }
                sm = op(seg[r], sm);
            }while((r&-r) != r);
            return 0;
        }
    };

    template<typename T> class dynamic_segtree{
    private:
        struct Node{
            T val;
            Node *l, *r;
            Node(T v) : val(v), l(nullptr), r(nullptr) {}
        };

        Node* root;
        ll L, R;
        function<T(T, T)> op;
        function<T()> e;
    public:
        dynamic_segtree(ll L, ll R, function<T(T,T)> op, function<T()> e) : L(L), R(R), op(op), e(e), root(nullptr) {}

        void set(ll pos, T x){
            if (pos < L || pos >= R) return;
            if (!root) root = new Node(e());
            Node* node = root;
            ll l = L, r = R;
            vector<Node*> path;
            while (true){
                path.push_back(node);
                if (r-l == 1) break;
                ll mid = (l+r)/2;
                if (pos < mid){
                    if (!node->l) node->l = new Node(e());
                    node = node->l;
                    r = mid;
                }
                else{
                    if (!node->r) node->r = new Node(e());
                    node = node->r;
                    l = mid;
                }
            }
            node->val = x;
            for (int i = (int)path.size()-2; i >= 0; i--){
                Node* cur = path[i];
                T lv = cur->l? cur->l->val: e();
                T rv = cur->r? cur->r->val: e();
                cur->val = op(lv, rv);
            }
        }

        T get(ll pos) const{
            if (pos < L || pos >= R) return e();
            if (!root) return e();
            Node* node = root;
            ll l = L, r = R;
            while (node){
                if (r-l == 1) return node->val;
                ll mid = (l+r)/2;
                if (pos < mid) node = node->l, r = mid;
                else node = node->r, l = mid;
            }
            return e();
        }

        T prod(ll ql, ll qr) const{
            if (qr <= L || R <= ql) return e();
            T res = e();
            stack<tuple<Node*, ll, ll>> st;
            st.emplace(root, L, R);
            while (!st.empty()) {
                auto [node, l, r] = st.top();
                st.pop();
                if (!node || r <= ql || qr <= l) continue;
                if (ql <= l && r <= qr){
                    res = op(res, node->val);
                    continue;
                }
                ll mid = (l+r)/2;
                st.emplace(node->l, l, mid);
                st.emplace(node->r, mid, r);
            }
            return res;
        }
    };

    template<typename S, typename F> class lazy_segtree{
    private:
        int _n, size, log;
        vector<S> d;
        vector<F> lz;
        function<S(S, S)> op;
        function<S()> e;
        function<S(F, S)> mapping;
        function<F(F, F)> composition;
        function<F()> id;

        void update(int k){
            d[k] = op(d[2*k], d[2*k+1]);
        }

        void all_apply(int k, F f){
            d[k] = mapping(f, d[k]);
            if(k < size) lz[k] = composition(f, lz[k]);
        }

        void push(int k){
            all_apply(2*k, lz[k]);
            all_apply(2*k+1, lz[k]);
            lz[k] = id();
        }
    public:
        lazy_segtree(int n, function<S(S,S)> op, function<S()> e, function<S(F,S)> mapping, function<F(F,F)> composition, function<F()> id) : _n(n), op(op), e(e), mapping(mapping), composition(composition), id(id){
            size = 1;
            log = 0;
            while(size < n) size <<= 1, log++;
            d.assign(2*size, e());
            lz.assign(size, id());
        }

        S get(int p){
            p += size;
            for(int i = log; i >= 1; i--) push(p>>i);
            return d[p];
        }

        void set(int p, S x){
            p += size;
            for(int i = log; i >= 1; i--) push(p>>i);
            d[p] = x;
            for(int i = 1; i <= log; i++) update(p>>i);
        }

        void build(){
            for(int i = size-1;i >= 1; i--) update(i);
        }

        S prod(int l, int r){
            l += size, r += size;
            for(int i = log; i >= 1; i--){
                if(((l>>i)<<i)!=l) push(l>>i);
                if(((r>>i)<<i)!=r) push((r-1)>>i);
            }
            S sml = e(), smr = e();
            while(l < r){
                if(l&1) sml = op(sml, d[l++]);
                if(r&1) smr = op(d[--r], smr);
                l >>= 1, r >>= 1;
            }
            return op(sml, smr);
        }

        void apply(int l, int r, F f){
            l += size, r += size;
            int l2 = l, r2 = r;
            for(int i = log; i >= 1; i--){
                if(((l>>i)<<i)!=l) push(l>>i);
                if(((r>>i)<<i)!=r) push((r-1)>>i);
            }
            while(l < r){
                if(l&1) all_apply(l++, f);
                if(r&1) all_apply(--r, f);
                l >>= 1;
                r >>= 1;
            }
            l = l2, r = r2;
            for(int i = 1; i <= log; i++){
                if(((l>>i)<<i)!=l) update(l>>i);
                if(((r>>i)<<i)!=r) update((r-1)>>i);
            }
        }

        template<class G> int max_right(int l, G g){
            if(l == _n) return _n;
            l += size;
            for(int i = log; i >= 1; i--) push(l>>i);
            S sm = e();
            do{
                while((l&1) == 0) l >>= 1;
                if(!g(op(sm, d[l]))){
                    while(l < size){
                        push(l);
                        l <<= 1;
                        if(g(op(sm, d[l]))){
                            sm = op(sm, d[l]);
                            l++;
                        }
                    }
                    return l - size;
                }
                sm = op(sm, d[l]);
                l++;
            }while((l&-l) != l);
            return _n;
        }

        template<class G> int min_left(int r, G g){
            if(r == 0) return 0;
            r += size;
            for(int i = log; i >= 1; i--) push((r-1)>>i);
            S sm = e();
            do{
                r--;
                while(r > 1 && (r&1)) r >>= 1;
                if(!g(op(d[r], sm))){
                    while(r < size){
                        push(r);
                        r = 2*r + 1;
                        if(g(op(d[r], sm))){
                            sm = op(d[r], sm);
                            r--;
                        }
                    }
                    return r+1-size;
                }
                sm = op(d[r], sm);
            }while((r&-r) != r);
            return 0;
        }
    };

    template<typename T, typename E> class godtree{
    private:
        struct Node{
            T val, sum;
            E lazy;
            bool rev;
            int sz, pri;
            Node *l, *r;

            Node(T v, E id) : val(v), sum(v), lazy(id), rev(false), sz(1), pri(rng()), l(nullptr), r(nullptr) {}
        };

        using F = function<T(T, T)>;
        using G = function<T(T, E, int)>;
        using H = function<E(E, E)>;
        using I = function<T()>;
        using J = function<E()>;

        F op;
        G mapping;
        H composition;
        I e;
        J id;
        Node* root = nullptr;
    public:
        godtree(F op, I e, G mapping, H composition, J id) : op(op), mapping(mapping), composition(composition), e(e), id(id) {}

        int sz(Node* t){ return t? t->sz: 0; }
        T sum(Node* t){ return t? t->sum: e(); }
        Node* new_node(T v){ return new Node(v, id()); }
        int size(){ return sz(root); }

        T get(Node* t, int k){
            push(t);
            if (k < sz(t->l)) return get(t->l, k);
            if (k == sz(t->l)) return t->val;
            return get(t->r, k - sz(t->l) - 1);
        }

        T get(int pos){
            return get(root, pos);
        }

        Node* update(Node* t){
            if (!t) return t;
            t->sz = 1 + sz(t->l)+sz(t->r);
            t->sum = op(op(sum(t->l), t->val), sum(t->r));
            return t;
        }

        void apply(Node* t, E f){
            if (!t) return;
            t->val = mapping(t->val, f, 1);
            t->sum = mapping(t->sum, f, t->sz);
            t->lazy = composition(t->lazy, f);
        }

        void push(Node* t){
            if (!t) return;
            if (t->rev){
                swap(t->l, t->r);
                if (t->l) t->l->rev ^= 1;
                if (t->r) t->r->rev ^= 1;
                t->rev = false;
            }
            if (t->lazy != id()){
                apply(t->l, t->lazy);
                apply(t->r, t->lazy);
                t->lazy = id();
            }
        }

        pair<Node*, Node*> split(Node* t, int k){
            if (!t) return {nullptr, nullptr};
            push(t);
            if (k <= sz(t->l)){
                auto [l, r] = split(t->l, k);
                t->l = r;
                return {l, update(t)};
            }
            else{
                auto [l, r] = split(t->r, k - sz(t->l)-1);
                t->r = l;
                return {update(t), r};
            }
        }

        Node* merge(Node* l, Node* r){
            if (!l || !r) return l? l: r;
            if (l->pri > r->pri){
                push(l);
                l->r = merge(l->r, r);
                return update(l);
            }
            else{
                push(r);
                r->l = merge(l, r->l);
                return update(r);
            }
        }

        void insert(int pos, T v){
            auto [a, b] = split(root, pos);
            root = merge(merge(a, new_node(v)), b);
        }

        void erase(int pos){
            auto [a, b] = split(root, pos);
            auto [c, d] = split(b, 1);
            root = merge(a, d);
        }

        void reverse(int l, int r){
            auto [a, b] = split(root, l);
            auto [c, d] = split(b, r-l);
            if (c) c->rev ^= 1;
            root = merge(a, merge(c, d));
        }

        void apply(int l, int r, E f){
            auto [a, b] = split(root, l);
            auto [c, d] = split(b, r-l);
            apply(c, f);
            root = merge(a, merge(c, d));
        }

        T query(int l, int r){
            auto [a, b] = split(root, l);
            auto [c, d] = split(b, r-l);
            T res = sum(c);
            root = merge(a, merge(c, d));
            return res;
        }
    };

    class trietree{
    public:
        static const int SIGMA = 256;
        vector<array<int, SIGMA>> nxt;
        vector<bool> is_end;
        vector<int> cnt;

        trietree(){
            nxt.emplace_back();
            nxt[0].fill(-1);
            is_end.push_back(false);
            cnt.push_back(0);
        }

        void insert(const string& s){
            int v = 0;
            for (unsigned char c : s){
                if (nxt[v][c] == -1){
                    nxt[v][c] = nxt.size();
                    nxt.emplace_back();
                    nxt.back().fill(-1);
                    is_end.push_back(false);
                    cnt.push_back(0);
                }
                v = nxt[v][c];
                cnt[v]++;
            }
            is_end[v] = true;
        }

        bool search(const string& s) const{
            int v = 0;
            for (unsigned char c : s){
                if (nxt[v][c] == -1) return false;
                v = nxt[v][c];
            }
            return is_end[v];
        }

        bool starts_with(const string& s) const{
            int v = 0;
            for (unsigned char c : s){
                if (nxt[v][c] == -1) return false;
                v = nxt[v][c];
            }
            return true;
        }

        int max_lcp(const string& s) const{
            int v = 0;
            int depth = 0;
            int ans = 0;
            for (unsigned char c : s){
                v = nxt[v][c];
                depth++;
                if (cnt[v] >= 2) ans = depth;
            }
            return ans;
        }
    };
}

namespace num{
    ll modmul(ll a, ll b, ll mod){
        return (__int128_t)a*b%mod;
    }

	ll modpow(ll a, ll e, ll mod = MOD){
		if (e == 0) return 1;
		ll res = 1;
		while (e){
			if (e&1) res = modmul(res, a, mod);
			a = modmul(a, a, mod);
			e >>= 1;
		}
		return res;
	}

    bool isprime(ll n){
        if (n < 2) return false;
        vector<ull> small = {2ull, 3ull, 5ull, 7ull, 11ull, 13ull, 17ull, 19ull, 23ull, 29ull};
        vector<ull> large = {2ull, 325ull, 9375ull, 28178ull, 450775ull, 9780504ull, 1795265022ull};
        for (ull i : small) if (n%i == 0) return n == i;
        ull d = n-1;
        int s = 0;
        while ((d&1) == 0) d >>= 1, s++;
        for (ull i : large){
            if (i%n == 0) continue;
    ull x = modpow(i, d, n);
            if (x == 1 || x == n-1) continue;
            bool comp = true;
            for (int j = 1; j < s; j++){
                x = (__uint128_t)x*x%n;
                if (x == n-1){
                    comp = false;
                    break;
                }
            }
            if (comp) return false;
        }
        return true;
    }

    ll extgcd(ll a, ll b, ll& x, ll& y){
        if (b == 0){
            x = 1, y = 0;
            return a;
        }
        ll d = extgcd(b, a%b, y, x);
        y -= a/b*x;
        return d;
    }

    template<typename T> ll tentousuu(vector<T>& A){
        auto Z = zaatu(A);
        int N = A.size();
        ll res = 0;
        tree::fenwicktree<int> F(N+1);
        for (int i = N-1; i >= 0; i--){
            res += F.sum(Z[i]-1);
            F.add(Z[i], 1);
        }
        return res;
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

	template<ll mod> class modint{
	public:
		ll value;

        static constexpr ll get_mod(){
            return mod;
        }

		modint(ll v = 0){
			value = v%mod;
			if (value < 0) value += mod;
		}

		modint operator + (const modint& other) const{
			ll res = value+other.value;
			if (res >= mod) res -= mod;
			return modint(res);
		}
		
		modint operator - (const modint& other) const{
			ll res = value-other.value;
			if (res < 0) res += mod;
			return modint(res);
		}

		modint operator * (const modint& other) const{
			return modint(value*other.value%mod);
		}

		modint& operator += (const modint& other){
			value += other.value;
			if (value >= mod) value -= mod;
			return *this;
		}

		modint& operator ++ (){
			value += 1;
			if (value >= mod) value -= mod;
			return *this;
		}

		modint operator ++ (int){
            modint tmp = *this;
            ++(*this);
            return tmp;
		}

		modint& operator -= (const modint& other){
			value -= other.value;
			if (value < 0) value += mod;
			return *this;
		}

		modint operator -- (){
			value -= 1;
			if (value < 0) value += mod;
			return *this;
		}

		modint& operator -- (int){
            modint tmp = *this;
            --(*this);
            return tmp;
		}
        
		modint& operator *= (const modint& other){
			value = value*other.value%mod;
			return *this;
		}

		modint pow(ll n) const{
			modint res(1), x(value);
			while (n > 0){
				if (n&1) res *= x;
				x *= x;
				n >>= 1;
			}
			return res;
		}

		modint inv() const{
			return pow(mod-2);
		}

		modint operator / (const modint& other) const{
			return *this*other.inv();
		}

		modint& operator /= (const modint& other){
			*this *= other.inv();
			return *this;
		}

		friend ostream& operator << (ostream& os, const modint& m){
			return os << m.value;
		}

		friend istream& operator >> (istream& is, modint& m){
			ll x;
			is >> x;
			m = modint(x);
			return is;
		}

        explicit operator long long() const { return value; };
		bool operator == (const modint& other) const { return value == other.value; }
		bool operator != (const modint& other) const { return value != other.value; }
        bool operator < (const modint& other) const { return value < other.value; }
        bool operator <= (const modint& other) const { return value <= other.value; }
        bool operator > (const modint& other) const { return value > other.value; }
        bool operator >= (const modint& other) const { return value >= other.value; }
		modint operator + (ll other) const { return *this+modint(other); }
		modint operator - (ll other) const { return *this-modint(other); }
		modint operator - () const { return modint(mod-value); }
		modint operator * (ll other) const { return *this*modint(other); }
		modint operator / (ll other) const { return *this/modint(other); }
	};
	template<ll mod> modint<mod> operator + (ll a, const modint<mod>& b){
		return modint<mod>(a)+b;
	}
	template<ll mod> modint<mod> operator - (ll a, const modint<mod>& b){
		return modint<mod>(a)-b;
	}
	template<ll mod> modint<mod> operator * (ll a, const modint<mod>& b){
		return modint<mod>(a)*b;
	}
	template<ll mod> modint<mod> operator / (ll a, const modint<mod>& b){
		return modint<mod>(a)/b;
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

	template<ll mod = 998244353, ll g = 3> vector<num::modint<mod>> convolution(const vector<num::modint<mod>>& a, const vector<num::modint<mod>>& b){
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
}

namespace fps{
    using mint = atcoder::static_modint<998244353>;
    using vm = vector<mint>;
    struct fps : vm {
#define d (*this)
#define s int(vm::size())
    template<class...Args> fps(Args...args): vm(args...) {}
    fps(initializer_list<mint> a): vm(a.begin(),a.end()) {}
    void rsz(int n) { if (s < n) resize(n);}
    fps& low_(int n) { resize(n); return d;}
    fps low(int n) const { return fps(d).low_(n);}
    mint& operator[](int i) { rsz(i+1); return vm::operator[](i);}
    mint operator[](int i) const { return i<s ? vm::operator[](i) : 0;}
    mint operator()(mint x) const{
        mint r;
        for (int i = s-1; i >= 0; --i) r = r*x+d[i];
        return r;
    }
    fps operator-() const { fps r(d); rep(i,s) r[i] = -r[i]; return r;}
    fps& operator+=(const fps& a) { rsz(a.size()); rep(i,a.size()) d[i] += a[i]; return d;}
    fps& operator-=(const fps& a) { rsz(a.size()); rep(i,a.size()) d[i] -= a[i]; return d;}
    fps& operator*=(const fps& a) { return d = atcoder::convolution(d, a);}
    fps& operator*=(mint a) { rep(i,s) d[i] *= a; return d;}
    fps& operator/=(mint a) { rep(i,s) d[i] /= a; return d;}
    fps operator+(const fps& a) const { return fps(d) += a;}
    fps operator-(const fps& a) const { return fps(d) -= a;}
    fps operator*(const fps& a) const { return fps(d) *= a;}
    fps operator*(mint a) const { return fps(d) *= a;}
    fps operator/(mint a) const { return fps(d) /= a;}
    fps operator~() const {
        fps r({d[0].inv()});
        for (int i = 1; i < s; i <<= 1) r = r*mint(2) - (r*r*low(i<<1)).low(i<<1);
        return r.low_(s);
    }
    fps diff() const{
        fps r(max(0, s-1));
        for (int i = 1; i < s; i++) r[i-1] = d[i]*i;
        return r;
    }
    fps& operator/=(const fps& a) { int w = s; d *= ~a; return d.low_(w);}
    fps operator/(const fps& a) const { return fps(d) /= a;}
    fps integ() const {
        fps r;
        rep(i,s) r[i+1] = d[i]/(i+1);
        return r;
    }
    fps log() const{
        assert((*this)[0] == 1);
        return (diff()*(~(*this))).low(size()-1).integ();
    }
    fps exp() const{
        assert((*this)[0] == 0);
        fps g({1});
        int n = size();
        for (int i = 1; i < n; i <<= 1){
            fps f = low(i<<1);
            fps lg = g.log();
            g = (g*(f-lg+fps({1}))).low(i<<1);
        }
        return g.low(n);
    }
    fps pow(long long k) const{
        if ((*this)[0] != 0) return (log()*mint(k)).exp().low(size());
        int n = size();
        if (k == 0) {
            fps r(n);
            r[0] = 1;
            return r;
        }
        int t = 0;
        while (t < n && (*this)[t] == 0) t++;
        if (t == n) return fps(n);
        if ((long long)t*k >= n) return fps(n);
        mint c = (*this)[t];
        fps g(n-t);
        for (int i = t; i < n; i++) g[i-t] = (*this)[i]/c;
        fps res = (g.log()*mint(k)).exp();
        mint ck = c.pow(k);
        res *= ck;
        fps ans(n);
        for (int i = 0; i < res.size(); i++) if (i+t*k < n) ans[i+t*k] = res[i];
        return ans;
    }
#undef s
#undef d
    };
    ostream& operator<<(ostream&o,const fps&a) {
        rep(i,a.size()) o<<(i?" ":"")<<a[i].val();
        return o;
    }
}

namespace matrix{
    template<typename T> class matrix{
    private:
    public:
        using mat = vector<vector<T>>;
        int sz;
        mat A;
        explicit matrix(int sz, T val = T()) : sz(sz), A(sz, vector<T>(sz, val)) {}

        vector<T>& operator [] (int i){
            return A[i];
        }

        const vector<T>& operator[] (int i) const{
            return A[i];
        }

        int size() const{
            return sz;
        }

        static matrix identity(int n){
            matrix I(n);
            for (int i = 0; i < n; i++) I[i][i] = T(1);
            return I;
        }

        friend istream& operator >> (istream& is, matrix& M){
            for(int i = 0; i < M.size(); i++){
                for(int j = 0; j < M.size(); j++){
                    is >> M[i][j];
                }
            }
            return is;
        }

        matrix operator + (const matrix& B) const{
            assert(sz == B.sz);
            matrix C(sz);
            for (int i = 0; i < sz; i++){
                for (int j = 0; j < sz; j++){
                    C[i][j] = A[i][j]+B[i][j];
                }
            }
            return C;
        }

        matrix& operator += (const matrix& B){
            assert(sz == B.sz);
            for (int i = 0; i < sz; i++){
                for (int j = 0; j < sz; j++){
                    A[i][j] += B[i][j];
                }
            }
            return *this;
        }

        matrix operator - (const matrix& B) const{
            assert(sz == B.sz);
            matrix C(sz);
            for (int i = 0; i < sz; i++){
                for (int j = 0; j < sz; j++){
                    C[i][j] = A[i][j]-B[i][j];
                }
            }
            return C;
        }

        matrix& operator -= (const matrix& B){
            assert(sz == B.sz);
            for (int i = 0; i < sz; i++){
                for (int j = 0; j < sz; j++){
                    A[i][j] -= B[i][j];
                }
            }
            return *this;
        }

        matrix operator * (const matrix& B) const{
            assert(sz == B.sz);
            matrix C(sz, T());
            for (int i = 0; i < sz; i++){
                for (int k = 0; k < sz; k++){
                    if (A[i][k] == T()) continue;
                    for (int j = 0; j < sz; j++){
                        C[i][j] += A[i][k]*B[k][j];
                    }
                }
            }
            return C;
        }

        matrix& operator *= (const matrix& B){
            assert(sz == B.sz);
            *this = (*this) *B;
            return *this;
        }

        matrix pow(long long n) const{
            matrix base = *this;
            matrix R = identity(sz);
            while (n > 0){
                if (n&1) R *= base;
                base *= base;
                n >>= 1;
            }
            return R;
        }
    };

    template<typename T> class minplus_matrix{
    private:
        using mat = vector<vector<T>>;
    public:
        T inf = numeric_limits<T>::max()/2;
        int sz;
        mat A;
        explicit minplus_matrix(int sz, T val = numeric_limits<T>::max()/2) : sz(sz), A(sz, vector<T>(sz, val)) {}

        vector<T>& operator[] (int i){
            return A[i];
        }

        const vector<T>& operator[] (int i) const{
            return A[i];
        }

        int size() const{
            return sz;
        }

        static minplus_matrix identity(int n){
            minplus_matrix I(n);
            for (int i = 0; i < n; i++) I[i][i] = 0;
            return I;
        }

        friend istream& operator >> (istream& is, minplus_matrix& M){
            for(int i = 0; i < M.size(); i++){
                for(int j = 0; j < M.size(); j++){
                    is >> M[i][j];
                }
            }
            return is;
        }

        minplus_matrix operator * (const minplus_matrix& B) const{
            assert(sz == B.sz);
            minplus_matrix C(sz);
            for (int i = 0; i < sz; i++){
                for (int k = 0; k < sz; k++){
                    for (int j = 0; j < sz; j++){
                        if (A[i][k] == inf || B[k][j] == inf) continue;
                        C[i][j] = min(C[i][j], A[i][k]+B[k][j]);
                    }
                }
            }
            return C;
        }

        minplus_matrix& operator *= (const minplus_matrix& B){
            assert(sz == B.sz);
            *this = (*this) *B;
            return *this;
        }

        minplus_matrix pow(long long n) const{
            minplus_matrix base = *this;
            minplus_matrix R = identity(sz);
            while (n > 0){
                if (n&1) R = R * base;
                base = base * base;
                n >>= 1;
            }
            return R;
        }
    };

    template<typename T> class sparsetable{
    private:
        vector<vector<T>> st;
        vector<int> log;
        function<T(T, T)> op;
        int n;
    public:
        sparsetable(const vector<T>& a, function<T(T, T)> op) : op(op){
            n = a.size();
            log.resize(n+1);
            log[1] = 0;
            for (int i = 2; i <= n; i++) log[i] = log[i/2]+1;
            int K = log[n]+1;
            st.assign(n, vector<T>(K));
            for (int i = 0; i < n; i++) st[i][0] = a[i];
            for (int j = 1; j < K; j++){
                for (int i = 0; i+(1<<j) <= n; i++){
                    st[i][j] = op(st[i][j-1], st[i+(1<<(j-1))][j-1]);
                }
            }
        }

        T prod(int l, int r){
            int j = log[r-l+1];
            return op(st[l][j], st[r-(1<<j)+1][j]);
        }
    };

    template<typename T> struct disjointsparsetable{
        int N, K;
        vector<T> A;
        vector<vector<T>> table;
        vector<int> log_table;
        function<T(T, T)> op;
        T e;

        disjointsparsetable(const vector<T>& v, T e, function<T(T, T)> op) : A(v), op(op), e(e){
            N = A.size(), K = 0;
            while ((1<<K) < N) K++;
            table.assign(K, vector<T>(N));
            for (int k = 0; k < K; k++){
                table[k] = A;
                int w = 1<<k;
                for (int a = 0; a < N; a += 2*w){
                    int mid = min(a+w, N);
                    int b = min(a+2*w, N);
                    if (mid-1 >= a){
                        table[k][mid-1] = A[mid-1];
                        for (int i = mid-2; i >= a; i--) table[k][i] = op(A[i], table[k][i+1]);
                    }
                    if (mid < b){
                        table[k][mid] = A[mid];
                        for (int i = mid+1; i < b; i++) table[k][i] = op(table[k][i-1], A[i]);
                    }
                }
            }
            log_table.resize(1<<K);
            for (int k = 0; k < K; k++){
                for (int i = (1<<k); i < (1<<(k+1)); i++) log_table[i] = k;
            }
        }

        T prod(int l, int r){
            if (l >= r) return e;
            if (l+1 == r) return A[l];
            int k = log_table[l^(r-1)];
            return op(table[k][l], table[k][r-1]);
        }
    };

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
}

namespace strings{
    bool iskaibun(string s){
        string t = s;
        reverse(t.begin(), t.end());
        return s == t;
    }

    vector<int> z_algorithm(const string& S){
        int N = S.size();
        vector<int> Z(N);
        Z[0] = N;
        int l = 0, r = 0;
        for (int i = 1; i < N; i++){
            if (i <= r) Z[i] = min(r-i+1, Z[i-l]);
            while (i+Z[i] < N && S[Z[i]] == S[i+Z[i]]) Z[i]++;
            if (i+Z[i]-1 > r) l = i, r = i+Z[i]-1;
        }
        return Z;
    }

    vector<int> manachar(const string& s){
        string t;
        for(char c: s) t += '#', t += c;
        t += '#';
        int n = t.size();
        vector<int> r(n);
        int center = 0, right = 0;
        for (int i = 0; i < n; i++){
            if (i < right) r[i] = min(right-i, r[2*center-i]);
            while(i-r[i]-1 >= 0 && i+r[i]+1 < n && t[i-r[i]-1] == t[i+r[i]+1]) r[i]++;
            if (i+r[i] > right) center = i, right = i+r[i];
        }
        return r;
    }

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

    class suffixarray{
    public:
        string s;
        vector<int> sa, lcp;

        suffixarray(const string& str){
            s = str;
            build_sa();
            build_lcp();
        }

    private:
        void build_sa(){
            int n = s.size();
            sa.resize(n);
            vector<int> rnk(n), tmp(n);
            for (int i = 0; i < n; i++) sa[i] = i, rnk[i] = (unsigned char)s[i];
            for (int k = 1; k < n; k <<= 1){
                auto cmp = [&](int i, int j){
                    if (rnk[i] != rnk[j]) return rnk[i] < rnk[j];
                    int ri = (i+k < n)? rnk[i+k]: -1;
                    int rj = (j+k < n)? rnk[j+k]: -1;
                    return ri < rj;
                };
                sort(sa.begin(), sa.end(), cmp);
                tmp[sa[0]] = 0;
                for (int i = 1; i < n; i++) tmp[sa[i]] = tmp[sa[i-1]]+cmp(sa[i-1], sa[i]);
                for (int i = 0; i < n; i++) rnk[i] = tmp[i];
            }
        }

        void build_lcp(){
            int n = s.size();
            if (n > 1) lcp.resize(n-1);
            vector<int> rnk(n);
            for (int i = 0; i < n; i++) rnk[sa[i]] = i;
            int h = 0;
            for (int i = 0; i < n; i++){
                if (rnk[i] == 0) continue;
                int j = sa[rnk[i]-1];
                if (h > 0) h--;
                while (i+h < n && j+h < n && s[i+h] == s[j+h]) h++;
                lcp[rnk[i]-1] = h;
            }
        }
    public:
        int cmp_substr(int pos, const string& t){
            int n = s.size(), m = t.size();
            for (int i = 0; i < m; i++){
                if (pos+i >= n) return -1;
                if (s[pos+i] != t[i]) return s[pos+i]-t[i];
            }
            return 0;
        }

        bool contains(const string& t){
            int left = 0, right = s.size();
            while (left < right){
                int mid = (left+right)/2;
                if (cmp_substr(sa[mid], t) < 0) left = mid+1;
                else right = mid;
            }
            if (left < (int)s.size()) return cmp_substr(sa[left], t) == 0;
            return false;
        }

        int lower_bound(const string& t){
            int left = 0, right = s.size();
            while (left < right){
                int mid = (left+right)/2;
                if (cmp_substr(sa[mid], t) < 0) left = mid+1;
                else right = mid;
            }
            return left;
        }

        int upper_bound(const string& t){
            int left = 0, right = s.size();
            while (left < right){
                int mid = (left+right)/2;
                if (cmp_substr(sa[mid], t) <= 0) left = mid+1;
                else right = mid;
            }
            return left;
        }
        
        int count(const string& t){
            return upper_bound(t)-lower_bound(t);
        }
    };
}

namespace arrays{
    class zobristrange{
    private:
        int N;
        vector<ull> w1, w2;
        vector<ull> HA1, HA2, HB1, HB2;
        vector<ull> SA, SB;

    public:
        zobristrange(int n) : N(n), w1(n+1), w2(n+1), HA1(n+1), HA2(n+1), HB1(n+1), HB2(n+1), SA(n+1), SB(n+1) {
            for (int i = 1; i <= N; i++){
                w1[i] = rng();
                w2[i] = rng();
            }
        }

        void build(const vector<int>& A, const vector<int>& B){
            for(int i = 1; i <= N; i++){
                HA1[i] = HA1[i-1]^w1[A[i]];
                HA2[i] = HA2[i-1]^w2[A[i]];
                HB1[i] = HB1[i-1]^w1[B[i]];
                HB2[i] = HB2[i-1]^w2[B[i]];
                SA[i] = SA[i-1]+w1[A[i]];
                SB[i] = SB[i-1]+w1[B[i]];
            }
        }

        bool same(int l, int r, int L, int R){
            ull a1 = HA1[r]^HA1[l-1];
            ull a2 = HA2[r]^HA2[l-1];
            ull b1 = HB1[R]^HB1[L-1];
            ull b2 = HB2[R]^HB2[L-1];
            ull sa = SA[r]-SA[l-1];
            ull sb = SB[R]-SB[L-1];
            return (a1 == b1 && a2 == b2 && sa == sb);
        }
    };

    template <class T> class suffixarray{
    public:
        vector<T> s;
        vector<int> sa, lcp;

        suffixarray(const vector<T>& str){
            s = str;
            build_sa();
            build_lcp();
        }

    private:
        void build_sa(){
            int n = s.size();
            sa.resize(n);
            vector<int> rnk(n), tmp(n);
            vector<T> xs = s;
            sort(xs.begin(), xs.end());
            xs.erase(unique(xs.begin(), xs.end()), xs.end());
            for (int i = 0; i < n; i++){
                sa[i] = i;
                rnk[i] = lower_bound(xs.begin(), xs.end(), s[i]) - xs.begin();
            }
            for (int k = 1; k < n; k <<= 1){
                auto cmp = [&](int i, int j){
                    if (rnk[i] != rnk[j]) return rnk[i] < rnk[j];
                    int ri = (i+k < n? rnk[i+k]: -1);
                    int rj = (j+k < n? rnk[j+k]: -1);
                    return ri < rj;
                };
                sort(sa.begin(), sa.end(), cmp);
                tmp[sa[0]] = 0;
                for (int i = 1; i < n; i++){
                    tmp[sa[i]] = tmp[sa[i-1]] + cmp(sa[i-1], sa[i]);
                }
                for (int i = 0; i < n; i++) rnk[i] = tmp[i];
                if (rnk[sa[n-1]] == n-1) break;
            }
        }

        void build_lcp(){
            int n = s.size();
            if (n > 1) lcp.resize(n - 1);
            vector<int> rnk(n);
            for (int i = 0; i < n; i++) rnk[sa[i]] = i;
            int h = 0;
            for (int i = 0; i < n; i++){
                if (rnk[i] == 0) continue;
                int j = sa[rnk[i]-1];
                if (h > 0) h--;
                while (i+h < n && j+h < n && s[i+h] == s[j+h]) h++;
                lcp[rnk[i]-1] = h;
            }
        }

    public:
        int cmp_substr(int pos, const vector<T>& t){
            int n = s.size(), m = t.size();
            for (int i = 0; i < m; i++){
                if (pos+i >= n) return -1;
                if (s[pos+i] != t[i]) return (s[pos+i] < t[i])? -1: 1;
            }
            return 0;
        }

        bool contains(const vector<T>& t){
            return count(t) > 0;
        }

        int lower_bound(const vector<T>& t){
            int left = 0, right = s.size();
            while (left < right){
                int mid = (left+right)/2;
                if (cmp_substr(sa[mid], t) < 0) left = mid+1;
                else right = mid;
            }
            return left;
        }

        int upper_bound(const vector<T>& t){
            int left = 0, right = s.size();
            while (left < right){
                int mid = (left+right)/2;
                if (cmp_substr(sa[mid], t) <= 0) left = mid+1;
                else right = mid;
            }
            return left;
        }

        int count(const vector<T>& t){
            return upper_bound(t)-lower_bound(t);
        }
    };
}

using amint = atcoder::static_modint<MOD>;
using mint = num::modint<MOD>;
using num::modpow;
using num::isprime;
template<typename T> using fenwicktree = tree::fenwicktree<T>;
template<typename T> using lazy_fenwicktree = tree::lazy_fenwicktree<T>;
template<typename T> using segtree = tree::segtree<T>;
template<typename T> using segatree = tree::segtree<T>;
template<typename T, typename U> using lazy_segtree = tree::lazy_segtree<T, U>;
template<typename T, typename U> using lazy_segatree = tree::lazy_segtree<T, U>;
template<typename T, typename U> using godtree = tree::godtree<T, U>;

void solve();
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout << fixed << setprecision(20);
    // testcases = 1;
    // cin >> testcases;
    while (testcases--) solve();
    return 0;
}

#define int long long
void solve(){
}
