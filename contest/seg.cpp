#include <bits/stdc++.h>
using namespace std;

struct SegTree
{
    int n;
    vector<int> t;

    SegTree(int n = 0)
    {
        init(n);
    }

    void init(int n_)
    {
        n = n_;
        t.assign(4 * n + 4, 0);
    }

    void update(int node, int l, int r, int pos, int val)
    {
        if (l == r)
        {
            t[node] += val;
            return;
        }
        int mid = (l + r) >> 1;
        if (pos <= mid)
            update(node << 1, l, mid, pos, val);
        else
            update(node << 1 | 1, mid + 1, r, pos, val);
        t[node] = t[node << 1] + t[node << 1 | 1];
    }

    void add(int pos, int val)
    {
        update(1, 1, n, pos, val);
    }

    int query(int node, int l, int r, int ql, int qr)
    {
        if (ql > r || qr < l)
            return 0;
        if (ql <= l && r <= qr)
            return t[node];
        int mid = (l + r) >> 1;
        return query(node << 1, l, mid, ql, qr) +
               query(node << 1 | 1, mid + 1, r, ql, qr);
    }

    int sum(int r)
    {
        if (r <= 0)
            return 0;
        return query(1, 1, n, 1, r);
    }

    // Find smallest idx such that prefix sum >= k
    int kth(int k)
    {
        int node = 1, l = 1, r = n;
        if (t[node] < k)
            return n + 1;

        while (l != r)
        {
            int mid = (l + r) >> 1;
            if (t[node << 1] >= k)
            {
                node = node << 1;
                r = mid;
            }
            else
            {
                k -= t[node << 1];
                node = node << 1 | 1;
                l = mid + 1;
            }
        }
        return l;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
    {
        int n;
        long long k;
        cin >> n >> k;

        vector<long long> a(n + 1), p(n + 1, 0), d(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            p[i] = p[i - 1] + a[i];
        }
        for (int i = 1; i <= n; i++)
            d[i] = a[i] - p[i - 1];

        vector<int> s0(n + 2, 0);
        for (int i = n; i >= 1; i--)
            s0[i] = s0[i + 1] + (d[i] > 0);

        vector<pair<long long, int>> dv;
        for (int i = 1; i <= n; i++)
            dv.push_back({d[i], i});
        sort(dv.begin(), dv.end(), greater<>());

        vector<int> ord(n);
        iota(ord.begin(), ord.end(), 1);
        sort(ord.begin(), ord.end(),
             [&](int i, int j)
             { return a[i] > a[j]; });

        SegTree seg(n);
        int ptr = 0;
        vector<long long> ans(n + 1, 0);

        auto fp = [&](int l, int r, int lim)
        {
            if (l > r || lim < 0)
                return r + 1;
            int lo = l, hi = r, res = r + 1;
            while (lo <= hi)
            {
                int mid = (lo + hi) >> 1;
                if (s0[mid + 1] <= lim)
                {
                    res = mid;
                    hi = mid - 1;
                }
                else
                    lo = mid + 1;
            }
            return res;
        };

        for (int i : ord)
        {
            long long v = a[i];
            while (ptr < n && dv[ptr].first > v)
            {
                seg.add(dv[ptr].second, 1);
                ptr++;
            }

            long long A = s0[i + 1], K = k - A, L = 0;
            if (K >= 0)
            {
                int tot = seg.sum(i - 1);
                int t = lower_bound(p.begin(), p.end(), v) - p.begin() + 1;

                int R1 = min(i, t - 1);
                if (R1 >= 1)
                {
                    long long need = tot - K;
                    int pos = (need > 0 ? seg.kth((int)need) + 1 : 1);
                    int x = max(1, pos);
                    if (x <= R1)
                        L += R1 - x + 1;
                }

                int L2 = max(1, t), R2 = i;
                if (L2 <= R2)
                {
                    long long lim = K - 1;
                    int pos;
                    if (lim < 0)
                        pos = i + 1;
                    else
                    {
                        long long need = tot - lim;
                        pos = (need > 0 ? seg.kth((int)need) + 1 : 1);
                    }
                    int x = max(L2, pos);
                    if (x <= R2)
                        L += R2 - x + 1;
                }
            }

            long long R = 0;
            int st = i + 1;
            if (st <= n)
            {
                int tr = lower_bound(p.begin() + 1, p.end(), 2 * v) - p.begin();
                int eA = min(n, tr - 1);
                int xA = fp(st, eA, (int)k);
                if (xA <= eA)
                    R += eA - xA + 1;

                int sB = max(st, tr);
                int xB = fp(sB, n, (int)(k - 1));
                if (xB <= n)
                    R += n - xB + 1;
            }

            ans[i] = L + R;
        }

        for (int i = 1; i <= n; i++)
            cout << ans[i] << (i == n ? '\n' : ' ');
    }
    return 0;
}
