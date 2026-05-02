#include <bits/stdc++.h>
using namespace std;

#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);
#define ll long long

struct Node
{
    int xr;
    int win; // 0 = left wins, 1 = right wins
};

void solve()
{
    int n, q;
    cin >> n >> q;

    int N = 1 << n;

    // 1-based indexing for cows
    vector<int> a(N + 1);
    for (int i = 1; i <= N; i++)
        cin >> a[i];

    // level[i] = tournament round i (1-based)
    vector<vector<Node>> level(n + 1);

    // Level 0 -> original cows (1-based)
    level[0].resize(N + 1);
    for (int i = 1; i <= N; i++)
    {
        level[0][i] = {a[i], 0};
    }

    // Build tournament
    for (int i = 1; i <= n; i++)
    {
        int sz = (int)level[i - 1].size() / 2;
        level[i].resize(sz + 1);
        for (int j = 1; j <= sz; j++)
        {
            Node L = level[i - 1][2 * j - 1];
            Node R = level[i - 1][2 * j];
            level[i][j].xr = L.xr ^ R.xr;
            level[i][j].win = (L.xr >= R.xr ? 0 : 1);
        }
    }

    // Update cow at position p (1-based)
    auto update = [&](int p, int val)
    {
        level[0][p].xr = val;
        for (int i = 1; i <= n; i++)
        {
            p = (p + 1) / 2;
            Node L = level[i - 1][2 * p - 1];
            Node R = level[i - 1][2 * p];
            level[i][p].xr = L.xr ^ R.xr;
            level[i][p].win = (L.xr >= R.xr ? 0 : 1);
        }
    };

    // Compute number of cows below cow p
    auto final_position = [&](int p)
    {
        ll pos = 0, block = 1;
        for (int i = 1; i <= n; i++)
        {
            int parent = (p + 1) / 2;
            int side = (p % 2 == 1 ? 0 : 1); // left = 0, right = 1
            if (level[i][parent].win == side)
                pos += block;
            block <<= 1;
            p = parent;
        }
        return pos;
    };

    while (q--)
    {
        int b, c;
        cin >> b >> c;

        int old = level[0][b].xr;

        update(b, c);
        ll below = final_position(b);
        cout << (N - 1 - below) << "\n";
        update(b, old); // rollback
    }
}

int main()
{
    fastio int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}
