#include <bits/stdc++.h>
using namespace std;

bool isPalindromeIgnoreX(const vector<int>& arr, int x) {
    int left = 0, right = arr.size() - 1;

    while (left < right) {
        while (left < right && arr[left] == x) left++;
        while (left < right && arr[right] == x) right--;

        if (arr[left] != arr[right])
            return false;

        left++;
        right--;
    }

    return true;
}

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int &x : arr) cin >> x;

    if (n <= 1) {
        cout << "Yes" << endl;
        return;
    }

    int left = 0, right = n - 1;

    while (left < right) {
        if (arr[left] != arr[right]) {
            if (isPalindromeIgnoreX(arr, arr[left]) || isPalindromeIgnoreX(arr, arr[right])) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
            return;
        }
        left++;
        right--;
    }

    cout << "Yes" << endl;
}

int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
