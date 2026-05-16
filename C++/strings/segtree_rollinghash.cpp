struct segtree_rollinghash{
    struct node {
        array<ll, 5> h;
        int len;
    };

    template<typename T> using segtree = tree::segtree<T>;
    const array<ll, 5> mod = {998244353, 1000000007, 1000000009, 1000000021, 1000000033};
    const ll base = 100;
    vector<array<ll, 5>> power;
    function<node(node, node)> op;
    node e = {{0, 0, 0, 0, 0}, 0};
    segtree<node> seg;

    segtree_rollinghash(const string& s) : power(s.size()+1), op(nullptr), seg(build_init(s), [&](node a, node b){ return a; }, e){
        int n = s.size();
        build_power(n);
        op = [&](node a, node b){
            if (a.len == 0) return b;
            if (b.len == 0) return a;
            node res;
            res.len = a.len+b.len;
            for (int i = 0; i < 5; i++){
                res.h[i] = (a.h[i]*power[b.len][i]+b.h[i])%mod[i];
            }
            return res;
        };
        seg = segtree<node>(build_init(s), op, e);
    }

    void build_power(int n){
        power.resize(n+1);
        power[0] = {1, 1, 1, 1, 1};
        for (int i = 0; i < n; i++) for (int j = 0; j < 5; j++){
            power[i+1][j] = power[i][j]*base%mod[j];
        }
    }

    vector<node> build_init(const string& s){
        int n = s.size();
        vector<node> v(n);
        for (int i = 0; i < n; i++){
            v[i].len = 1;
            for (int j = 0; j < 5; j++) v[i].h[j] = s[i];
        }
        return v;
    }

    void set(int pos, char c){
        node x;
        x.len = 1;
        for (int j = 0; j < 5; j++) x.h[j] = c;
        seg.set(pos, x);
    }

    node get(int l, int r){
        return seg.prod(l, r);
    }
};
