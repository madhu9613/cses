t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    if k == 1:
        if n == 1:
            print(1)
        else:
            print("IMPOSSIBLE")
    elif k == n:
        print(' '.join(map(str, range(1, n+1))))
    else:
        # Check if solution is possible: according to Erdős–Szekeres, the minimal maximum is ceil(sqrt(n))
        # But we need to construct a permutation where max(lis, lds) = k.
        # The necessary condition is that k must be such that it's possible to split into k groups where the LIS is k (picking one from each group)
        # And the LDS is the size of the largest group. So, the largest group must be <=k, but also, product of lis (k) and lds (max group size) >=n.
        # So, max group size should be <=k and >= ceil(n/k)
        max_group_size = (n + k - 1) // k
        if max_group_size > k:
            print("IMPOSSIBLE")
        else:
            # Construct the permutation by splitting into k groups, each group is decreasing.
            # The groups are [1..a1], [a1+1..a2], ..., [a_{k-1}+1..n], each in decreasing order.
            # The total elements is n.
            groups = []
            elements = list(range(1, n+1))
            group_size = n // k
            remainder = n % k
            start = 0
            for i in range(k):
                current_group_size = group_size + (1 if i < remainder else 0)
                end = start + current_group_size
                group = elements[start:end]
                groups.append(group[::-1])  # reverse to make decreasing
                start = end
            permutation = []
            for group in groups:
                permutation.extend(group)
            print(' '.join(map(str, permutation)))