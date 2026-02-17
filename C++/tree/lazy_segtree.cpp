template<class T> class lazy_segtree{
private:
    int n;
    vector<T> seg, lazy;
    vector<bool> flag;
    T e;
    function<T(T,T)> op;

    void build(int node, int l, int r, const vector<T>& A){
        if(r-l == 1){
            seg[node] = A[l];
            return;
        }
        int mid = (l+r)/2;
        build(node*2, l, mid, A);
        build(node*2+1, mid, r, A);
        seg[node] = op(seg[node*2], seg[node*2+1]);
    }

    void push(int node, int l, int r){
        if(!flag[node]) return;
        int mid = (l+r)/2;
        apply(node*2, l, mid, lazy[node]);
        apply(node*2+1, mid, r, lazy[node]);
        flag[node] = false;
    }

    void apply(int node, int l, int r, T val){
        seg[node] = val * (r-l);
        lazy[node] = val;
        flag[node] = true;
    }

    void update(int node, int l, int r, int ql, int qr, T val){
        if(qr <= l || r <= ql) return;
        if(ql <= l && r <= qr){
            apply(node, l, r, val);
            return;
        }
        push(node, l, r);
        int mid = (l+r)/2;
        update(node*2, l, mid, ql, qr, val);
        update(node*2+1, mid, r, ql, qr, val);
        seg[node] = op(seg[node*2], seg[node*2+1]);
    }

    T query(int node, int l, int r, int ql, int qr){
        if(qr <= l || r <= ql) return e;
        if(ql <= l && r <= qr) return seg[node];
        push(node, l, r);
        int mid = (l+r)/2;
        return op(query(node*2, l, mid, ql, qr),
                    query(node*2+1, mid, r, ql, qr));
    }

    T get(int node, int l, int r, int idx){
        if(r-l == 1) return seg[node];
        push(node, l, r);
        int mid = (l+r)/2;
        if(idx < mid) return get(node*2, l, mid, idx);
        else return get(node*2+1, mid, r, idx);
    }

    void add(int node, int l, int r, int idx, T val){
        if(r-l == 1){
            seg[node] += val;
            return;
        }
        push(node, l, r);
        int mid = (l+r)/2;
        if(idx < mid) add(node*2, l, mid, idx, val);
        else add(node*2+1, mid, r, idx, val);
        seg[node] = op(seg[node*2], seg[node*2+1]);
    }

    int find_first(int node, int nl, int nr, int l, T val){
        if(nr <= l) return -1;
        push(node, nl, nr);
        if(seg[node] < val) return -1;
        if(nr-nl == 1) return nl;

        int mid = (nl+nr)/2;
        int res = find_first(node*2, nl, mid, l, val);
        if(res != -1) return res;
        return find_first(node*2+1, mid, nr, l, val);
    }

    int find_last(int node, int nl, int nr, int r, T val){
        if(r <= nl) return -1;
        push(node, nl, nr);
        if(seg[node] < val) return -1;
        if(nr-nl == 1) return nl;

        int mid = (nl+nr)/2;
        int res = find_last(node*2+1, mid, nr, r, val);
        if(res != -1) return res;
        return find_last(node*2, nl, mid, r, val);
    }

    int find_th(int node, int l, int r, T k){
        push(node, l, r);
        if(seg[node] < k) return -1;
        if(r-l == 1) return l;
        int mid = (l+r)/2;
        push(node*2, l, mid);
        if(seg[node*2] >= k){
            return find_th(node*2, l, mid, k);
        }
        else {
            return find_th(node*2+1, mid, r, k - seg[node*2]);
        }
    }

public:
    lazy_segtree(const vector<T>& A, T id, function<T(T,T)> op) : e(id), op(op){
        n = A.size();
        seg.assign(4*n, e);
        lazy.assign(4*n, 0);
        flag.assign(4*n, false);
        build(1, 0, n, A);
    }

    void update(int l, int r, T val){ update(1, 0, n, l, r, val); }
    T query(int l, int r){ return query(1, 0, n, l, r); }
    T get(int idx){ return get(1, 0, n, idx); }
    void add(int idx, T val){ add(1, 0, n, idx, val); }
    int find_first(int l, T val){ return find_first(1, 0, n, l, val); }
    int find_last(int r, T val){ return find_last(1, 0, n, r, val); }
    int find_th(T k){ return find_th(1, 0, n, k); }
};