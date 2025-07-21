#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    stack<int> st;

    for (int i = 0; i < n; ++i) {
        while (!st.empty() && a[st.top()] >= a[i]) {
            st.pop();
        }

        if (st.empty()) {
            cout << 0 << " ";
        } else {
            cout << st.top() + 1 << " "; // Convert to 1-based
        }

        st.push(i);
    }

    cout << "\n";
    return 0;
}
