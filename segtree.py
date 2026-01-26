from typing import Callable, List

class segtree:
    def __init__(self, A: List, e, op: Callable):
        self.n = len(A)
        self.e = e
        self.op = op
        self.seg = [e] * (4 * self.n)
        self._build(1, 0, self.n, A)

    def _build(self, node, l, r, A):
        if r - l == 1:
            self.seg[node] = A[l]
            return
        mid = (l + r) // 2
        self._build(node * 2, l, mid, A)
        self._build(node * 2 + 1, mid, r, A)
        self.seg[node] = self.op(self.seg[node * 2], self.seg[node * 2 + 1])

    def _query(self, node, l, r, ql, qr):
        if qr <= l or r <= ql:
            return self.e
        if ql <= l and r <= qr:
            return self.seg[node]
        mid = (l + r) // 2
        return self.op(
            self._query(node * 2, l, mid, ql, qr),
            self._query(node * 2 + 1, mid, r, ql, qr)
        )

    def query(self, l, r):
        return self._query(1, 0, self.n, l, r)

    def _update(self, node, l, r, idx, val):
        if r - l == 1:
            self.seg[node] = val
            return
        mid = (l + r) // 2
        if idx < mid:
            self._update(node * 2, l, mid, idx, val)
        else:
            self._update(node * 2 + 1, mid, r, idx, val)
        self.seg[node] = self.op(self.seg[node * 2], self.seg[node * 2 + 1])

    def update(self, idx, val):
        self._update(1, 0, self.n, idx, val)

    def _get(self, node, l, r, idx):
        if r - l == 1:
            return self.seg[node]
        mid = (l + r) // 2
        if idx < mid:
            return self._get(node * 2, l, mid, idx)
        else:
            return self._get(node * 2 + 1, mid, r, idx)

    def get(self, idx):
        return self._get(1, 0, self.n, idx)

    def add(self, idx, val):
        self.update(idx, self.get(idx) + val)

    def _find_first(self, node, nl, nr, l, val):
        if nr <= l:
            return -1
        if self.seg[node] < val:
            return -1
        if nr - nl == 1:
            return nl

        mid = (nl + nr) // 2

        if l < mid:
            res = self._find_first(node * 2, nl, mid, l, val)
            if res != -1:
                return res
            return self._find_first(node * 2 + 1, mid, nr, l, val)
        else:
            return self._find_first(node * 2 + 1, mid, nr, l, val)

    def find_first(self, l, val):
        return self._find_first(1, 0, self.n, l, val)
