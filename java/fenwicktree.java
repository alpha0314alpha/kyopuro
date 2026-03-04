class Fenwicktree{
    private int n;
    private long[] bit;
    private long[] arr;

    public Fenwicktree(int n){
        this.n = n;
        bit = new long[n];
        arr = new long[n];
    }

    public void add(int i, long x){
        arr[i] += x;
        while (i < n){
            bit[i] += x;
            i |= i+1;
        }
    }

    public void update(int i, long val){
        long diff = val-arr[i];
        add(i, diff);
    }

    public long get(int i){
        return arr[i];
    }
    
    public long sum(int i){
        long res = 0;
        while (i >= 0){
            res += bit[i];
            i = (i&(i+1))-1;
        }
        return res;
    }

    public long rangeSum(int l, int r){
        if (l > r) return 0;
        return sum(r)-(l > 0? sum(l-1): 0);
    }
}
