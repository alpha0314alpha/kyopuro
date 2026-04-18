struct persistent_dsu{
    tree::persistent_segtree<int> seg;
    int n;

    persistent_dsu(int n) : seg(n, -1, [](int a, int b){ return 0; }), n(n) {}

    int root(int v, int x){
        while (true){
            int p = seg.get(v, x);
            if (p < 0) return x;
            x = p;
        }
    }

    int merge(int v, int a, int b){
        a = root(v, a);
        b = root(v, b);
        if (a == b) return v;
        int sa = -seg.get(v, a);
        int sb = -seg.get(v, b);
        if (sa < sb) swap(a, b);
        int nv = seg.set(v, a, -(sa + sb));
        nv = seg.set(nv, b, a);
        return nv;
    }

    bool same(int v, int a, int b){
        return root(v, a) == root(v, b);
    }

    int size(int v, int x){
        x = root(v, x);
        return -seg.get(v, x);
    }
};
