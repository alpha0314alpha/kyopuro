template<typename T> class dynamic_segtree{
private:
    struct Node{
        T val;
        Node *l, *r;
        Node(T v) : val(v), l(nullptr), r(nullptr) {}
    };

    Node* root;
    ll L, R;
    function<T(T, T)> op;
    function<T()> e;
public:
    dynamic_segtree(ll L, ll R, function<T(T,T)> op, function<T()> e) : L(L), R(R), op(op), e(e), root(nullptr) {}

    void set(ll pos, T x){
        if (pos < L || pos >= R) return;
        if (!root) root = new Node(e());
        Node* node = root;
        ll l = L, r = R;
        vector<Node*> path;
        while (true){
            path.push_back(node);
            if (r-l == 1) break;
            ll mid = (l+r)/2;
            if (pos < mid){
                if (!node->l) node->l = new Node(e());
                node = node->l;
                r = mid;
            }
            else{
                if (!node->r) node->r = new Node(e());
                node = node->r;
                l = mid;
            }
        }
        node->val = x;
        for (int i = (int)path.size()-2; i >= 0; i--){
            Node* cur = path[i];
            T lv = cur->l? cur->l->val: e();
            T rv = cur->r? cur->r->val: e();
            cur->val = op(lv, rv);
        }
    }

    T get(ll pos) const{
        if (pos < L || pos >= R) return e();
        if (!root) return e();
        Node* node = root;
        ll l = L, r = R;
        while (node){
            if (r-l == 1) return node->val;
            ll mid = (l+r)/2;
            if (pos < mid) node = node->l, r = mid;
            else node = node->r, l = mid;
        }
        return e();
    }

    T prod(ll ql, ll qr) const{
        if (qr <= L || R <= ql) return e();
        T res = e();
        stack<tuple<Node*, ll, ll>> st;
        st.emplace(root, L, R);
        while (!st.empty()) {
            auto [node, l, r] = st.top();
            st.pop();
            if (!node || r <= ql || qr <= l) continue;
            if (ql <= l && r <= qr){
                res = op(res, node->val);
                continue;
            }
            ll mid = (l+r)/2;
            st.emplace(node->l, l, mid);
            st.emplace(node->r, mid, r);
        }
        return res;
    }
};
