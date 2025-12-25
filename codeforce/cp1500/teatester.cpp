#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<ll> a(n), b(n);
        for (auto& x : a) cin >> x;
        for (auto& x : b) cin >> x;

        vector<ll> sum(n + 1, 0);
        for (int i = 0; i < n; i++)
            sum[i + 1] = sum[i] + b[i];

        vector<ll> cnt(n + 1, 0), add(n + 1, 0);

        for (int i = 0; i < n; i++) {
            int j = lower_bound(sum.begin(), sum.end(),
                a[i] + sum[i] + 1) - sum.begin() - 1;
            cnt[i]++;
            cnt[j]--;
            add[j] += a[i] - sum[j] + sum[i];
        }

        for (int i = 0; i < n; i++) {
            cout << cnt[i] * b[i] + add[i] << ' ';
            cnt[i + 1] += cnt[i];
        }
        cout << '\n';
    }
}
