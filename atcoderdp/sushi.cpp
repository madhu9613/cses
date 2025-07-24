// Author: Madhujya Rajkhowa
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define all(x) (x).begin(), (x).end()
#define endl '\n'

const int MAXN = 305;
double dp[MAXN][MAXN][MAXN];
bool vis[MAXN][MAXN][MAXN];
int n;


double dfs(int x, int y, int z) {
    if (x < 0 || y < 0 || z < 0) return 0.0;
    if (x == 0 && y == 0 && z == 0) return 0.0;
    if (vis[x][y][z]) return dp[x][y][z];

    vis[x][y][z] = true;

    double total = x + y + z;
    double res = (double)n / total;

    if (x > 0) res += (x / total) * dfs(x - 1, y, z);
    if (y > 0) res += (y / total) * dfs(x + 1, y - 1, z);
    if (z > 0) res += (z / total) * dfs(x, y + 1, z - 1);

    return dp[x][y][z] = res;
}

void solve() {
    cin >> n;
    vector<int> a(n);
    int x = 0, y = 0, z = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] == 1) x++;
        else if (a[i] == 2) y++;
        else if (a[i] == 3) z++;
    }

    double ans = dfs(x, y, z);
    cout << fixed << setprecision(10) << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
