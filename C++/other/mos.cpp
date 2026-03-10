class mos{
private:
    struct query{
        int l, r, idx;
    };
    int n, block;
    vector<query> qs;
public:

    mos(int n) : n(n){
        block = sqrt(n);
    }

    void add_query(int l, int r){
        qs.push_back({l, r, (int)qs.size()});
    }

    template<class ADD, class REMOVE, class OUTPUT>
    void run(ADD add, REMOVE remove, OUTPUT output){
        sort(qs.begin(), qs.end(), [&](query a, query b){
            int ablock = a.l/block, bblock = b.l/block;
            if (ablock != bblock) return ablock < bblock;
            return a.r < b.r;
        });
        int l = 0, r = 0;
        for (auto& q : qs){
            while (l > q.l) add(--l);
            while (r < q.r) add(r++);
            while (l < q.l) remove(l++);
            while (r > q.r) remove(--r);
            output(q.idx);
        }
    }
};
