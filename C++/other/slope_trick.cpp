template<class T> struct slope_trick{
    T min_f = 0, lazy_l = 0, lazy_r = 0;
    priority_queue<T, vector<T>, less<T>> L;
    priority_queue<T, vector<T>, greater<T>> R;

    T top_l() const{ return L.empty()? numeric_limits<T>::lowest(): L.top()+lazy_l; }
    T top_r() const{ return R.empty()? numeric_limits<T>::max(): R.top()+lazy_r; }
    void push_l(T x){ L.push(x-lazy_l); }
    void push_r(T x){ R.push(x-lazy_r); }
    void clear_l(){ while (!L.empty()) L.pop(); }
    void clear_r(){ while (!R.empty()) R.pop(); }
    void shift(T l, T r){ lazy_l -= l, lazy_r -= r; }
    T get_min() const{ return min_f; }
    pair<T, T> argmin() const{ return make_pair(top_l(), top_r()); }

    void add_l(T a){
        if (!R.empty() && a > top_r()){
            min_f += a-top_r();
            push_r(a);
            push_l(top_r());
            R.pop();
        }
        else push_l(a);
    }

    void add_r(T a){
        if (!L.empty() && a < top_l()){
            min_f += top_l() - a;
            push_l(a);
            push_r(top_l());
            L.pop();
        }
        else push_r(a);
    }

    void add_abs(T a){
        add_l(a);
        add_r(a);
    }
};
