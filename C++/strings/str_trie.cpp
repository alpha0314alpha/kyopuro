struct str_trie{
    struct node{
        int count = 0, terminal_count = 0;
        map<char, node*> to;
    };

    node* root;
    str_trie(){ root = new node(); }
    ~str_trie(){ clear(root); }
    int size() const{ return root->count; }

    template<typename F> void dfs(const F& f, node* v = nullptr, bool is_root = true){
        if (v == nullptr) v = root;
        f(v, is_root);
        for (auto& [c, u] : v->to) dfs(f, u, false);
    }

    void insert(const string& s, int k = 1){
        node* cur = root;
        cur->count += k;
        for (char c : s){
            if (!cur->to.count(c)) cur->to[c] = new node();
            cur = cur->to[c];
            cur->count += k;
        }
        cur->terminal_count += k;
    }

    int count(const string& s) const{
        node* cur = root;
        for (char c : s){
            if (!cur->to.count(c)) return 0;
            cur = cur->to.at(c);
        }
        return cur->terminal_count;
    }

    bool contains(const string& s) const{
        return count(s) > 0;
    }

    int prefix_count(const string& s) const{
        node* cur = root;
        for (char c : s){
            if (!cur->to.count(c)) return 0;
            cur = cur->to.at(c);
        }
        return cur->count;
    }

    bool starts_with(const string& s) const{
        node* cur = root;
        for (char c : s){
            if (!cur->to.count(c)) return false;
            cur = cur->to.at(c);
        }
        return true;
    }

    bool erase(const string& s, int k = 1){
        int exist = count(s);
        if (exist < k) return false;
        vector<pair<node*, char>> path;
        node* cur = root;
        cur->count -= k;
        for (char c : s){
            path.push_back({cur, c});
            cur = cur->to[c];
            cur->count -= k;
        }
        cur->terminal_count -= k;
        for (int i = (int)path.size()-1; i >= 0; i--){
            node* parent = path[i].first;
            char c = path[i].second;
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
