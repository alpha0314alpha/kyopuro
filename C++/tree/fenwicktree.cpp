template<typename T> class fenwicktree{
private:
    int n;
    vector<T> bit, a;

public:
    fenwicktree(int n) : n(n), bit(n, T()), a(n, T()) {}

    void add(int i, T x){
        while(i < n){
            bit[i] += x;
            i |= i + 1;
        }
    }

    void set(int i, T x){
        add(i, x - a[i]);
        a[i] = x;
    }

    T get(int i) const{
        return a[i];
    }

    T sum(int i) const{
        T res = T();
        while(i >= 0){
            res += bit[i];
            i = (i&(i+1))-1;
        }
        return res;
    }

    T range_sum(int l, int r) const{
        if(l > r) return T();
        return sum(r)-(l? sum(l-1): T());
    }
};
