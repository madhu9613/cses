#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define max3(a, b, c) max(max(a, b), c)
#define max4(a, b, c, d) max(max(a, b), max(c, d))
#define pii pair<int, int>
#define pll pair<ll, ll>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endl '\n'

ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
}
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
const int MOD = 1e9 + 7;
const int INF = INT_MAX;
const ll LINF = 1e18;

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> child(n + 1);
    vi color(n + 1);
    int root = -1;
    for (int i = 1; i <= n; i++)
    {
        int p, c;
        cin >> p >> color[i];
        if (p == -1)
        {
            root = i;
        }
        else
        {
            child[p].pb(i);
        }
    }
    vi del;
    for (int i = 1; i <= n; i++)
    {
        if (i == root)
            continue;
        if (color[i] == 1)
        {
            bool candelete = true;
            for (int ch : child[i])
            {
                if (color[ch] == 0)
                {
                    candelete = false;

                    break;
                }
            }
            if (candelete)
            {

                del.pb(i);
            }
        }
    }
    if (del.empty())
    {
        cout << -1 << endl;
    }
    else
    {
        for (int v : del)
        {
            cout << v << " ";
        }
        cout << endl;
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