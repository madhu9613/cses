#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long n, k;
    cin >> n >> k;

    vector<int> res;
    int low = 1, high = n;

    for (int i = 0; i < n; ++i) {
        long long max_inv = high - low;

        if (k >= max_inv) {
            res.push_back(high);
            k -= max_inv;
            --high;
        } else {
            res.push_back(low);
            ++low;
        }
    }

    for (int x : res) {
        cout << x << " ";
    }
    cout << '\n';

    return 0;
}
