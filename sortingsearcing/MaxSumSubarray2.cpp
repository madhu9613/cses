#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    vector<long long> x(n + 1), prefix(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> x[i];
        prefix[i] = prefix[i - 1] + x[i];
    }

    multiset<long long> window; // to maintain prefix[j] in [i-b, i-a]
    long long ans = LLONG_MIN;

    for (int i = a; i <= n; ++i) {
        // Insert prefix[i - a] into window
        window.insert(prefix[i - a]);
        // Remove prefix[i - b - 1] if it's out of range
        if (i - b - 1 >= 0) {
            window.erase(window.find(prefix[i - b - 1]));
        }
        // Now window has prefix[j] for j in [i-b, i-a]
        ans = max(ans, prefix[i] - *window.begin());
    }

    cout << ans << '\n';
    return 0;
}
