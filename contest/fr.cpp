#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;

        vector<int> a(n), b(n);
        for (auto &x : a)
            cin >> x;
        for (auto &x : b)
            cin >> x;

        bool ok = true;

        // For each residue class mod k, check multisets
        for (int r = 0; r < k && ok; r++)
        {
            map<int, int> cnt; // count of a values
            int wildcards = 0;

            for (int i = r; i < n; i += k)
            {
                cnt[a[i]]++;
            }
            for (int i = r; i < n; i += k)
            {
                if (b[i] == -1)
                {
                    wildcards++;
                }
                else
                {
                    if (cnt[b[i]] > 0)
                    {
                        cnt[b[i]]--;
                    }
                    else
                    {
                        ok = false;
                        break;
                    }
                }
            }
            // wildcards should fill remaining cnt values
            // sum of remaining cnt values should equal wildcards
            if (ok)
            {
                int remaining = 0;
                for (auto &p : cnt)
                    remaining += p.second;
                if (remaining != wildcards)
                    ok = false;
            }
        }

        cout << (ok ? "YES" : "NO") << "\n";
    }
    return 0;
}