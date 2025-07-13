#include <bits/stdc++.h>
using namespace std;

bool isPalindromeIgnoreX(string s, char x, int &ans) {
    int left = 0, right = s.length() - 1;

    while (left < right) {
        if (s[left] != s[right]) {
            while (left < right && s[left] == x) {
                left++;
                ans++;
            }
            while (left < right && s[right] == x) {
                right--;
                ans++;
            }
        }
        if (s[left] != s[right]) {
            return false;
        }
        left++;
        right--;
    }

    return true;
}

int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        int left = 0, right = n - 1;
        bool solved = false;

        while (left < right) {
            if (s[left] != s[right]) {
                int ans1 = 0;
                bool isPos1 = isPalindromeIgnoreX(s, s[left], ans1);
                if (!isPos1) ans1 = INT_MAX;

                int ans2 = 0;
                bool isPos2 = isPalindromeIgnoreX(s, s[right], ans2);
                if (!isPos2) ans2 = INT_MAX;

                if (!isPos1 && !isPos2) {
                    cout << -1 << endl;
                } else {
                    cout << min(ans1, ans2) << endl;
                }

                solved = true;
                break;
            }
            left++;
            right--;
        }

        if (!solved) {
            cout << 0 << endl;  // Already a palindrome
        }
    }

    return 0;
}
