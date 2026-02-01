from typing import List, Callable, TypeVar

T = TypeVar('T')

class segtree:
    def __init__(self, A: List[T], e: T, op: Callable[[T, T], T]):
        self.n = len(A)
        self.e = e
        self.op = op
        self.seg = [e] * (4 * self.n)
        self._build(1, 0, self.n, A)

    def _build(self, node: int, l: int, r: int, A: List[T]):
        if r - l == 1:
            self.seg[node] = A[l]
            return
        mid = (l + r) // 2
        self._build(node * 2, l, mid, A)
        self._build(node * 2 + 1, mid, r, A)
        self.seg[node] = self.op(self.seg[node * 2], self.seg[node * 2 + 1])

    def _query(self, node: int, l: int, r: int, ql: int, qr: int) -> T:
        if qr <= l or r <= ql:
            return self.e
        if ql <= l and r <= qr:
            return self.seg[node]
        mid = (l + r) // 2
        return self.op(self._query(node * 2, l, mid, ql, qr),
                       self._query(node * 2 + 1, mid, r, ql, qr))

    def query(self, l: int, r: int) -> T:
        return self._query(1, 0, self.n, l, r)

    def _update(self, node: int, l: int, r: int, idx: int, val: T):
        if r - l == 1:
            self.seg[node] = val
            return
        mid = (l + r) // 2
        if idx < mid:
            self._update(node * 2, l, mid, idx, val)
        else:
            self._update(node * 2 + 1, mid, r, idx, val)
        self.seg[node] = self.op(self.seg[node * 2], self.seg[node * 2 + 1])

    def update(self, idx: int, val: T):
        self._update(1, 0, self.n, idx, val)

    def get(self, idx: int) -> T:
        node = 1
        l = 0
        r = self.n
        while r - l > 1:
            mid = (l + r) // 2
            if idx < mid:
                node = node * 2
                r = mid
            else:
                node = node * 2 + 1
                l = mid
        return self.seg[node]

    def add(self, idx: int, val: T):
        self.update(idx, self.get(idx) + val)

    def _find_first(self, node: int, nl: int, nr: int, l: int, val: T) -> int:
        if nr <= l or self.seg[node] < val:
            return -1
        if nr - nl == 1:
            return nl
        mid = (nl + nr) // 2
        if l < mid:
            res = self._find_first(node * 2, nl, mid, l, val)
            if res != -1:
                return res
        return self._find_first(node * 2 + 1, mid, nr, l, val)

    def find_first(self, l: int, val: T) -> int:
        return self._find_first(1, 0, self.n, l, val)

    def _find_last(self, node: int, nl: int, nr: int, r: int, val: T) -> int:
        if r <= nl or self.seg[node] <= val:
            return -1
        if nr - nl == 1:
            return nl
        mid = (nl + nr) // 2
        res = self._find_last(node * 2 + 1, mid, nr, r, val)
        if res != -1:
            return res
        return self._find_last(node * 2, nl, mid, r, val)

    def find_last(self, r: int, val: T) -> int:
        return self._find_last(1, 0, self.n, r, val)
