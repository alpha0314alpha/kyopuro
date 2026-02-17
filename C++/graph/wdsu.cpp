template<typename T> class wdsu{
private:
    vector<int> parent, rankv;
    vector<T> weight;
public:
    wdsu(int n){
        parent.resize(n);
        rankv.assign(n, 0);
        weight.assign(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int root(int x){
        if (parent[x] == x) return x;
        int r = root(parent[x]);
        weight[x] += weight[parent[x]];
        return parent[x] = r;
    }

    T potential(int x){
        root(x);
        return weight[x];
    }

    bool merge(int x, int y, T w){
        int rx = root(x), ry = root(y);
        if (rx == ry) return false;
        if (rankv[rx] < rankv[ry]){
            swap(rx, ry);
            swap(x, y);
            w = -w;
        }
        parent[ry] = rx;
        weight[ry] = weight[x]+w-weight[y];
        if (rankv[rx] == rankv[ry]) rankv[rx]++;
        return true;
    }

    T diff(int x, int y){
        return potential(y)-potential(x);
    }

    bool same(int x, int y){
        return root(x) == root(y);
    }
};