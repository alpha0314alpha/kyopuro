import math

class sim:
    class arr:
        def __init__(self, n):
            self.sz = n
            self.sum = 0
            self.pref = [0]*n

    def __init__(self, n):
        self.N = n
        self.block = int(math.sqrt(n))+1
        self.table = []
        num_blocks = (self.N+self.block-1)//self.block
        self.block_pref = [0]*num_blocks
        for i in range(num_blocks):
            sz = min(self.block, self.N-i*self.block)
            self.table.append(sim.arr(sz))

    def add(self, i, x):
        y, z = i//self.block, i%self.block
        self.table[y].sum += x
        for j in range(z, self.table[y].sz):
            self.table[y].pref[j] += x
        for k in range(y, len(self.block_pref)):
            self.block_pref[k] += x

    def _sum(self, r):
        if r < 0:
            return 0
        y, z = r//self.block, r%self.block
        res = self.table[y].pref[z]
        if y > 0:
            res += self.block_pref[y-1]
        return res
    
    def sum(self, l, r):
        return self._sum(r-1)-self._sum(l-1)
