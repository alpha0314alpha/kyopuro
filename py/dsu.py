class dsu:
    def __init__(self, n):
        self.parent = list(range(n))
        self.sz = [1]*n

    def root(self, x):
        if self.parent[x] == x:
            return x
        self.parent[x] = self.root(self.parent[x])
        return self.parent[x]

    def merge(self, x, y):
        x = self.root(x)
        y = self.root(y)
        if x == y:
            return
        if self.sz[x] < self.sz[y]:
            x, y = y, x
        self.parent[y] = x
        self.sz[x] += self.sz[y]

    def same(self, x, y):
        return self.root(x) == self.root(y)

    def size(self, x):
        return self.sz[self.root(x)]