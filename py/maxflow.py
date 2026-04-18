from collections import deque
import math

class maxflow:
    class edge:
        def __init__(self, to, cap, rev):
            self.to = to
            self.cap = cap
            self.rev = rev

    def __init__(self, n):
        self.N = n
        self.G = [[] for _ in range(n)]
        self.level = [-1] * n
        self.it = [0] * n

    def add_edge(self, u, v, cap):
        a = self.edge(v, cap, len(self.G[v]))
        b = self.edge(u, 0, len(self.G[u]))
        self.G[u].append(a)
        self.G[v].append(b)

    def bfs(self, s, t):
        self.level = [-1]*self.N
        q = deque()
        self.level[s] = 0
        q.append(s)
        while q:
            v = q.popleft()
            for e in self.G[v]:
                if e.cap > 0 and self.level[e.to] < 0:
                    self.level[e.to] = self.level[v]+1
                    q.append(e.to)
        return self.level[t] >= 0

    def dfs(self, v, t, f):
        if v == t:
            return f
        for i in range(self.it[v], len(self.G[v])):
            self.it[v] = i
            e = self.G[v][i]
            if e.cap > 0 and self.level[v] < self.level[e.to]:
                d = self.dfs(e.to, t, min(f, e.cap))
                if d > 0:
                    e.cap -= d
                    self.G[e.to][e.rev].cap += d
                    return d
        return 0

    def flow(self, s, t):
        flow = 0
        INF = float('inf')
        while self.bfs(s, t):
            self.it = [0]*self.N
            while True:
                f = self.dfs(s, t, INF)
                if f == 0:
                    break
                flow += f
        return flow
