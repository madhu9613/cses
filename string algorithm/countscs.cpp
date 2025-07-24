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

int countSCS(string A, string B) {
    int n = A.size(), m = B.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1));
    vector<vector<int>> cnt(n+1, vector<int>(m+1));

    for (int i = 0; i <= n; i++) {
        dp[i][0] = i;
        cnt[i][0] = 1;
    }

    for (int j = 0; j <= m; j++) {
        dp[0][j] = j;
        cnt[0][j] = 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (A[i-1] == B[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
                cnt[i][j] = cnt[i-1][j-1];
            } else {
                if (dp[i-1][j] < dp[i][j-1]) {
                    dp[i][j] = 1 + dp[i-1][j];
                    cnt[i][j] = cnt[i-1][j];
                } else if (dp[i-1][j] > dp[i][j-1]) {
                    dp[i][j] = 1 + dp[i][j-1];
                    cnt[i][j] = cnt[i][j-1];
                } else {
                    dp[i][j] = 1 + dp[i-1][j]; // or dp[i][j-1]
                    cnt[i][j] = (cnt[i-1][j] + cnt[i][j-1]) % MOD;
                }
            }
        }
    }

    return cnt[n][m];
}

void solve() {
    string a,b;cin>>a>>b;
    cout<<countSCS(a,b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    while (t--) solve();
    return 0;
}