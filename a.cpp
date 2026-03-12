#include <bits/stdc++.h>
// #define MOD 1000000007ll
#define MOD 998244353ll
#define INF (1ll<<60)
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
#define rrep(i, n) for(int i = (n)-1; i >= 0; i--)
#define each(i, a) for(auto& i : a)
#define out(x, y) (!(0 <= x && x < H && 0 <= y && y < W))
#define yes cout<<"Yes"<<endl
#define no cout<<"No"<<endl
#define yesno(a) cout<<(a?"Yes":"No")<<endl
#define sanko(a, b, c) (a? b: c)
#define ci cin
#define tostr to_string
#define func function
#define uniqueerase(A) A.erase(unique(A.begin(), A.end()), A.end())
using namespace std;
using cd = complex<long double>;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
template<typename T> using pq = priority_queue<T>;
template<typename T> using pqg = priority_queue<T, vector<T>, greater<T>>;
template<typename T> using vv = vector<vector<T>>;
template<typename T> using vvv = vector<vv<T>>;
template<typename T> using vvvv = vector<vvv<T>>;
template<typename T> using vvvvv = vector<vvvv<T>>;
// template<typename T> using uset = unorderd_set<T>;
// template<typename T> using umap = unorderd_map<T>;
template<typename T> using mset = multiset<T>;
const ll ROOT = (MOD == 998244353ll? 3: 5);
const int dx[] = { 1, 0, -1, 0 };
const int dy[] = { 0, -1, 0, 1 };
const int dx8[] = { 1, 1, 0, -1, -1, -1, 0, 1 };
const int dy8[] = { 0, -1, -1, -1, 0, 1, 1, 1 };
const long double PI = acosl(-1);
const string abcdefghijklmnopqrstuvwxyz = "abcdefghijklmnopqrstuvwxyz";
const string ABCDEFGHIJKLMNOPQRSTUVWXYZ = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const string num0123456789 = "0123456789";
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

bool iskaibun(string s){
	string t = s;
	reverse(t.begin(), t.end());
	return s == t;
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

namespace graph{
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
	
    template<typename T> class maxflow{
        struct edge{
            int to;
            T cap;
            int rev;
        };

        int N;
        vector<vector<edge>> G;
        vector<int> level, it;

    public:
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

        int N;
        vector<vector<edge>> G;
        vector<C> dist, h;
        vector<int> prevv, preve;

    public:
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

        void update(int i, T val){
            i += size;
            seg[i] = val;
            while (i >>= 1) seg[i] = op(seg[i<<1], seg[i<<1|1]);
        }

        T query(int l, int r){
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
            update(i, get(i)+val);
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

        void set(int p, S x){
            d[p+size] += x;
        }

        S get(int p){
            p += size;
            for(int i = log; i >= 1; i--) push(p>>i);
            return d[p];
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

		bool operator == (const modint& other) const { return value == other.value; }
		bool operator != (const modint& other) const { return value != other.value; }
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
}

namespace matrix{
    template<typename T> class matrix{
    private:
        using mat = vector<vector<T>>;
        int sz;
        mat A;
    public:
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

template<typename T> istream& operator >> (istream& is, matrix::matrix<T>& M){
    for(int i = 0; i < M.size(); i++){
        for(int j = 0; j < M.size(); j++){
            is >> M[i][j];
        }
    }
    return is;
}

#if MOD == 998244353ll
namespace fps{
    using mint = num::modint<998244353>;
    using F = vector<mint>;

    F multiply(const F& a, const F& b, int N){
        auto r = num::multiply_ntt<MOD, ROOT>(a, b);
        r.resize(N);
        return r;
    }

    F diff(const F& f){
        int n = f.size();
        F g(max(0, n-1));
        for (int i = 1; i < n; i++) g[i-1] = f[i]*i;
        return g;
    }

    F integral(const F& f){
        int n = f.size();
        F g(n+1);
        for (int i = 0; i < n; i++) g[i+1] = f[i]/(i+1);
        return g;
    }

    F inv(const F& f, int N){
        F g(1);
        g[0] = f[0].inv();
        for (int n = 1; n < N; n <<= 1){
            F f_cut(min((int)f.size(), 2*n));
            for (int i = 0; i < f_cut.size(); i++) f_cut[i] = f[i];
            auto gg = multiply(g, g, 2*n);
            auto fg = multiply(f_cut, gg, 2*n);
            g.resize(2*n);
            for (int i = 0; i < 2*n; i++) g[i] = g[i]*2-fg[i];
        }
        g.resize(N);
        return g;
    }

    F log(const F& f, int N){
        auto df = diff(f);
        auto invf = inv(f, N);
        auto res = multiply(df, invf, N-1);
        return integral(res);
    }

    F exp(const F& f, int N){
        F g(1);
        g[0] = 1;
        for (int n = 1; n < N; n <<= 1){
            auto lg = log(g, 2*n);
            F diff_f(2*n);
            for (int i = 0; i < min((int)f.size(), 2*n); i++) diff_f[i] = f[i];
            for (int i = 0; i < 2*n; i++) lg[i] = diff_f[i]-lg[i];
            lg[0] += 1;
            g = multiply(g, lg, 2*n);
        }
        g.resize(N);
        return g;
    }

    F fastpow(F f, int D, int K){
        F res = {1};
        while (D){
            if (D&1) res = multiply(res, f, K);
            D >>= 1;
            if (D) f = multiply(f, f, K);
        }
        return res;
    }
} 
#endif

#ifndef ONLINE_JUDGE
signed testcases = 10;
#else
signed testcases = 1;
#endif
using mint = num::modint<MOD>;
using num::modpow;
template<typename T> using fenwicktree = tree::fenwicktree<T>;
template<typename T> using segtree = tree::segtree<T>;

void solve();
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(20);
    // cin >> testcases;
    testcases = 1;
    while (testcases--) solve();
    return 0;
}

#define int long long 
void solve(){
    
}