template<typename S, typename F> class lazy_segtree{
private:
    int _n, size, log;
    vector<S> d;
    vector<F> lz;
    function<S(S, S)> op;
    function<S()> e;
    function<S(F, S)> mapping;
    function<F(F, F)> composition;
    function<F()> id;

    void update(int k){
        d[k] = op(d[2*k], d[2*k+1]);
    }

    void all_apply(int k, F f){
        d[k] = mapping(f, d[k]);
        if(k < size) lz[k] = composition(f, lz[k]);
    }

    void push(int k){
        all_apply(2*k, lz[k]);
        all_apply(2*k+1, lz[k]);
        lz[k] = id();
    }
public:
    lazy_segtree(int n, function<S(S,S)> op, function<S()> e, function<S(F,S)> mapping, function<F(F,F)> composition, function<F()> id) : _n(n), op(op), e(e), mapping(mapping), composition(composition), id(id){
        size = 1;
        log = 0;
        while(size < n) size <<= 1, log++;
        d.assign(2*size, e());
        lz.assign(size, id());
    }

    void set(int p, S x){
        d[p+size] += x;
    }

    S get(int p){
        p += size;
        for(int i = log; i >= 1; i--) push(p>>i);
        return d[p];
    }

    void build(){
        for(int i = size-1;i >= 1; i--) update(i);
    }

    S prod(int l, int r){
        l += size, r += size;
        for(int i = log; i >= 1; i--){
            if(((l>>i)<<i)!=l) push(l>>i);
            if(((r>>i)<<i)!=r) push((r-1)>>i);
        }
        S sml = e(), smr = e();
        while(l < r){
            if(l&1) sml = op(sml, d[l++]);
            if(r&1) smr = op(d[--r], smr);
            l >>= 1, r >>= 1;
        }
        return op(sml, smr);
    }

    void apply(int l, int r, F f){
        l += size, r += size;
        int l2 = l, r2 = r;
        for(int i = log; i >= 1; i--){
            if(((l>>i)<<i)!=l) push(l>>i);
            if(((r>>i)<<i)!=r) push((r-1)>>i);
        }
        while(l < r){
            if(l&1) all_apply(l++, f);
            if(r&1) all_apply(--r, f);
            l >>= 1;
            r >>= 1;
        }
        l = l2, r = r2;
        for(int i = 1; i <= log; i++){
            if(((l>>i)<<i)!=l) update(l>>i);
            if(((r>>i)<<i)!=r) update((r-1)>>i);
        }
    }
};