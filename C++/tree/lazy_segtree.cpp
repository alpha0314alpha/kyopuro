template<typename S, typename F> class lazy_segtree{
private:
    int _n, size, log;
    vector<S> d;
    vector<F> lz;
    // function<S(S, S)> op;
    // function<S()> e;
    // function<S(F, S)> mapping;
    // function<F(F, F)> composition;
    // function<F()> id;

    S (*op)(S, S);
    S (*e)();
    S (*mapping)(F, S);
    F (*composition)(F, F);
    F (*id)();

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
    // lazy_segtree(int n, function<S(S,S)> op, function<S()> e, function<S(F,S)> mapping, function<F(F,F)> composition, function<F()> id) : _n(n), op(op), e(e), mapping(mapping), composition(composition), id(id){
    lazy_segtree(int n, S (*op)(S, S), S (*e)(), S (*mapping)(F, S), F(*composition)(F, F), F (*id)()) : _n(n), op(op), e(e), mapping(mapping), composition(composition), id(id){
        size = 1;
        log = 0;
        while(size < n) size <<= 1, log++;
        d.assign(2*size, e());
        lz.assign(size, id());
    }

    S get(int p){
        p += size;
        for(int i = log; i >= 1; i--) push(p>>i);
        return d[p];
    }

    void set(int p, S x){
        p += size;
        for(int i = log; i >= 1; i--) push(p>>i);
        d[p] = x;
        for(int i = 1; i <= log; i++) update(p>>i);
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

    template<class G> int max_right(int l, G g){
        if(l == _n) return _n;
        l += size;
        for(int i = log; i >= 1; i--) push(l>>i);
        S sm = e();
        do{
            while((l&1) == 0) l >>= 1;
            if(!g(op(sm, d[l]))){
                while(l < size){
                    push(l);
                    l <<= 1;
                    if(g(op(sm, d[l]))){
                        sm = op(sm, d[l]);
                        l++;
                    }
                }
                return l - size;
            }
            sm = op(sm, d[l]);
            l++;
        }while((l&-l) != l);
        return _n;
    }

    template<class G> int min_left(int r, G g){
        if(r == 0) return 0;
        r += size;
        for(int i = log; i >= 1; i--) push((r-1)>>i);
        S sm = e();
        do{
            r--;
            while(r > 1 && (r&1)) r >>= 1;
            if(!g(op(d[r], sm))){
                while(r < size){
                    push(r);
                    r = 2*r + 1;
                    if(g(op(d[r], sm))){
                        sm = op(d[r], sm);
                        r--;
                    }
                }
                return r+1-size;
            }
            sm = op(d[r], sm);
        }while((r&-r) != r);
        return 0;
    }
};
