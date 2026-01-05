#include <vector>

template<class T> class lazy_segtree {
private:
    int n;
    vector<T> seg, lazy;
    T e;
    function<T(T, T)> op;

    void build(int node, int l, int r, const vector<T> &A){
        if (r - l == 1) {
            seg[node] = A[l];
            return;
        }
        int mid = (l + r) / 2;
        build(node*2, l, mid, A);
        build(node*2+1, mid, r, A);
        seg[node] = op(seg[node*2], seg[node*2+1]);
    }

    void push(int node){
        if (lazy[node] != 0) {
            seg[node*2] += lazy[node];
            seg[node*2+1] += lazy[node];
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
            lazy[node] = 0;
        }
    }

    void update(int node, int l, int r, int ql, int qr, T val){
        if (qr <= l || r <= ql) return;
        if (ql <= l && r <= qr) {
            seg[node] += val;
            lazy[node] += val;
            return;
        }
        push(node);
        int mid = (l+r)/2;
        update(node * 2, l, mid, ql, qr, val);
        update(node * 2 + 1, mid, r, ql, qr, val);
        seg[node] = op(seg[node*2], seg[node*2+1]);
    }

    T query(int node, int l, int r, int ql, int qr){
        if (qr <= l || r <= ql) return e;
        if (ql <= l && r <= qr) return seg[node];
        push(node);
        int mid = (l+r)/2;
        return op(
            query(node*2, l, mid, ql, qr),
            query(node*2+1, mid, r, ql, qr)
        );
    }

public:
    lazy_segtree(const vector<T>& A, T id, function<T(T, T)> op) : e(id), op(op){
        n = A.size();
        seg.assign(4 * n, e);
        lazy.assign(4 * n, 0);
        build(1, 0, n, A);
    }

    void update(int l, int r, T val){
        update(1, 0, n, l, r, val);
    }

    T query(int l, int r){
        return query(1, 0, n, l, r);
    }
};
