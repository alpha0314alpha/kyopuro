class dsu{
    private int[] parent;
    private int[] sz;

    public dsu(int n){
        parent = new int[n];
        sz = new int[n];
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            sz[i] = 1;
        }
    }

    public int root(int x) {
        if (parent[x] == x) return x;
        return parent[x] = root(parent[x]);
    }

    public void merge(int x, int y){
        x = root(x);
        y = root(y);
        if (x == y) return;
        if (sz[x] < sz[y]) {
            int tmp = x;
            x = y;
            y = tmp;
        }
        parent[y] = x;
        sz[x] += sz[y];
    }

    public boolean same(int x, int y){
        return root(x) == root(y);
    }

    public int size(int x){
        return sz[root(x)];
    }
}