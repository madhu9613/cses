#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> a;

bool check(int v, int& L, int& R) {
    vector<int> pref(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        if (a[i] >= v) pref[i] = pref[i - 1] + 1;
        else pref[i] = pref[i - 1] - 1;
    }

    int min_pref = 0;
    int min_pos = 0;

    for (int r = k; r <= n; r++) {
        if (pref[r - k] < min_pref) {
            min_pref = pref[r - k];
            min_pos = r - k;
        }

        if (pref[r] - min_pref >= 0) {
            L = min_pos + 1;
            R = r;
            return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        cin >> n >> k;

        a.assign(n + 1, 0);
        for (int i = 1; i <= n; i++)
            cin >> a[i];

        int low = 1, high = n;
        int vmax = 1;
        int L = 1, R = k;

        // Binary search for maximum submedian
        while (low <= high) {
            int mid = (low + high) / 2;
            int l = -1, r = -1;

            if (check(mid, l, r)) {
                vmax = mid;
                L = l;
                R = r;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        // Output all submedians
        cout << vmax << "\n";
        for (int v = 1; v <= vmax; v++) {
            cout << v << " " << L << " " << R << "\n";
        }
    }

    return 0;
}