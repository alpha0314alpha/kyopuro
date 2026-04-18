struct hld{
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
