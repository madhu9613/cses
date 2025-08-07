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

int n, s;
vi a;

int maxiLsumS() {
    int maxLen = -1;
    int left = 0, sum = 0;

    for (int right = 0; right < n; ++right) {
        sum += a[right];

        while (sum > s && left <= right) {
            sum -= a[left++];
        }

        if (sum == s) {
            maxLen = max(maxLen, right - left + 1);
        }
    }

    return maxLen;
}

void solve() {
    cin >> n >> s;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int len = maxiLsumS();
    if (len == -1) {
        cout << -1 << endl; 
    } else {
        cout << n - len << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
