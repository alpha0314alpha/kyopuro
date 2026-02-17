template<class T> class segtree{
private:
    int n;
    vector<T> seg;
    T e;
    function<T(T, T)> op;

    void build(int node, int l, int r, const vector<T>& A){
        if (r-l == 1){
            seg[node] = A[l];
            return;
        }
        int mid = (l+r)/2;
        build(node*2, l, mid, A);
        build(node*2+1, mid, r, A);
        seg[node] = op(seg[node*2], seg[node*2+1]);
    }

    T query(int node, int l, int r, int ql, int qr) const{
        if (qr <= l || r <= ql) return e;
        if (ql <= l && r <= qr) return seg[node];
        int mid = (l+r)/2;
        return op(query(node*2, l, mid, ql, qr), query(node*2+1, mid, r, ql, qr));
    }

    int find_first(int node, int nl, int nr, int l, T val){
        if (nr <= l) return -1;
        if (seg[node] > val) return -1;
        if (nr-nl == 1) return nl;

        int mid = (nl+nr)/2;
        int res = -1;

        if (l < mid){
            res = find_first(node*2, nl, mid, l, val);
            if (res != -1) return res;
            return find_first(node*2+1, mid, nr, l, val);
        }
        else{
            return find_first(node*2+1, mid, nr, l, val);
        }
    }

    int find_last(int node, int nl, int nr, int r, T val){
        if (r <= nl) return -1;
        if (seg[node] <= val) return -1;
        if (nr - nl == 1) return nl;

        int mid = (nl + nr) / 2;
        int res = find_last(node*2+1, mid, nr, r, val);
        if (res != -1) return res;
        return find_last(node*2, nl, mid, r, val);
    }

    int find_th(int node, int l, int r, int k){
        if(r-l == 1) return l;
        int mid = (l+r)/2;
        if (seg[node*2] >= k) return find_th(node*2, l, mid, k);
        else return find_th(node*2+1, mid, r, k-seg[node*2]);
    }

    void update(int node, int l, int r, int idx, T val){
        if (r-l == 1){
            seg[node] = val;
            return;
        }
        int mid = (l+r)/2;
        if (idx < mid) update(node*2, l, mid, idx, val);
        else update(node*2+1, mid, r, idx, val);
        seg[node] = op(seg[node*2], seg[node*2+1]);
    }

    T get(int node, int l, int r, int idx) const{
        if (r-l == 1) return seg[node];
        int mid = (l+r)/2;
        if (idx < mid) return get(node*2, l, mid, idx);
        else return get(node*2+1, mid, r, idx);
    }
public:
    segtree(const vector<T>& A, T id, function<T(T, T)> op) : e(id), op(op){
        n = A.size();
        seg.assign(4*n, e);
        build(1, 0, n, A);
    }

    T query(int l, int r) const{ return query(1, 0, n, l, r); }
    void update(int idx, T val){ update(1, 0, n, idx, val); }
    int find_first(int l, T val){ return find_first(1, 0, n, l, val); }
    int find_last(int l, T val){ return find_last(1, 0, n, l, val); }
    int find_th(int k){ if(seg[1] < k) return -1; return find_th(1, 0, n, k); }
    T get(int idx) const{ return get(1, 0, n, idx); }
    void add(int idx, T val){ update(idx, get(idx) + val); }
};