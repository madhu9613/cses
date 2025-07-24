import sys
from math import log2
from collections import deque

def main():
    input = sys.stdin.read().split()
    ptr = 0
    n, q = map(int, input[ptr:ptr+2])
    ptr +=2
    c = list(map(int, input[ptr:ptr+n]))
    ptr +=n
    
    adj = [[] for _ in range(n+1)]
    for _ in range(n-1):
        a, b = map(int, input[ptr:ptr+2])
        ptr +=2
        adj[a].append(b)
        adj[b].append(a)
    
    LOG = int(log2(n)) + 2
    parent = [[-1]*(n+1) for _ in range(LOG)]
    depth = [0]*(n+1)
    size = [0]*(n+1)
    heavy = [-1]*(n+1)
    head = [0]*(n+1)
    pos = [0]*(n+1)
    current_pos = 0

    # DFS to compute size, heavy, parent, depth
    def dfs(u):
        nonlocal current_pos
        size[u] = 1
        max_size = 0
        for v in adj[u]:
            if v != parent[0][u]:
                parent[0][v] = u
                depth[v] = depth[u] + 1
                dfs(v)
                size[u] += size[v]
                if size[v] > max_size:
                    max_size = size[v]
                    heavy[u] = v
    parent[0][1] = -1
    depth[1] = 0
    dfs(1)

    # Binary lifting for LCA
    for k in range(1, LOG):
        for v in range(1, n+1):
            if parent[k-1][v] != -1:
                parent[k][v] = parent[k-1][parent[k-1][v]]

    def lca(u, v):
        if u == v:
            return u
        if depth[u] < depth[v]:
            u, v = v, u
        # bring u up to depth of v
        for k in range(LOG-1, -1, -1):
            if depth[u] - (1<<k) >= depth[v]:
                u = parent[k][u]
        if u == v:
            return u
        for k in range(LOG-1, -1, -1):
            if parent[k][u] != -1 and parent[k][u] != parent[k][v]:
                u = parent[k][u]
                v = parent[k][v]
        return parent[0][u]

    # HLD decomposition
    def decompose(u, h):
        nonlocal current_pos
        head[u] = h
        pos[u] = current_pos
        current_pos += 1
        if heavy[u] != -1:
            decompose(heavy[u], h)
        for v in adj[u]:
            if v != parent[0][u] and v != heavy[u]:
                decompose(v, v)
    decompose(1, 1)

    # Segment Tree for path queries
    class SegmentTree:
        def __init__(self, data):
            self.n = len(data)
            self.size = 1
            while self.size < self.n:
                self.size <<= 1
            self.tree = [0] * (2 * self.size)
            for i in range(self.n):
                self.tree[self.size + i] = data[i]
            for i in range(self.size - 1, 0, -1):
                self.tree[i] = self.tree[2 * i] + self.tree[2 * i + 1]
        
        def query_range(self, l, r):
            res = 0
            l += self.size
            r += self.size
            while l <= r:
                if l % 2 == 1:
                    res += self.tree[l]
                    l += 1
                if r % 2 == 0:
                    res += self.tree[r]
                    r -= 1
                l //= 2
                r //= 2
            return res

    # Initialize data for Segment Tree
    data = [0]*n
    st = SegmentTree(data)

    def distance(u, v):
        ancestor = lca(u, v)
        return depth[u] + depth[v] - 2 * depth[ancestor]

    coin_nodes = [i for i in range(1, n+1) if c[i-1] == 1]

    for _ in range(q):
        a, b = map(int, input[ptr:ptr+2])
        ptr +=2
        S = list(set(coin_nodes + [a, b]))
        if len(S) == 1:
            print(0)
            continue
        # Sort S based on pos values
        S_sorted = sorted(S, key=lambda x: pos[x])
        total = 0
        # Sum distances between consecutive nodes and the wrap-around
        for i in range(len(S_sorted)):
            u = S_sorted[i]
            v = S_sorted[(i+1)%len(S_sorted)]
            total += distance(u, v)
        steiner_edges = total // 2
        answer = 2 * steiner_edges - distance(a, b)
        print(answer)

if __name__ == '__main__':
    main()