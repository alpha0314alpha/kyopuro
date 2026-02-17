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