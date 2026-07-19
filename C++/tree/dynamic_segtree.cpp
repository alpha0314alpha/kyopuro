template<class S> struct dynamic_segtree{
    struct Node{
        S val;
        Node *l, *r;
        Node(S v) : val(v), l(nullptr), r(nullptr) {}
    };

    Node* root = nullptr;
    static constexpr ll L = -(1LL<<60);
    static constexpr ll R = (1LL<<60);
    function<S(S, S)> op;
    function<S()> e;
    dynamic_segtree(function<S(S, S)> op, function<S()> e) : op(op), e(e) {}

    void set(Node*& node, ll nl, ll nr, ll idx, S x){
        if (!node) node = new Node(e());
        if (nr-nl == 1){
            node->val = x;
            return;
        }
        ll mid = (nl+nr)>>1;
        if (idx < mid) set(node->l, nl, mid, idx, x);
        else set(node->r, mid, nr, idx, x);
        S lv = node->l? node->l->val: e();
        S rv = node->r? node->r->val: e();
        node->val = op(lv, rv);
    }

    bool contains(Node* node, ll nl, ll nr, ll idx) const{
        if (!node) return false;
        if (nr-nl == 1) return true;
        ll mid = (nl+nr)>>1;
        if (idx < mid) return contains(node->l, nl, mid, idx);
        else return contains(node->r, mid, nr, idx);
    }

    S query(Node* node, ll nl, ll nr, ll ql, ll qr) const{
        if (!node || nr <= ql || qr <= nl) return e();
        if (ql <= nl && nr <= qr) return node->val;
        ll mid = (nl+nr)>>1;
        return op(query(node->l, nl, mid, ql, qr), query(node->r, mid, nr, ql, qr));
    }

    void set(ll idx, S x) {
        set(root, L, R, idx, x);
    }

    bool contains(ll idx) const{
        return contains(root, L, R, idx);
    }

    S prod(ll l, ll r) const {
        return query(root, L, R, l, r);
    }

    S all_prod() const{
        return root? root->val: e();
    }

    S get(ll idx) const{
        return query(root, L, R, idx, idx+1);
    }

    template<class G>
    ll max_right(ll l, G f) const {
        S sm = e();
        return max_right(root, L, R, l, f, sm);
    }

    template<class G>
    ll min_left(ll r, G f) const {
        S sm = e();
        return min_left(root, L, R, r, f, sm);
    }

    template<class G> ll max_right(Node* node, ll nl, ll nr, ll l, G f, S& sm) const{
        if (nr <= l) return nr;
        if (!node){
            S nxt = op(sm, e());
            if (!f(nxt)) return l;
            sm = nxt;
            return nr;
        }
        if (nl >= l){
            S nxt = op(sm, node->val);
            if (f(nxt)){
                sm = nxt;
                return nr;
            }
            if (nr - nl == 1) return nl;
        }
        ll mid = (nl+nr)>>1;
        ll res = max_right(node->l, nl, mid, l, f, sm);
        if (res != mid) return res;
        return max_right(node->r, mid, nr, l, f, sm);
    }

    template<class G> ll min_left(Node* node, ll nl, ll nr, ll r, G f, S& sm) const{
        if (nl >= r) return nl;
        if (!node){
            S nxt = op(e(), sm);
            if (!f(nxt)) return r;
            sm = nxt;
            return nl;
        }
        if (nr <= r){
            S nxt = op(node->val, sm);
            if (f(nxt)){
                sm = nxt;
                return nl;
            }
            if (nr-nl == 1) return nr;
        }
        ll mid = (nl+nr)>>1;
        ll res = min_left(node->l, nl, mid, r, f, sm);
        if (res != mid) return res;
        return min_left(node->r, mid, nr, r, f, sm);
    }
};
