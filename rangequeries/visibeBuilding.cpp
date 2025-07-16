#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005
#define LOG 17 // since 2^17 > 1e5

int n, q;
int h[MAXN];
int P[MAXN]; // P[i] = next greater index to the right
int up[MAXN][LOG]; // binary lifting table

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;
    for (int i = 0; i < n; ++i) cin >> h[i];

    // Step 1: Compute P[i] using a monotonic stack
    stack<int> st;
    for (int i = n - 1; i >= 0; --i) {
        while (!st.empty() && h[st.top()] <= h[i]) st.pop();
        P[i] = st.empty() ? n : st.top(); // n means out of bounds
        st.push(i);
    }

    // Step 2: Binary lifting setup
    for (int i = 0; i < n; ++i)
        up[i][0] = P[i];

    for (int j = 1; j < LOG; ++j) {
        for (int i = 0; i < n; ++i) {
            int mid = up[i][j - 1];
            up[i][j] = (mid < n) ? up[mid][j - 1] : n;
        }
    }

    // Step 3: Answer queries
    while (q--) {
        int a, b;
        cin >> a >> b;
        --a; --b;

        int count = 0;
        int curr = a;

        for (int j = LOG - 1; j >= 0; --j) {
            if (up[curr][j] <= b) {
                curr = up[curr][j];
                count += (1 << j);
            }
        }

        // Count the starting building
        cout << count + 1 << '\n';
    }

    return 0;
}
