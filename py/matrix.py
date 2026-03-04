class matrix:
    def __init__(self, sz, mod, val=0):
        self.sz = sz
        self.mod = mod
        self.A = [[val % mod for _ in range(sz)] for _ in range(sz)]

    def __getitem__(self, i):
        return self.A[i]

    def size(self):
        return self.sz

    @staticmethod
    def identity(n, mod):
        I = matrix(n, mod)
        for i in range(n):
            I[i][i] = 1
        return I

    def __add__(self, other):
        assert self.sz == other.sz and self.mod == other.mod
        C = matrix(self.sz, self.mod)
        for i in range(self.sz):
            for j in range(self.sz):
                C[i][j] = (self[i][j] + other[i][j]) % self.mod
        return C

    def __iadd__(self, other):
        assert self.sz == other.sz and self.mod == other.mod
        for i in range(self.sz):
            for j in range(self.sz):
                self[i][j] = (self[i][j] + other[i][j]) % self.mod
        return self

    def __sub__(self, other):
        assert self.sz == other.sz and self.mod == other.mod
        C = matrix(self.sz, self.mod)
        for i in range(self.sz):
            for j in range(self.sz):
                C[i][j] = (self[i][j]-other[i][j])%self.mod
        return C

    def __isub__(self, other):
        assert self.sz == other.sz and self.mod == other.mod
        for i in range(self.sz):
            for j in range(self.sz):
                self[i][j] = (self[i][j]-other[i][j])%self.mod
        return self

    def __mul__(self, other):
        assert self.sz == other.sz and self.mod == other.mod
        C = matrix(self.sz, self.mod)
        for i in range(self.sz):
            for k in range(self.sz):
                if self[i][k] == 0:
                    continue
                aik = self[i][k]
                for j in range(self.sz):
                    C[i][j] = (C[i][j]+aik*other[k][j])%self.mod
        return C

    def __imul__(self, other):
        self.A = (self*other).A
        return self

    def pow(self, n):
        base = self
        R = matrix.identity(self.sz, self.mod)
        while n > 0:
            if n&1:
                R *= base
            base *= base
            n >>= 1
        return R

    def __repr__(self):
        return "\n".join(" ".join(map(str, row)) for row in self.A)