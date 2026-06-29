# from acl_cpp.convolution import convolution
# from acl_cpp.dsu import dsu
# from acl_cpp.fenwicktree import fenwick_tree as fenwicktree
# from acl_cpp.maxflow import mf_graph
# from acl_cpp.mincostflow import mcf_graph
# from acl_cpp.scc import scc_graph
# from acl_cpp.twosat import two_sat as twosat
# from acl_cpp.string import *
# from acl_cpp.math import *
# from acl_cpp.internal.math import *
# from atcoder.segtree import SegTree as segtree
# from atcoder.lazysegtree import LazySegTree as lazy_segtree

from sortedcontainers import *
from collections import *
from itertools import *
from functools import *
import heapq
import bisect
import sys
import numpy as np
import random
import math

sys.setrecursionlimit(10**8)
input = sys.stdin.readline
lb = bisect.bisect_left
ub = bisect.bisect_right
dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]
dxy = [(1, 0), (0, 1), (-1, 0), (0, -1)]
PI = math.pi
EPS = 1e-14
INF = 1<<60
MOD = 998244353
# MOD = 10**9+7

def dijkstra(G, roots):
    N = len(G)
    Q = []
    dist = [INF for _ in range(N)]
    for r in roots:
        dist[r] = 0
        heapq.heappush(Q, (0, r))
    while Q:
        d, p = heapq.heappop(Q)
        if dist[p] < d:
            continue
        for u, v in G[p]:
            if dist[u] > d+v:
                dist[u] = d+v
                heapq.heappush(Q, (dist[u], u))
    for i in range(N):
        if dist[i] == INF:
            dist[i] = -1
    return dist

def zaatu(A):
    B = list(set(sorted(A)))
    return [lb(B, A[i]) for i in range(len(A))]

def to_rle(A):
    res = []
    for x in A:
        if len(res) == 0 or res[-1][0] != x:
            res.append([x, 1])
        else:
            res[-1][1] += 1
    return res

def inversion(A):
    N, Z = len(A), zaatu(A)
    res = 0
    F = fenwicktree(N+1)
    for i in range(N-1, -1, -1):
        res += F.sum(0, Z[i])
        F.add(Z[i], 1)
    return res

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

class comb:
    def __init__(self, n, m):
        self.mod = m
        self.size = n
        self.fact = [0]*(self.size+1)
        self.invfact = [0]*(self.size+1)
        for i in range(self.size+1):
            if i == 0:
                self.fact[i] = 1
            else:
                self.fact[i] = self.fact[i-1]*i%self.mod
        self.invfact[n] = pow(self.fact[n], self.mod-2, self.mod)
        for i in range(self.size, 0, -1):
            self.invfact[i-1] = self.invfact[i]*i%self.mod
    def factrial(self, n):
        if n > self.size:
            return -1
        return self.fact[n]
    def npr(self, n, r):
        if r < 0 or n < r or n > self.size:
            return 0
        return self.fact[n]*self.invfact[n-r]%self.mod
    def ncr(self, n, r):
        if r < 0 or n < r or n > self.size:
            return 0
        return self.fact[n]*self.invfact[r]%self.mod*self.invfact[n-r]%self.mod
    def nhr(self, n, r):
        if n <= 0 or r < 0 or n+r-1 > self.size:
            return 0
        return self.ncr(n+r-1, r)

class prime:
    @staticmethod
    def is_prime(N):
        if N < 2:
            return False
        small = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29]
        large = [2, 325, 9375, 28178, 450775, 9780504, 1795265022]
        for i in small:
            if N%i == 0:
                return N == i
        d, s = N-1, 0
        while d%2 == 0:
            d //= 2
            s += 1
        for i in large:
            if i%N == 0:
                continue
            x = pow(i, d, N)
            if x == 1 or x == N-1:
                continue
            comp = True
            for j in range(1, s):
                x = x*x%N
                if x == N-1:
                    comp = False
                    break
            if comp:
                return False
        return True
    @staticmethod
    def prime_sieve(N):
        isprime = [True]*(N+1)
        sq = math.isqrt(N)+2
        isprime[0] = False
        isprime[1] = False
        for i in range(2, N+1):
            if not isprime[i]:
                continue
            for j in range(i*i, N+1, i):
                isprime[j] = False
        res = []
        for i in range(1, N+1):
            if isprime[i]:
                res.append(i)
        return res
    @staticmethod
    def calc_divisor(N):
        res = []
        i = 1
        while i*i <= N:
            if N%i == 0:
                res.append(i)
                if i*i != N:
                    res.append(N//i)
            i += 1
        return sorted(res)
    @staticmethod
    def pollard(N):
        if N%2 == 0:
            return 2
        if N%3 == 0:
            return 3
        while True:
            c = random.randrange(1, N)
            x = random.randrange(N)
            y, d = x, 1
            def f(v):
                return (v*v+c)%N
            while d == 1:
                x, y = f(x), f(f(y))
                d = math.gcd(abs(x-y), N)
            if d != N:
                return d
    @staticmethod
    def _prime_factor_internal(N, res):
        if N == 1:
            return
        if num.is_prime(N):
            res.append(N)
            return
        d = num.pollard(N)
        num._prime_factor_internal(d, res)
        num._prime_factor_internal(N//d, res)
    @staticmethod
    def prime_factor(N):
        res = []
        num._prime_factor_internal(N, res)
        return sorted(res)

if __name__ == "__main__":
    pass
