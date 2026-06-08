class binary_trie:
    class Node:
        __slots__ = ("one", "zero", "count")
        def __init__(self):

            self.one = -1
            self.zero = -1
            self.count = 0

    def __init__(self, log=60):
        self.LOG = log
        self.T = [self.Node()]

    def _new_node(self):
        self.T.append(self.Node())
        return len(self.T)-1

    def size(self):
        return self.T[0].count

    def count(self, x):
        v = 0
        for i in range(self.LOG-1, -1, -1):
            f = (x>>i)&1
            nxt = self.T[v].one if f else self.T[v].zero
            if nxt == -1:
                return 0
            v = nxt
        return self.T[v].count

    def insert(self, x, k=1):
        v = 0
        self.T[v].count += k
        for i in range(self.LOG-1, -1, -1):
            f = (x>>i)&1
            if f:
                if self.T[v].one == -1:
                    self.T[v].one = self._new_node()
                v = self.T[v].one
            else:
                if self.T[v].zero == -1:
                    self.T[v].zero = self._new_node()
                v = self.T[v].zero
            self.T[v].count += k

    def erase(self, x, k=1):
        if self.count(x) < k:
            return False
        v = 0
        self.T[v].count -= k
        for i in range(self.LOG-1, -1, -1):
            f = (x>>i)&1
            v = self.T[v].one if f else self.T[v].zero
            self.T[v].count -= k
        return True

    def kth(self, k):
        assert 0 <= k < self.size()
        v = 0
        x = 0
        for i in range(self.LOG-1, -1, -1):
            lc = 0
            if self.T[v].zero != -1:
                lc = self.T[self.T[v].zero].count
            if k < lc:
                v = self.T[v].zero
            else:
                k -= lc
                x |= 1<<i
                v = self.T[v].one
        return x

    def count_less(self, x):
        v = 0
        res = 0
        for i in range(self.LOG-1, -1, -1):
            if v == -1:
                break
            f = (x>>i)&1
            if f:
                u = self.T[v].zero
                if u != -1:
                    res += self.T[u].count
            v = self.T[v].one if f else self.T[v].zero
        return res

    def min_xor(self, x):
        assert self.size() > 0
        v = 0
        res = 0
        for i in range(self.LOG-1, -1, -1):
            f = (x>>i)&1
            u = self.T[v].one if f else self.T[v].zero
            if u != -1 and self.T[u].count > 0:
                v = u
            else:
                res |= 1<<i
                v = self.T[v].zero if f else self.T[v].one
        return res

    def max_xor(self, x):
        assert self.size() > 0
        v = 0
        res = 0
        for i in range(self.LOG-1, -1, -1):
            f = ((x>>i)&1)^1
            u = self.T[v].one if f else self.T[v].zero
            if u != -1 and self.T[u].count > 0:
                res |= 1<<i
                v = u
            else:
                v = self.T[v].zero if f else self.T[v].one
        return res
