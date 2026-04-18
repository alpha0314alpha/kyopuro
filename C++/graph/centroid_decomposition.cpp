struct centroid_decomposition{
    int N;
    vector<vector<int>> G;
    vector<int> sz, par;
    vector<bool> removed;

    centroid_decomposition(int n) : N(n), G(N), sz(N), removed(N, false), par(N, -1){}

    void add_edge(int u, int v){
        
G[u].push_back(v);
        G[v].push_back(u);
    }

    int dfs_size(int n, int p){
        sz[n] = 1;
        for (int i : G[n]) if (i != p && !removed[i]) sz[n] += dfs_size(i, n);
        return sz[n];
    }

    int dfs_centroid(int n, int p, int total){
        for (int i : G[n]) if (i != p && !removed[i]){
            if (sz[i] > total/2){
                return dfs_centroid(i, n, total);
            }
        }
        return n;
    }

    void build(int n, int p){
        int total = dfs_size(n, -1);
        int c = dfs_centroid(n, -1, total);
        par[c] = p, removed[c] = true;
        for (int i : G[c]) if (!removed[i]) build(i, c);
    }

    void decompose(int root = 0){
        build(root, -1);
    }

    int get_parent(int n){
        return par[n];
    }
};
