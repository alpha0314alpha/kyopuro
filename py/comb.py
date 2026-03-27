class comb:
    def __init__(self, n, m):
        self.mod = m
        self.size = n
        self.fact = [0]*(self.size+1)
        self.invfact = [0]*(self.size+1)
        for i in range(self.size+1):
            if i == 0:
                self.fact[i] = 1
            else:
                self.fact[i] = self.fact[i-1]*i%self.mod
        self.invfact[n] = pow(self.fact[n], self.mod-2, self.mod)
        for i in range(self.size, 0, -1):
            self.invfact[i-1] = self.invfact[i]*i%self.mod

    def factrial(self, n):
        if n > self.size:
            return -1
        return self.fact[n]
    
    def npr(self, n, r):
        if r < 0 or n < r or n > self.size:
            return 0
        return self.fact[n]*self.invfact[n-r]%self.mod
    
    def ncr(self, n, r):
        if r < 0 or n < r or n > self.size:
            return 0
        return self.fact[n]*self.invfact[r]%self.mod*self.invfact[n-r]%self.mod

    def nhr(self, n, r):
        if n <= 0 or r < 0 or n+r-1 > self.size:
            return 0
        return self.ncr(n+r-1, r)
