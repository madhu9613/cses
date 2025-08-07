#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define max3(a, b, c) max(max(a, b), c)
#define max4(a, b, c, d) max(max(a, b), max(c, d))
#define pii pair<int,int>
#define all(x) (x).begin(), (x).end()
#define endl '\n'
 
const int MOD = 1e9 + 7;
const int INF = INT_MAX;
 
void solve() {
    string s;
    cin >> s;
    int n = s.length();
    int total0 = count(all(s), '0');
    int total1 = n - total0;
 
    int rem0 = total0;
    int rem1 = total1;
 
    string t = "";
    for (int i = 0; i < n; i++) {
        if (s[i] == '1' && rem0 > 0) {
            t += '0';
            rem0--;
        } else if (s[i] == '0' && rem1 > 0) {
            t += '1';
            rem1--;
        } else {
            break;
        }
    }
 
    cout << n - t.length() << endl;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}