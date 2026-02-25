#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        vector<int> x1(n), x2(n);
        for (int i = 0; i < n; i++)
            cin >> x1[i];
        for (int i = 0; i < n; i++)
            cin >> x2[i];

        vector<pair<int, int>> bridges(n);
        for (int i = 0; i < n; i++)
            bridges[i] = {x1[i], x2[i]};

        // Sort by left side coordinate
        sort(bridges.begin(), bridges.end());

        // LIS on right side coordinates
        vector<int> lis;
        for (auto &p : bridges)
        {
            int val = p.second;
            auto it = lower_bound(lis.begin(), lis.end(), val);
            if (it == lis.end())
                lis.push_back(val);
            else
                *it = val;
        }

        cout << lis.size() << "\n";
    }

    return 0;
}
