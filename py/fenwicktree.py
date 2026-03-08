class fenwicktree:
    def __init__(self, n):
        self.n = n
        self.bit = [0]*n
        self.a = [0]*n
    
    def add(self, i, x):
        while i < self.n:
            self.bit[i] += x
            i |= i+1
    
    def set(self, i, x):
        self.add(i, x-self.a[i])
        self.a[i] = x
    
    def get(self, i):
        return self.a[i]
    
    def sum(self, i):
        res = 0
        while i >= 0:
            res += self.bit[i]
            i = (i&(i+1))-1
        return res
    
    def range_sum(self, l, r):
        if l > r:
            return 0
        return self.sum(r)-(self.sum(l-1) if l else 0)