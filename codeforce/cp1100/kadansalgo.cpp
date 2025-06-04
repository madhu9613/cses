#include <bits/stdc++.h>
using namespace std;

// Returns ((start_index, end_index), max_sum)
pair<pair<int, int>, int> solve(int arr[], int n) {
    int max_sum = INT_MIN;
    int current_sum = 0;
    int start = 0, end = 0, temp_start = 0;

    for (int i = 0; i < n; ++i) {
        current_sum += arr[i];

        if (current_sum > max_sum) {
            max_sum = current_sum;
            start = temp_start;
            end = i;
        }

        if (current_sum < 0) {
            current_sum = 0;
            temp_start = i + 1;
        }
    }

    return {{start, end}, max_sum};
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        pair<pair<int, int>, int> ans = solve(arr, n);
        cout << "Start: " << ans.first.first << ", End: " << ans.first.second << ", Max Sum: " << ans.second << "\n";
    }
    return 0;
}
