template<typename T> class intervalset{
public:
    set<pair<T, T>> s;

    void add(T l, T r){
        auto it = s.lower_bound({l, numeric_limits<T>::lowest()});
        if (it != s.begin()) it--;
        while (it != s.end()){
            if (it->second < l){
                it++;
                continue;
            }
            if (it->first > r) break;
            l = min(l, it->first);
            r = max(r, it->second);
            it = s.erase(it);
        }
        s.insert({l, r});
    }

    void remove(T l, T r){
        auto it = s.lower_bound({l+1, numeric_limits<T>::lowest()});
        if (it != s.begin()) it--;
        vector<pair<T, T>> add;
        while (it != s.end()){
            T L = it->first;
            T R = it->second;
            if (R < l){
                it++;
                continue;
            }
            if (L > r) break;
            if (L < l) add.push_back({L, l-1});
            if (R > r) add.push_back({r+1, R});
            it = s.erase(it);
        }

        for (auto p : add) s.insert(p);
    }

    void print(){
        for (auto p : s){
            cout << '[' << p.first << ',' << p.second << ']' << endl;
        }
    }
};