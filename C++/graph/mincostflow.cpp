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