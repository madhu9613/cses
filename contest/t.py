import sys

def solve():
    n, k = map(int, sys.stdin.readline().split())
    a = list(map(int, sys.stdin.readline().split()))
    p = list(map(int, sys.stdin.readline().split()))
    
    x = a[p[0]-1]
    
    # We want to make everything equal to x.
    # Let's count how many times we change from x to not-x and back.
    ops = 0
    current_val = x
    
    for i in range(n):
        if a[i] != current_val:
            ops += 1
            current_val = a[i]
            
    # If we ended on not-x, we need one more flip to get back to x.
    if current_val != x:
        ops += 1
        
    print(ops)

t_str = sys.stdin.readline().strip()
if t_str:
    t = int(t_str)
    for _ in range(t):
        solve()