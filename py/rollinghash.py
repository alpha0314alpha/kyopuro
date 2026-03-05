class rollinghash:
    def __init__(self, S):
        self.mod = 1000000007
        self.base = 100
        self.N = len(S)
        self.power = [1]*(self.N+1)
        self.hash = [0]*(self.N+1)
        for i in range(self.N):
            self.power[i+1] = (self.power[i]*self.base)%self.mod
            self.hash[i+1] = (self.hash[i]*self.base+ord(S[i]))%self.mod
    
    def get(self, l, r):
        res = self.hash[r]-(self.hash[l]*self.power[r-l])%self.mod
        if res < 0:
            res += self.mod
        return res