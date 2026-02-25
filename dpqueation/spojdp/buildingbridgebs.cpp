// https://www.spoj.com/problems/BRIDGE/

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

        vector<int> left(n), right(n);
        for (int i = 0; i < n; i++)
            cin >> left[i];
        for (int i = 0; i < n; i++)
            cin >> right[i];

        vector<pair<int, int>> bridges(n);
        for (int i = 0; i < n; i++)
            bridges[i] = {left[i], right[i]};

        sort(bridges.begin(), bridges.end());

        vector<int> tail;

        for (int i = 0; i < n; i++)
        {
            int x = bridges[i].second;

            auto it = upper_bound(tail.begin(), tail.end(), x);

            if (it == tail.end())
                tail.push_back(x);
            else
                *it = x;
        }

        cout << tail.size() << "\n";
    }

    return 0;
}
