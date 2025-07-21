// Author: Madhujya Rajkhowa
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define all(x) (x).begin(), (x).end()
#define endl '\n'

const int MOD = 1e9 + 7;
const int INF = INT_MAX;

void solve()
{
    int n,m;
    cin >> n>>m;
    vi a(n);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    vi pos(n + 1);

    for (int i = 1; i <= n; i++)
    {
        pos[a[i]] = i;
    }

    int round = 1;
    for (int i = 2; i <= n; i++)
    {
        if (pos[i] < pos[i - 1])
            round++;
    }
      while (m--) {
        int x, y;
        cin >> x>>y;

        // The values at positions a and b
        int va = a[x], vb = a[y];

        // Store affected value pairs (i, i+1)
        set<pair<int, int>> affected;

        for (int v : {va - 1, va, va + 1, vb - 1, vb, vb + 1}) {
            if (1 <= v && v < n) {
                affected.insert({v, v + 1});
            }
        }

        // Subtract current inversions
        for (auto [x, y] : affected) {
            if (pos[x] > pos[y]) round--;
        }

        // Perform the swap
        swap(a[x], a[y]);
        swap(pos[va], pos[vb]);

        // Add updated inversions
        for (auto [x, y] : affected) {
            if (pos[x] > pos[y]) round++;
        }

        cout << round << "\n";
    }
    
   

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    while (t--)
        solve();
    return 0;
}