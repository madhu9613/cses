#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int& x : a) cin >> x;

    unordered_map<int, int> freq;
    vector<int> result;

    for (int i = 0; i < n; ++i) {
        freq[a[i]]++;

        if (i >= k)
        {
            freq[a[i - k]]--;
            if (freq[a[i - k]] == 0)
                freq.erase(a[i - k]);
        }

        if (i >= k - 1)
            result.push_back(freq.size());
    }

    for (int x : result)
        cout << x << " ";
    cout << "\n";

    return 0;
}
