template<class T> class segtree{
private:
    int n, size;
    vector<T> seg;
    T e;
    function<T(T, T)> op;
public:
    segtree(const vector<T>& A, T id, function<T(T, T)> op) : e(id), op(op){
        n = A.size();
        size = 1;
        while (size < n) size <<= 1;
        seg.assign(2*size, e);
        for (int i = 0; i < n; i++) seg[size+i] = A[i];
        for (int i = size-1; i > 0; i--) seg[i] = op(seg[i<<1], seg[i<<1|1]);
    }

    void update(int i, T val){
        i += size;
        seg[i] = val;
        while (i >>= 1) seg[i] = op(seg[i<<1], seg[i<<1|1]);
    }

    T query(int l, int r){
        T L = e, R = e;
        for (l += size, r += size; l < r; l >>= 1, r >>= 1){
            if (l&1) L = op(L, seg[l++]);
            if (r&1) R = op(seg[--r], R);
        }
        return op(L, R);
    }

    T get(int i){
        return seg[size+i];
    }

    void add(int i, T val){
        update(i, get(i)+val);
    }

    template<typename F> int max_right(int l, F f){
        if (l == n) return n;
        l += size;
        T sm = e;
        do{
            while ((l & 1) == 0) l >>= 1;
            if (!f(op(sm, seg[l]))){
                while (l < size){
                    l <<= 1;
                    if (f(op(sm, seg[l]))){
                        sm = op(sm, seg[l]);
                        l++;
                    }
                }
                return l-size;
            }
            sm = op(sm, seg[l]);
            l++;
        }while((l&-l) != l);
        return n;
    }

    template<typename F> int min_left(int r, F f){
        if (r == 0) return 0;
        r += size;
        T sm = e;
        do{
            r--;
            while (r > 1 && (r&1)) r >>= 1;
            if (!f(op(seg[r], sm))){
                while (r < size){
                    r = r<<1|1;
                    if (f(op(seg[r], sm))){
                        sm = op(seg[r], sm);
                        r--;
                    }
                }
                return r+1-size;
            }
            sm = op(seg[r], sm);
        }while((r&-r) != r);
        return 0;
    }
};