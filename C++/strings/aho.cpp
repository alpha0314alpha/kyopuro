struct aho{
    struct node{
        int next[26];
        int fail, par;
        bool bad;

        node(){
            memset(next, -1, sizeof(next));
            fail = 0;
            par = -1;
            bad = false;
        }
    };

    vector<node> T;

    aho(){
        T.emplace_back();
    }

    node operator [] (int i) const{
        return T[i];
    }

    int size() const{
        return (int)T.size();
    }

    int add(string S){
        int v = 0;
        for (char c : S){
            int b = c-'a';
            if (T[v].next[b] == -1){
                T[v].next[b] = T.size();
                T.emplace_back();
                T.back().par = v;
            }
            v = T[v].next[b];
        }
        T[v].bad = true;
        return v;
    }

    void build(){
        queue<int> Q;
        for (int i = 0; i < 26; i++){
            int u = T[0].next[i];
            if (u == -1) T[0].next[i] = 0;
            else{
                T[u].fail = 0;
                Q.push(u);
            }
        }
        while (!Q.empty()){
            int v = Q.front();
            Q.pop();
            T[v].bad |= T[T[v].fail].bad;
            for (int i = 0; i < 26; i++){
                int u = T[v].next[i];
                if (u == -1) T[v].next[i] = T[T[v].fail].next[i];
                else{
                    T[u].fail = T[T[v].fail].next[i];
                    Q.push(u);
                }
            }
        }
    }
};
