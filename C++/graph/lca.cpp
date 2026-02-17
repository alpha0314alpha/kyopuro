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