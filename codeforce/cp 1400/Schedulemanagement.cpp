#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define endl '\n'

void solve()
{
    int n, m;
    cin >> n >> m;
    vi a(m);
    for (int i = 0; i < m; i++) cin >> a[i];

    vector<int> task_i_can_do_better(n + 1, 0);
    for (int i = 0; i < m; i++) task_i_can_do_better[a[i]]++;

    auto ican = [&](int t) {
        ll total_task = 0;
        for (int i = 1; i <= n; i++) {
            int x = min(task_i_can_do_better[i], t);
            if (t > x) {
                int rem = t - x;
                x += rem / 2;
            }
            total_task += x;
        }
        return total_task >= m;
    };

    int l = 1, r = 2 * m, ans = -1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (ican(mid)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
