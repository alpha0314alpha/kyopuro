template<class T> struct lower_bound_maxflow{
    int N, SS, TT;
    atcoder::mf_graph<T> G;
    vector<T> bal;
    lower_bound_maxflow(int n) : N(n), SS(n), TT(n+1), G(n+2), bal(N, T()) {}

    void add_edge(int u, int v, T lo, T hi){
        assert(lo <= hi);
        G.add_edge(u, v, hi-lo);
        bal[u] -= lo, bal[v] += lo;
    }

    bool build(int s, int t){
        const T inf = numeric_limits<T>::max()/4;
        G.add_edge(t, s, inf);
        T sum = 0;
        for (int i = 0; i < N; i++){
            if (bal[i] > 0){
                G.add_edge(SS, i, bal[i]);
                sum += bal[i];
            }
            else if (bal[i] < 0){
                G.add_edge(i, TT, -bal[i]);
            }
        }
        return G.flow(SS, TT) == sum;
    }

    T flow(int s, int t){
        return G.flow(s, t);
    }
};
