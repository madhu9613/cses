#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        vector<int> a(n + 1);
        vector<array<int, 2>> edges;

        for (int i = 1; i <= n; i++)
            cin >> a[i];

        bool possible = true;
        vector<int> parent(n + 1);

        for (int i = 2; i <= n; i++)
        {
            if (a[i] != a[1])
            {
                edges.push_back({1, i});
                parent[i] = 1;
            }
            else
            {
                if (i > 2)
                {
                    if (a[i - 1] != a[i])
                    {
                        edges.push_back({i - 1, i});
                        parent[i] = i - 1;
                    }
                    else
                    {
                        edges.push_back({parent[i - 1], i});
                        parent[i] = parent[i - 1]; 
                    }
                }
                else
                {
                    bool found = false;
                    for (int j = 2; j <= n; j++)
                    {
                        if (a[j] != a[i])
                        {
                            parent[i] = j;
                            edges.push_back({j, i});
                            found = true;
                            break;
                        }
                    }
                    if (!found)
                    {
                        possible = false;
                        break;
                    }
                }
            }
        }

        if (possible && (int)edges.size() == n - 1)
        {
            cout << "YES\n";
            for (auto &e : edges)
            {
                cout << e[0] << " " << e[1] << "\n";
            }
        }
        else
        {
            cout << "NO\n";
        }
    }
    return 0;
}
