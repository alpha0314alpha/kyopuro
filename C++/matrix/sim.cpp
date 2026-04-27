template<typename T> struct sim{
    struct arr{
        int sz;
        T sum;
        vector<T> pref;
        arr(int n) : sz(n), sum(T()), pref(n, T()){}
    };

    int N, block;
    vector<arr> table;
    vector<T> block_pref;

    sim(int n) : N(n), block(sqrt(n)+1){
        int num_blocks = (N+block-1)/block;
        for (int i = 0; i < num_blocks; i++){
            int sz = min(block, N-i*block);
            table.emplace_back(sz);
        }
        block_pref.assign(num_blocks, T());
    }

    void add(int i, T x){
        int y = i/block, z = i%block;
        table[y].sum += x;
        for (int j = z; j < table[y].sz; j++) table[y].pref[j] += x;
        for (int k = y; k < (int)block_pref.size(); k++) block_pref[k] += x;
    }

    T _sum(int r){
        if (r < 0) return T();
        int y = r/block, z = r%block;
        T res = table[y].pref[z];
        if (y > 0) res += block_pref[y-1];
        return res;
    }

    T sum(int l, int r){
        return _sum(r-1) - _sum(l-1);
    }
};
