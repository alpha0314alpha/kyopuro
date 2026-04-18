template<typename T, typename E> class godtree{
private:
    struct Node{
        T val, sum;
        E lazy;
        bool rev;
        int sz, pri;
        Node *l, *r;

        Node(T v, E id) : val(v), sum(v), lazy(id), rev(false), sz(1), pri(rng()), l(nullptr), r(nullptr) {}
    };

    using F = function<T(T, T)>;
    using G = function<T(T, E, int)>;
    using H = function<E(E, E)>;
    using I = function<T()>;
    using J = function<E()>;

    F op;
    G mapping;
    H composition;
    I e;
    J id;
    Node* root = nullptr;
public:
    godtree(F op, I e, G mapping, H composition, J id) : op(op), mapping(mapping), composition(composition), e(e), id(id) {}

    int sz(Node* t){ return t? t->sz: 0; }
    T sum(Node* t){ return t? t->sum: e(); }
    Node* new_node(T v){ return new Node(v, id()); }
    int size(){ return sz(root); }

    T get(Node* t, int k){
        push(t);
        if (k < sz(t->l)) return get(t->l, k);
        if (k == sz(t->l)) return t->val;
        return get(t->r, k - sz(t->l) - 1);
    }

    T get(int pos){
        return get(root, pos);
    }

    Node* update(Node* t){
        if (!t) return t;
        t->sz = 1 + sz(t->l)+sz(t->r);
        t->sum = op(op(sum(t->l), t->val), sum(t->r));
        return t;
    }

    void apply(Node* t, E f){
        if (!t) return;
        t->val = mapping(t->val, f, 1);
        t->sum = mapping(t->sum, f, t->sz);
        t->lazy = composition(t->lazy, f);
    }

    void push(Node* t){
        if (!t) return;
        if (t->rev){
            swap(t->l, t->r);
            if (t->l) t->l->rev ^= 1;
            if (t->r) t->r->rev ^= 1;
            t->rev = false;
        }
        if (t->lazy != id()){
            apply(t->l, t->lazy);
            apply(t->r, t->lazy);
            t->lazy = id();
        }
    }

    pair<Node*, Node*> split(Node* t, int k){
        if (!t) return {nullptr, nullptr};
        push(t);
        if (k <= sz(t->l)){
            auto [l, r] = split(t->l, k);
            t->l = r;
            return {l, update(t)};
        }
        else{
            auto [l, r] = split(t->r, k - sz(t->l)-1);
            t->r = l;
            return {update(t), r};
        }
    }

    Node* merge(Node* l, Node* r){
        if (!l || !r) return l? l: r;
        if (l->pri > r->pri){
            push(l);
            l->r = merge(l->r, r);
            return update(l);
        }
        else{
            push(r);
            r->l = merge(l, r->l);
            return update(r);
        }
    }

    void insert(int pos, T v){
        auto [a, b] = split(root, pos);
        root = merge(merge(a, new_node(v)), b);
    }

    void erase(int pos){
        auto [a, b] = split(root, pos);
        auto [c, d] = split(b, 1);
        root = merge(a, d);
    }

    void reverse(int l, int r){
        auto [a, b] = split(root, l);
        auto [c, d] = split(b, r-l);
        if (c) c->rev ^= 1;
        root = merge(a, merge(c, d));
    }

    void apply(int l, int r, E f){
        auto [a, b] = split(root, l);
        auto [c, d] = split(b, r-l);
        apply(c, f);
        root = merge(a, merge(c, d));
    }

    T query(int l, int r){
        auto [a, b] = split(root, l);
        auto [c, d] = split(b, r-l);
        T res = sum(c);
        root = merge(a, merge(c, d));
        return res;
    }
};
