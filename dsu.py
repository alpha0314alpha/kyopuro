class dsu:
    def __init__(self, N: int):
        self.parent = list(range(N))
        self.sz = [1]*N

    def root(self, x: int):
        if self.parent[x] == x:
            return x
        self.parent[x] = self.root(self.parent[x])
        return self.parent[x]

    def merge(self, x: int, y: int):
        x = self.root(x)
        y = self.root(y)
        if x != y:
            if self.sz[x] < self.sz[y]:
                x, y = y, x
            self.parent[y] = x
            self.sz[x] += self.sz[y]

    def same(self, x: int, y: int):
        return self.root(x) == self.root(y)

    def size(self, x: int):
        return self.sz[self.root(x)]
