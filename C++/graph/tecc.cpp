struct tecc{
    int N;
    vector<vector<pair<int, int>>> G;
    vector<pair<int, int>> E;
    vector<int> ord, low, comp;
    vector<bool> is_bridge;
    int timer = 0;

    tecc(int n) : N(n), G(n), ord(n, -1), low(n) {}
    
    void add_edge(int u, int v){
        int id = E.size();
        E.emplace_back(u, v);
        G[u].emplace_back(v, id);
        G[v].emplace_back(u, id);
    }

    void dfs(int n, int p = -1){
        ord[n] = low[n] = timer++;
        for (auto [i, id] : G[n]) if (id != p){
            if (ord[i] != -1) low[n] = min(low[n], ord[i]);
            else{
                dfs(i, id);
                low[n] = min(low[n], low[i]);
                if (ord[n] < low[i]) is_bridge[id] = true;
            }
        }
    }

    vector<vector<int>> build(){
        fill(ord.begin(), ord.end(), -1);
        timer = 0;
        is_bridge.assign(E.size(), false);
        for (int i = 0; i < N; i++) if (ord[i] == -1) dfs(i);
        dsu uf(N);
        for (int i = 0; i < (int)E.size(); i++){
            if (is_bridge[i]) continue;
            auto [u, v] = E[i];
            uf.merge(u, v);
        }
        comp.resize(N);
        map<int, int> mp;
        int idx = 0;
        for (int i = 0; i < N; i++){
            int r = uf.root(i);
            if (!mp.count(r)) mp[r] = idx++;
            comp[i] = mp[r];
        }
        vector<vector<int>> tree(idx);
        for (int i = 0; i < (int)E.size(); i++){
            if (!is_bridge[i]) continue;
            auto [u, v] = E[i];
            int a = comp[u], b = comp[v];
            tree[a].push_back(b);
            tree[b].push_back(a);
        }
        return tree;
    }
};
