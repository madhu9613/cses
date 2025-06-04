MOD = 10**9 + 7

def count_distinct_subsequences(arr):
    n = len(arr)
    last_seen = dict()
    total = 0
    dp = [0] * n

    for i in range(n):
        x = arr[i]
        dp[i] = (total + 1) % MOD
        if x in last_seen:
            dp[i] = (dp[i] - dp[last_seen[x]] + MOD) % MOD
        last_seen[x] = i
        total = (total + dp[i]) % MOD

    return total

# Input reading
n = int(input())
arr = list(map(int, input().split()))
print(count_distinct_subsequences(arr))
