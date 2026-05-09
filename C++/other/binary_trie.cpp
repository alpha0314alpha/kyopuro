struct binary_trie{
    struct node{
        int ch[2];
        int count;
        node() : ch{-1,-1}, count(0) {}
    };

    static constexpr int LOG = 60;
    vector<node> T;

    binary_trie(){
        T.emplace_back();
    }

    int new_node(){
        T.emplace_back();
        return (int)T.size()-1;
    }

    int size() const{
        return T[0].count;
    }

    int count(ll x) const{
        int v = 0;
        for (int i = LOG-1; i >= 0; i--){
            int f = (x>>i)&1;
            if (T[v].ch[f] == -1) return 0;
            else v = T[v].ch[f];
        }
        return T[v].count;
    }

    void insert(ll x, int k = 1){
        int v = 0;
        T[v].count += k;
        for (int i = LOG-1; i >= 0; i--){
            int f = (x>>i)&1;
            if (T[v].ch[f] == -1) T[v].ch[f] = new_node();
            v = T[v].ch[f];
            T[v].count += k;
        }
    }

    bool erase(ll x, int k = 1){
        if (count(x) < k) return false;
        else{
            int v = 0;
            T[v].count -= k;
            for (int i = LOG-1; i >= 0; i--){
                int f = (x>>i)&1;
                v = T[v].ch[f];
                T[v].count -= k;
            }
            return true;
        }
    }

    ll kth(int k) const{
        assert(0 <= k && k < size());
        int v = 0;
        ll x = 0;
        for (int i = LOG-1; i >= 0; i--){
            int lc = 0;
            if (T[v].ch[0] != -1) lc = T[T[v].ch[0]].count;
            if (k < lc) v = T[v].ch[0];
            else{
                k -= lc;
                x |= 1LL<<i;
                v = T[v].ch[1];
            }
        }
        return x;
    }

    int count_less(ll x) const{
        int v = 0;
        int res = 0;
        for (int i = LOG-1; i >= 0; i--){
            if (v == -1) break;
            int f = (x>>i)&1;
            if (f){
                int u = T[v].ch[0];
                if (u != -1) res += T[u].count;
            }
            v = T[v].ch[f];
        }
        return res;
    }

    ll min_xor(ll x) const{
        assert(size() > 0);
        int v = 0;
        ll res = 0;
        for (int i = LOG-1; i >= 0; i--){
            int f = (x>>i)&1;
            int u = T[v].ch[f];
            if (u != -1 && T[u].count > 0){
                v = u;
            }
            else{
                res |= 1LL<<i;
                v = T[v].ch[f^1];
            }
        }
        return res;
    }

    ll max_xor(ll x) const{
        assert(size() > 0);
        int v = 0;
        ll res = 0;
        for (int i = LOG-1; i >= 0; i--){
            int f = ((x>>i)&1)^1;
            int u = T[v].ch[f];
            if (u != -1 && T[u].count > 0){
                res |= 1LL<<i;
                v = u;
            }
            else v = T[v].ch[f^1];
        }
        return res;
    }
};
