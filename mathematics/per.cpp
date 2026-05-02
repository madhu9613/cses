#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll fact[21];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // precompute factorials
    fact[0] = 1;
    for (int i = 1; i <= 20; i++)
        fact[i] = fact[i - 1] * i;

    int t;
    cin >> t;
    while (t--)
    {
        int type, n;
        cin >> type >> n;

        if (type == 1)
        {
            // TYPE 1: print k-th permutation
            ll k;
            cin >> k;

            vector<int> available;
            for (int i = 1; i <= n; i++)
                available.push_back(i);

            vector<int> ans;

            for (int i = 0; i < n; i++)
            {
                ll block = fact[n - i - 1];
                ll idx = (k - 1) / block;
                ans.push_back(available[idx]);
                available.erase(available.begin() + idx);
                k = (k - 1) % block + 1;
            }

            for (int x : ans)
                cout << x << " ";
            cout << "\n";
        }

        else
        {
            // TYPE 2: compute rank of given permutation
            vector<int> p(n);
            for (int i = 0; i < n; i++)
                cin >> p[i];

            vector<int> available;
            for (int i = 1; i <= n; i++)
                available.push_back(i);

            ll k = 1;

            for (int i = 0; i < n; i++)
            {
                int smaller = lower_bound(available.begin(), available.end(), p[i]) - available.begin();
                k += smaller * fact[n - i - 1];
                available.erase(available.begin() + smaller);
            }

            cout << k << "\n";
        }
    }
    return 0;
}
