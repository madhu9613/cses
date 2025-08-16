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
    int n;
    cin >> n;
    vector<array<int, 3>> happy(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> happy[i][0] >> happy[i][1] >> happy[i][2];
    }
    array<int, 3> prev = happy[1];

    for (int i = 2; i <= n; i++)
    {
        array<int, 3> curr;
        curr[0] = happy[i][0] + max(prev[1], prev[2]);
        curr[1] = happy[i][1] + max(prev[0], prev[2]);
        curr[2] = happy[i][2] + max(prev[0], prev[1]);
        prev = curr;
    }
    cout << *max_element(prev.begin(), prev.end()) << endl;
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