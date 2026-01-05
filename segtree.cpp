#include <vector>

template<class T> class segtree{
private:
    int n;
    vector<T> seg;
    T e;
    function<T(T, T)> op;

    void build(int node, int l, int r, const vector<T> &A){
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
public:
    segtree(const vector<T> &A, T id, function<T(T, T)> op) : e(id), op(op){
        n = A.size();
        seg.assign(4*n, e);
        build(1, 0, n, A);
    }

    T query(int l, int r) const{
        return query(1, 0, n, l, r);
    }

    void update(int idx, T val){
        update(1, 0, n, idx, val);
    }
};
