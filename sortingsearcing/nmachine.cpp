#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool canProduce(vector<int>& machines, ll time, ll t) {
    ll total = 0;
    for (int k : machines) {
        total += time / k;
        if (total >= t) return true;  // Early stopping
    }
    return total >= t;
}

int main() {
    int n;
    ll t;
    cin >> n >> t;
    vector<int> machines(n);
    for (int i = 0; i < n; i++) {
        cin >> machines[i];
    }

    // Binary search on time
    ll left = 1, right = *min_element(machines.begin(), machines.end()) * t, ans = right;
    while (left <= right) {
        ll mid = left + (right - left) / 2;
        if (canProduce(machines, mid, t)) {
            ans = mid;
            right = mid - 1;  // Try for a smaller time
        } else {
            left = mid + 1;  // Increase time
        }
    }

    cout << ans << endl;
    return 0;
}
