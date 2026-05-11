template<typename t> struct array_trie{
    struct node{
        int count = 0, terminal_count = 0;
        map<t, node*> to;
    };

    node* root;
    array_trie(){ root = new node(); }
    ~array_trie(){ clear(root); }
    int size() const{ return root->count; }

    template<typename F> void dfs(const F& f, node* v = nullptr, bool is_root = true){
        if (v == nullptr) v = root;
        f(v, is_root);
        for (auto& [c, u] : v->to) dfs(f, u, false);
    }

    void insert(const vector<t>& s, int k = 1){
        node* cur = root;
        cur->count += k;
        for (t c : s){
            if (!cur->to.count(c)) cur->to[c] = new node();
            cur = cur->to[c];
            cur->count += k;
        }
        cur->terminal_count += k;
    }

    int count(const vector<t>& s) const{
        node* cur = root;
        for (t c : s){
            if (!cur->to.count(c)) return 0;
            cur = cur->to.at(c);
        }
        return cur->terminal_count;
    }

    bool contains(const vector<t>& s) const{
        return count(s) > 0;
    }

    int prefix_count(const vector<t>& s) const{
        node* cur = root;
        for (t c : s){
            if (!cur->to.count(c)) return 0;
            cur = cur->to.at(c);
        }
        return cur->count;
    }

    bool starts_with(const vector<t>& s) const{
        node* cur = root;
        for (t c : s){
            if (!cur->to.count(c)) return false;
            cur = cur->to.at(c);
        }
        return true;
    }

    bool erase(const vector<t>& s, int k = 1){
        int exist = count(s);
        if (exist < k) return false;
        vector<pair<node*, t>> path;
        node* cur = root;
        cur->count -= k;
        for (t c : s){
            path.push_back({cur, c});
            cur = cur->to[c];
            cur->count -= k;
        }
        cur->terminal_count -= k;
        for (int i = (int)path.size()-1; i >= 0; i--){
            node* parent = path[i].first;
            t c = path[i].second;
            node* child = parent->to[c];
            if (child->count == 0){
                delete child;
                parent->to.erase(c);
            }
            else break;
        }
        return true;
    }

    void clear(node* v){
        for (auto& [c, u] : v->to) clear(u);
        delete v;
    }
};
