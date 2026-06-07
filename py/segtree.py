class segtree:
    def __init__(self, arg, op, e):
        self.op = op
        self.e = e
        if isinstance(arg, list):
            A = arg
            self.n = len(A)
            self.size = 1
            while self.size < self.n:
                self.size <<= 1
            self.seg = [e]*(2*self.size)
            for i in range(self.n):
                self.seg[self.size+i] = A[i]
            for i in range(self.size-1, 0, -1):
                self.seg[i] = op(self.seg[i<<1], self.seg[i<<1|1])
        else:
            self.n = arg
            self.size = 1
            while self.size < self.n:
                self.size <<= 1
            self.seg = [e]*(2*self.size)
            for i in range(self.size-1, 0, -1):
                self.seg[i] = op(self.seg[i<<1], self.seg[i<<1|1])

    def set(self, i, val):
        i += self.size
        self.seg[i] = val
        i >>= 1
        while i:
            self.seg[i] = self.op(self.seg[i<<1], self.seg[i<<1|1])
            i >>= 1

    def all_prod(self):
        return self.seg[1]

    def prod(self, l, r):
        L = self.e
        R = self.e
        l += self.size
        r += self.size
        while l < r:
            if l&1:
                L = self.op(L, self.seg[l])
                l += 1
            if r&1:
                r -= 1
                R = self.op(self.seg[r], R)
            l >>= 1
            r >>= 1
        return self.op(L, R)

    def get(self, i):
        return self.seg[self.size+i]

    def __getitem__(self, i):
        return self.seg[self.size+i]

    def add(self, i, val):
        self.set(i, self.get(i)+val)

    def max_right(self, l, f):
        if l == self.n:
            return self.n
        l += self.size
        sm = self.e
        while True:
            while (l&1) == 0:
                l >>= 1
            if not f(self.op(sm, self.seg[l])):
                while l < self.size:
                    l <<= 1
                    if f(self.op(sm, self.seg[l])):
                        sm = self.op(sm, self.seg[l])
                        l += 1
                return l-self.size
            sm = self.op(sm, self.seg[l])
            l += 1
            if (l&-l) == l:
                break
        return self.n

    def min_left(self, r, f):
        if r == 0:
            return 0
        r += self.size
        sm = self.e
        while True:
            r -= 1
            while r > 1 and (r&1):
                r >>= 1
            if not f(self.op(self.seg[r], sm)):
                while r < self.size:
                    r = r<<1|1
                    if f(self.op(self.seg[r], sm)):
                        sm = self.op(self.seg[r], sm)
                        r -= 1
                return r+1-self.size
            sm = self.op(self.seg[r], sm)
            if (r&-r) == r:
                break
            return 0
