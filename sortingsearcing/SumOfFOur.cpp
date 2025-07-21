#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    long long x;
    cin >> n >> x;

    vector<pair<long long, int>> a(n); // value, index
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first;
        a[i].second = i + 1; // 1-based index
    }

    // Map from sum to list of index pairs
    unordered_map<long long, vector<pair<int, int>>> mp;

    // Store all pair sums
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            mp[a[i].first + a[j].first].emplace_back(i, j);
        }
    }

    // Now try all combinations again and check for complement
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            long long need = x - (a[i].first + a[j].first);
            if (mp.find(need) != mp.end()) {
                for (auto [k, l] : mp[need]) {
                    // Ensure all indices are distinct
                    if (k != i && k != j && l != i && l != j) {
                        cout << a[i].second << " " << a[j].second << " "
                             << a[k].second << " " << a[l].second << "\n";
                        return 0;
                    }
                }
            }
        }
    }

    cout << "IMPOSSIBLE\n";
    return 0;
}
