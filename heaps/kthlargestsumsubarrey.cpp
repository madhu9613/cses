#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Min heap to store the k largest sums
    priority_queue<int, vector<int>, greater<int>> mini;

    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += arr[j];

            if (mini.size() < k) {
                mini.push(sum);
            } else if (sum > mini.top()) {
                mini.pop();
                mini.push(sum);
            }
        }
    }

    // Kth largest sum of a subarray
    cout << mini.top() << endl;

    return 0;
}
