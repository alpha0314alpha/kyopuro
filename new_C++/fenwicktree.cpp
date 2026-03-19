#include <bits/stdc++.h>
using namespace std;

template<typename T> class fenwicktree{
private:
    int _n;
    vector<T> bit;
public:
    fenwicktree(int n) : _n(n), bit(n, T()) {}

    void add(int p, T x){
        assert(0 <= p && p < _n);
        p++;
        while (p <= _n){
            bit[p-1] += x;
            p += p&-p;
        }
    }

    T sum(int l, int r){
        assert(0 <= l && l <= r && r <= _n);
        return _sum(r)-_sum(l);
    }

    T _sum(int p){
        T res = 0;
        while (p > 0){
            res += bit[p-1];
            p -= p&-p;
        }
        return res;
    }
};
