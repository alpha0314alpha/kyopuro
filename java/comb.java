public class comb{
    int size;
    long mod;
    long[] fact, invfact;

    long modpow(long a, long e){
        long res = 1;
        while (e > 0){
            if ((e&1) == 1) res = res*a%mod;
            a = a*a%mod;
            e >>= 1;
        }
        return res;
    }

    public comb(int n, long m){
        this.size = n;
        this.mod = m;
        this.fact = new long[n+1];
        this.invfact = new long[n+1];
        fact[0] = 1;
        for (int i = 1; i <= n; i++) fact[i] = fact[i-1]*i%mod;
        invfact[n] = modpow(fact[n], mod-2);
        for (int i = n; i >= 1; i--){
            invfact[i - 1] = invfact[i]*i%mod;
        }
    }

    long factorial(int n){
        if (n > size) return -1;
        return fact[n];
    }

    long npr(int n, int r){
        if (r < 0 || n < r || n > size) return 0;
        return fact[n]*invfact[n-r]%mod;
    }

    long ncr(int n, int r){
        if (r < 0 || n < r || n > size) return 0;
        return fact[n]*invfact[r]%mod*invfact[n-r]%mod;
    }

    long nhr(int n, int r){
        if (n <= 0 || r < 0 || n+r-1 > size) return 0;
        return ncr(n+r-1, r);
    }
}
