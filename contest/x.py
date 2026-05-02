import sys
from collections import deque, defaultdict

input = sys.stdin.read

def solve():
    data = input().split()
    idx = 0
    t = int(data[idx]); idx += 1
    results = []
    
    for _ in range(t):
        n = int(data[idx]); idx += 1
        a = [0] + list(int(data[idx + x]) for x in range(n)); idx += n
        
        adj = [[] for _ in range(n + 1)]
        degree = [0] * (n + 1)
        
        for __ in range(n - 1):
            u = int(data[idx]); v = int(data[idx + 1])
            idx += 2
            adj[u].append(v)
            adj[v].append(u)
            degree[u] += 1
            degree[v] += 1
        
        # Calculate initial S_v parity
        sum_parity = [0] * (n + 1)
        for v in range(1, n + 1):
            total = 0
            for u in adj[v]:
                total += a[u]
            sum_parity[v] = total % 2
        
        # Removable if a[v] % 2 != sum_parity[v]
        removable = [False] * (n + 1)
        q = deque()
        removed = [False] * (n + 1)
        remaining_degree = degree.copy()
        
        for v in range(1, n + 1):
            if (a[v] % 2) != sum_parity[v]:
                removable[v] = True
                q.append(v)
        
        order = []
        
        while q:
            v = q.popleft()
            if removed[v]:
                continue
            
            # Check if still removable (neighbors might have changed)
            if (a[v] % 2) != sum_parity[v]:
                order.append(v)
                removed[v] = True
                
                # Update neighbors
                for u in adj[v]:
                    if removed[u]:
                        continue
                    remaining_degree[u] -= 1
                    if a[v] % 2 == 1:  # odd value flips parity
                        sum_parity[u] ^= 1
                    
                    # Update sum_parity for u: remove a[v] contribution
                    # But we're tracking parity, so just flipped if a[v] odd
                    
                    # Check if u became removable
                    if (a[u] % 2) != sum_parity[u] and not removed[u]:
                        q.append(u)
        
        if len(order) == n:
            results.append("YES")
            results.append(" ".join(map(str, order)))
        else:
            results.append("NO")
    
    print("\n".join(results))

if __name__ == "__main__":
    solve()