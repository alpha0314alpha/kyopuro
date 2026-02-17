class scc{
public:
    int N;
    vector<vector<int>> graph;
    vector<int> ord, low, comp;
    vector<bool> in_stack;
    stack<int> st;
    int noword = 0, compcount = 0;

    scc(int n) : N(n), graph(n) {}

    void add_edge(int u, int v){
        graph[u].push_back(v);
    }

    void dfs(int v){
        noword++;
        ord[v] = noword;
        low[v] = noword;
        st.push(v);
        in_stack[v] = true;
        for (int to : graph[v]){
            if (ord[to] == -1){
                dfs(to);
                low[v] = min(low[v], low[to]);
            }
            else if (in_stack[to]){
                low[v] = min(low[v], ord[to]);
            }
        }
        if (ord[v] == low[v]){
            while (true){
                int u = st.top();
                st.pop();
                in_stack[u] = false;
                comp[u] = compcount;
                if (u == v) break;
            }
            compcount++;
        }
    }

    int build(){
        noword = 0, compcount = 0;
        ord.assign(N, -1);
        low.resize(N);
        comp.resize(N);
        in_stack.assign(N, false);
        for (int i = 0; i < N; i++){
            if (ord[i] == -1) dfs(i);
        }
        return compcount;
    }
};