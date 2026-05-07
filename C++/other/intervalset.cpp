template<typename T> struct intervalset {
    static constexpr T inf = numeric_limits<T>::max();
    static constexpr T ninf = numeric_limits<T>::lowest();
    set<pair<T,T>> st;

    bool touch_left(T a, T b) const{
        return b == inf || a <= b + 1;
    }

    bool touch_right(T a, T b) const{
        return b == ninf || a >= b - 1;
    }

    auto find(T x){
        auto it = st.upper_bound({x, inf});
        if (it == st.begin()) return st.end();
        --it;
        if (it->first <= x && x <= it->second) return it;
        return st.end();
    }

    bool contains(T x){
        return find(x) != st.end();
    }

    bool contains(T l, T r){
        if (l > r) return false;
        auto it = find(l);
        return it != st.end() && r <= it->second;
    }

    void insert(T l, T r){
        if (l > r) return;
        auto it = st.lower_bound({l, ninf});
        if (it != st.begin()){
            auto prv = prev(it);
            if (touch_right(prv->second, l)) it = prv;
        }
        while (it != st.end() && touch_left(it->first, r)){
            l = min(l, it->first);
            r = max(r, it->second);
            it = st.erase(it);
        }
        st.insert({l, r});
    }

    void erase(T l, T r){
        if (l > r) return;
        auto it = st.lower_bound({l, ninf});
        if (it != st.begin()) --it;
        vector<pair<T,T>> add;
        while (it != st.end()){
            auto [L, R] = *it;
            if (R < l){
                ++it;
                continue;
            }
            if (L > r) break;
            it = st.erase(it);
            if (L < l) add.push_back({L, T(l-1)});
            if (r < R) add.push_back({T(r+1), R});
        }
        for (auto &p : add) st.insert(p);
    }

    void insert(T x){
        insert(x, x);
    }

    void erase(T x){
        erase(x, x);
    }

    vector<pair<T, T>> intervals() const{
        return vector<pair<T, T>>(st.begin(), st.end());
    }

    T mex(T x){
        auto it = find(x);
        if (it == st.end()) return x;
        if (it->second == inf) return inf;
        return it->second + 1;
    }

    int size() const{
        return (int)st.size();
    }
};
