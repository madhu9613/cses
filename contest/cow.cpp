#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    ll x, y;
    cin >> x >> y;

    // simplest case
    if ((x & y) == 0)
    {
        cout << x << " " << y << "\n";
        return;
    }

    ll p = 0, q = 0;

    for (int i = 0; i <= 30; i++)
    {
        ll bit = 1LL << i;

        bool bx = x & bit;
        bool by = y & bit;

        if (bx && !by)
        {
            p |= bit;
        }
        else if (!bx && by)
        {
            q |= bit;
        }
        else if (bx && by)
        {
            // conflict: give to smaller
            if (p <= q)
                p |= bit;
            else
                q |= bit;
        }
    }

    cout << p << " " << q << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
