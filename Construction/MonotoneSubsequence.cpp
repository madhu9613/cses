#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve(int n, int k) {
    if (k == 1) {
        if (n == 1) {
            cout << "1\n";
        } else {
            cout << "IMPOSSIBLE\n";
        }
    } else if (k == n) {
        for (int i = 1; i <= n; ++i)
            cout << i << " ";
        cout << "\n";
    } else {
        int max_group_size = (n + k - 1) / k;
        if (max_group_size > k) {
            cout << "IMPOSSIBLE\n";
        } else {
            vector<int> permutation;
            int current = 1;
            int base_group_size = n / k;
            int extra = n % k;

            for (int i = 0; i < k; ++i) {
                int group_size = base_group_size + (i < extra ? 1 : 0);
                vector<int> group;
                for (int j = 0; j < group_size; ++j) {
                    group.push_back(current++);
                }
                reverse(group.begin(), group.end());
                for (int val : group) {
                    cout << val << " ";
                }
            }
            cout << "\n";
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        solve(n, k);
    }
    return 0;
}
