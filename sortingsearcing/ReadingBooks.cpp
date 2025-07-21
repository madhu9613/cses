#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    long long sum = 0, max_time = 0;

    for (int i = 0; i < n; ++i) {
        long long t;
        cin >> t;
        sum += t;
        max_time = max(max_time, t);
    }

    cout << max(sum, 2 * max_time) << '\n';
    return 0;
}
