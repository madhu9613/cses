#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<long long> h(n);
    for (int i = 0; i < n; ++i) cin >> h[i];

    vector<int> NSL(n), NSR(n);
    stack<int> st;

    // Previous Smaller
    for (int i = 0; i < n; ++i) {
        while (!st.empty() && h[st.top()] >= h[i]) st.pop();
        NSL[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }

    while (!st.empty()) st.pop();

    // Next Smaller
    for (int i = n - 1; i >= 0; --i) {
        while (!st.empty() && h[st.top()] >= h[i]) st.pop();
        NSR[i] = st.empty() ? n : st.top();
        st.push(i);
    }

    // max_area[i] = maximum area in window i
    vector<long long> ans(n - k + 1, 0);

    for (int i = 0; i < n; ++i) {
        int l = NSL[i] + 1;
        int r = NSR[i] - 1;
        int width = r - l + 1;
        long long height = h[i];

        // valid windows where this bar contributes fully
        int start = max(l, i - k + 1);
        int end = min(i, n - k);

        for (int j = start; j <= end; ++j) {
            ans[j] = max(ans[j], height * min(k, width - (j < l ? l - j : 0)));
        }
    }

    for (auto a : ans) cout << a << " ";
    cout << "\n";
    return 0;
}
