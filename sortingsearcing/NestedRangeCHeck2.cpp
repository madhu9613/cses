#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define ll long long
#define pb push_back
#define pii pair<ll, ll>

template<typename T>
using ordered_multiset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<tuple<ll, ll, int>> ranges(n);
    vector<ll> all_r;

    for (int i = 0; i < n; ++i) {
        ll l, r;
        cin >> l >> r;
        ranges[i] = {l, r, i};
        all_r.pb(r);
    }

    // Coordinate compression of r values
    sort(all_r.begin(), all_r.end());
    all_r.erase(unique(all_r.begin(), all_r.end()), all_r.end());

    auto compress = [&](ll x) {
        return lower_bound(all_r.begin(), all_r.end(), x) - all_r.begin();
    };

    vector<int> contains(n), contained_by(n);

    // --- Part 1: count how many ranges each range contains ---
    sort(ranges.begin(), ranges.end(), [&](auto &a, auto &b) {
        if (get<0>(a) != get<0>(b)) return get<0>(a) > get<0>(b); // descending l
        return get<1>(a) < get<1>(b);                             // ascending r
    });

    ordered_multiset<pii> os1;
    for (auto &[l, r, idx] : ranges) {
        int cr = compress(r);
        // Count of r <= current r
        contains[idx] = os1.order_of_key({cr + 1, 0});
        os1.insert({cr, idx});
    }

    // --- Part 2: count how many ranges contain each range ---
    sort(ranges.begin(), ranges.end(), [&](auto &a, auto &b) {
        if (get<0>(a) != get<0>(b)) return get<0>(a) < get<0>(b); // ascending l
        return get<1>(a) > get<1>(b);                             // descending r
    });

    ordered_multiset<pii> os2;
    for (auto &[l, r, idx] : ranges) {
        int cr = compress(r);
        // Count of r >= current r
        contained_by[idx] = os2.size() - os2.order_of_key({cr, 0});
        os2.insert({cr, idx});
    }

    for (int x : contains) cout << x << " ";
    cout << '\n';
    for (int x : contained_by) cout << x << " ";
    cout << '\n';

    return 0;
}
