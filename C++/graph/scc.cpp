struct scc{
    int N;
    vector<vector<int>> G, RG;
    vector<int> comp, order;
    vector<bool> used;

    scc(int n) : N(n), G(n), RG(n), comp(n, -1), used(n, false) {}

    void add_edge(int u, int v){
        G[u].push_back(v);
        RG[v].push_back(u);
    }

    void dfs(int n){
        used[n] = true;
        for (int i : G[n]) if (!used[i]) dfs(i);
        order.push_back(n);
    }

    void rdfs(int n, int k){
        comp[n] = k;
        for (int i : RG[n]) if (comp[i] == -1) rdfs(i, k);
    }

    vector<vector<int>> build(){
        for (int i = 0; i < N; i++) if (!used[i]) dfs(i);
        reverse(order.begin(), order.end());
        int k = 0;
        for (int i : order) if (comp[i] == -1) rdfs(i, k++);
        vector<vector<int>> res(k);
        for (int i = 0; i < N; i++) res[comp[i]].push_back(i);
        return res;
    }
};
