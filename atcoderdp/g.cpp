 #include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    for (int i = 0; i < n; i++) cin >> A[i];

    vector<bool> dp(k + 1, false); // dp[i] = true if winning with i stones

    for (int i = 1; i <= k; i++) {
        for (int a : A) {
            if (i - a >= 0 && !dp[i - a]) {
                dp[i] = true;
                break;
            }
        }
    }

    if (dp[k])
        cout << "First" << endl;  // Taro wins
    else
        cout << "Second" << endl; // Jiro wins

    return 0;
}
