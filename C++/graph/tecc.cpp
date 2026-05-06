struct tecc{
    int N;
    vector<vector<pair<int, int>>> G;
    vector<pair<int, int>> E;
    vector<int> ord, low, comp_;
    vector<bool> is_bridge;
    int timer = 0;

    vector<vector<int>> groups_;
    vector<vector<int>> tree_;
    bool built = false;

    tecc(int n) : N(n), G(n), ord(n, -1), low(n) {}

    void add_edge(int u, int v){
        int id = E.size();
        E.emplace_back(u, v);
        G[u].emplace_back(v, id);
        G[v].emplace_back(u, id);
    }

    void dfs(int v, int pe = -1){
        ord[v] = low[v] = timer++;
        for (auto [to, id] : G[v]){
            if (id == pe) continue;
            if (ord[to] != -1){
                low[v] = min(low[v], ord[to]);
            }
            else{
                dfs(to, id);
                low[v] = min(low[v], low[to]);
                if (ord[v] < low[to]) is_bridge[id] = true;
            }
        }
    }

    void build(){
        if (built) return;
        built = true;
        fill(ord.begin(), ord.end(), -1);
        timer = 0;
        is_bridge.assign(E.size(), false);
        for (int i = 0; i < N; i++) if (ord[i] == -1) dfs(i);
        dsu uf(N);
        for (int i = 0; i < (int)E.size(); i++){
            if (!is_bridge[i]){
                auto [u, v] = E[i];
                uf.merge(u, v);
            }
        }
        comp_.resize(N);
        map<int, int> mp;
        int idx = 0;
        for (int i = 0; i < N; i++){
            int r = uf.root(i);
            if (!mp.count(r)) mp[r] = idx++;
            comp_[i] = mp[r];
        }
        groups_.assign(idx, {});
        for (int i = 0; i < N; i++){
            groups_[comp_[i]].push_back(i);
        }
        tree_.assign(idx, {});
        for (int i = 0; i < (int)E.size(); i++){
            if (!is_bridge[i]) continue;
            auto [u, v] = E[i];
            int a = comp_[u], b = comp_[v];
            tree_[a].push_back(b);
            tree_[b].push_back(a);
        }
    }

    const vector<int>& comp(){
        build();
        return comp_;
    }

    const vector<vector<int>>& groups(){
        build();
        return groups_;
    }

    const vector<vector<int>>& tree(){
        build();
        return tree_;
    }
};
