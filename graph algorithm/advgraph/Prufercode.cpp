#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> prufer(n - 2);
    vector<int> degree(n + 1, 1);  // all nodes initially have degree 1

    for (int i = 0; i < n - 2; ++i) {
        cin >> prufer[i];
        degree[prufer[i]]++;  // each code number increases degree
    }

    set<int> leaves;
    for (int i = 1; i <= n; ++i) {
        if (degree[i] == 1)
            leaves.insert(i);
    }

    for (int u : prufer) {
        int v = *leaves.begin();  // smallest leaf
        leaves.erase(leaves.begin());

        cout << u << " " << v << '\n';

        degree[u]--;
        degree[v]--;

        if (degree[u] == 1)
            leaves.insert(u);
    }

    // Two nodes remain
    auto it = leaves.begin();
    int a = *it;
    ++it;
    int b = *it;

    cout << a << " " << b << '\n';

    return 0;
}
