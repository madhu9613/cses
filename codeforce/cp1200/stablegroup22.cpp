#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    
        ll n, k, x;
        cin >> n >> k >> x;
        vector<ll> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        sort(a.begin(), a.end());

        vector<ll> insert_needed;

        for (int i = 1; i < n; i++) {
            ll diff = a[i] - a[i - 1];
            if (diff > x) {
                // how many students needed to fill the gap
                ll need = (diff + x - 1) / x - 1;
                insert_needed.push_back(need);
            }
        }

        // total groups = 1 + number of big gaps
        ll groups = 1 + insert_needed.size();

        // sort by minimal insertions needed
        sort(insert_needed.begin(), insert_needed.end());

        for (ll need : insert_needed) {
            if (k >= need) {
                k -= need;
                groups--; // merged group
            } else {
                break;
            }
        }

        cout << groups << '\n';
    

    return 0;
}
