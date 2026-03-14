    template<typename T> class rerooting{
    private:
    public:
        int n;
        T id;
        vector<vector<int>> g;
        vector<T> dp, ans;
        function<T(T, T)> merge;
        function<T(T)> add_root;

        rerooting(int n, T id, function<T(T, T)> merge, function<T(T)> add_root) : n(n), g(n), dp(n, id), ans(n, id), id(id), merge(merge), add_root(add_root) {}

        void add_edge(int u, int v){
            g[u].push_back(v);
            g[v].push_back(u);
        }

        void dfs1(int v, int p){
            T res = id;
            for (int i : g[v]) if (i != p){
                dfs1(i, v);
                res = merge(res, add_root(dp[i]));
            }
            dp[v] = res;
        }

        void dfs2(int v, int p, T from_parent){
            int deg = g[v].size();
            vector<T> prefix(deg+1, id), suffix(deg+1, id);
            for (int i = 0; i < deg; i++){
                int to = g[v][i];
                T val;
                if (to == p) val = from_parent;
                else val = add_root(dp[to]);
                prefix[i+1] = merge(prefix[i], val);
            }
            for (int i = deg-1; i >= 0; i--){
                int to = g[v][i];
                T val;
                if (to == p) val = from_parent;
                else val = add_root(dp[to]);
                suffix[i] = merge(suffix[i+1], val);
            }
            ans[v] = prefix[deg];
            for (int i = 0; i < deg; i++){
                int to = g[v][i];
                if (to == p) continue;
                T val = add_root(merge(prefix[i], suffix[i+1]));
                dfs2(to, v, val);
            }
        }

        vector<T> output(){
            dfs1(0, -1);
            dfs2(0, -1, add_root(id));
            return ans;
        }
    };
