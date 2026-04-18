template<typename T> struct persistent_segtree{
private:
    struct node{
        T val;
        node *l, *r;
        node(T v, node* l = nullptr, node* r = nullptr) : val(v), l(l), r(r) {}
    };

    int n;
    T e;
    function<T(T, T)> op;
    vector<node*> roots;
    node* build(int l, int r, const vector<T>& A){
        if (l+1 == r){
            if (l < (int)A.size()) return new node(A[l]);
            return new node(e);
        }
        int m = (l+r)/2;
        node* left = build(l, m, A);
        node* right = build(m, r, A);
        return new node(op(left->val, right->val), left, right);
    }

    node* update(node* cur, int l, int r, int idx, T val){
        if (l+1 == r) return new node(val);
        int m = (l+r)/2;
        if (idx < m){
            node* nl = update(cur->l, l, m, idx, val);
            return new node(op(nl->val, cur->r->val), nl, cur->r);
        }
        else{
            node* nr = update(cur->r, m, r, idx, val);
            return new node(op(cur->l->val, nr->val), cur->l, nr);
        }
    }

    T query(node* node, int l, int r, int ql, int qr){
        if (qr <= l || r <= ql) return e;
        if (ql <= l && r <= qr) return node->val;
        int m = (l+r)/2;
        return op(query(node->l, l, m, ql, qr), query(node->r, m, r, ql, qr));
    }

    T get_val(node* node, int l, int r, int idx){
        if (l+1 == r) return node->val;
        int m = (l+r)>>1;
        if (idx < m) return get_val(node->l, l, m, idx);
        else return get_val(node->r, m, r, idx);
    }
public:

    persistent_segtree(const vector<T>& A, T id, function<T(T,T)> op) : n(A.size()), e(id), op(op){
        roots.push_back(build(0, n, A));
    }

    persistent_segtree(int sz, T id, function<T(T,T)> op) : n(sz), e(id), op(op){
        vector<T> A;
        roots.push_back(build(0, n, A));
    }

    int set(int v, int i, T val){
        node* newRoot = update(roots[v], 0, n, i, val);
        roots.push_back(newRoot);
        return (int)roots.size()-1;
    }

    int add(int v, int i, T val){
        T cur = get_val(roots[v], 0, n, i);
        return set(v, i, cur+val);
    }

    T prod(int v, int l, int r){
        return query(roots[v], 0, n, l, r);
    }

    T get(int v, int i){
        return get_val(roots[v], 0, n, i);
    }

    int versions() const{
        return roots.size();
    }
};
