class dsu{
private:
    vector<int> parent;
    vector<int> sz;
public:
    dsu(int n){
        parent.resize(n);
        sz.assign(n, 1);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int root(int x){
        if (parent[x] == x) return x;
        return parent[x] = root(parent[x]);
    }

    void merge(int x, int y){
        x = root(x);
        y = root(y);
        if (x == y) return;

        if (sz[x] < sz[y]) swap(x, y);
        parent[y] = x;
        sz[x] += sz[y];
    }

    bool same(int x, int y){
        return root(x) == root(y);
    }

    int size(int x){
        return sz[root(x)];
    }
};