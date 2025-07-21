#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    long long x;
    cin >> n >> x;
    
    vector<pair<long long, int>> a(n); // pair: value, original index

    for (int i = 0; i < n; ++i) {
        cin >> a[i].first;
        a[i].second = i + 1; // 1-based indexing
    }

    sort(a.begin(), a.end());

    for (int i = 0; i < n; ++i) {
        int left = i + 1, right = n - 1;
        while (left < right) {
            long long sum = a[i].first + a[left].first + a[right].first;
            if (sum == x) {
                cout << a[i].second << " " << a[left].second << " " << a[right].second << endl;
                return 0;
            } else if (sum < x) {
                ++left;
            } else {
                --right;
            }
        }
    }

    cout << "IMPOSSIBLE" << endl;
    return 0;
}
