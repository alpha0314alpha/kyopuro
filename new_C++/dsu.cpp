class dsu{
private:
    int _n;
    vector<int> sz;
public:
    dsu(int n) : _n(n), sz(n, -1) {}

    bool merge(int x, int y){
        assert(0 <= x && x < _n);
        assert(0 <= y && y < _n);
        x = root(x);
        y = root(y);
        if (x == y) return false;
        if (-sz[x] < -sz[y]) swap(x, y);
        sz[x] += sz[y];
        sz[y] = x;
        return true;
    }

    bool same(int x, int y){
        assert(0 <= x && x < _n);
        assert(0 <= y && y < _n);
        return root(x) == root(y);
    }

    int root(int x){
        assert(0 <= x && x < _n);
        if (sz[x] < 0) return x;
        sz[x] = root(sz[x]);
        return sz[x];
    }

    int size(int x){
        assert(0 <= x && x < _n);
        return -sz[root(x)];
    }
};
