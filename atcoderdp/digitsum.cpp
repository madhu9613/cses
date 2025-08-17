#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int MOD = 1e9 + 7;

string k;
int d;



int dp[10005][105][2]; 

int f(int pos, int sum, bool tight) {
    if (pos == (int)k.size())
        return (sum % d == 0);

    if (dp[pos][sum][tight] != -1)
        return dp[pos][sum][tight];

    int res = 0;
    int maxi = tight ? k[pos] - '0' : 9;
    for (int digit = 0; digit <= maxi; digit++) {
        res = (res + f(pos + 1, (sum + digit) % d, tight && (digit == maxi))) % MOD;
    }
    return dp[pos][sum][tight] = res;
}

void solve() {
    cin >> k >> d;
    memset(dp, -1, sizeof(dp));

    int ans = f(0, 0, 1) - 1; 
    if (ans < 0) ans += MOD;
    cout << ans << endl;
}


 //printing the valid answers offcours its exponential'

 
// void dfs(int pos, int sum, bool tight, string num) {
//     if (pos == (int)k.size()) {
//         if (sum % d == 0) {
//             cout << num << endl;  
//         }
//         return;
//     }

//     int maxi = tight ? k[pos] - '0' : 9;
//     for (int digit = 0; digit <= maxi; digit++) {
//         dfs(pos + 1, (sum + digit) % d, tight && (digit == maxi), num + char('0' + digit));
//     }
// }

// void solve() {
//     cin >> k >> d;

//     dfs(0, 0, true, "");  
// }


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}
