// Count of Subarrays of given Array with median at least X
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Fenwick
{
    vector<int> bit;
    int n;
    Fenwick(int n) : n(n), bit(n + 1) {}
   void update(int i, int delta)
    {
        for (; i <= n; i += i & -i)
            bit[i] += delta;
    } 
    int query(int i)
    {
        int res = 0;
        for (; i > 0; i -= i & -i)
            res += bit[i];
        return res;
    }
};

ll countSubarraysWithMedianAtLeastX(const vector<int> &a, int x)
{
    int n = a.size();
    vector<int> b(n);
    for (int i = 0; i < n; ++i)
        b[i] = (a[i] >= x ? 1 : -1);

    vector<ll> prefix(n + 1);
    for (int i = 0; i < n; ++i)
        prefix[i + 1] = prefix[i] + b[i];

    // Coordinate compression
    vector<ll> all = prefix;
    sort(all.begin(), all.end());
    all.erase(unique(all.begin(), all.end()), all.end());

    auto getIndex = [&](ll val)
    {
        return lower_bound(all.begin(), all.end(), val) - all.begin() + 1;
    };

    Fenwick bit(all.size());
    ll ans = 0;
    for (int i = 0; i <= n; ++i)
    {
        int idx = getIndex(prefix[i]);
        ans += bit.query(idx);
        ; // Count prefixes smaller than current
        bit.update(idx, 1);
    }
    return ans;
}

int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int &v : a)
        cin >> v;

    cout << countSubarraysWithMedianAtLeastX(a, x) << '\n';
    return 0;
}
