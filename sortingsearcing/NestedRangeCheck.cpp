// Author: Madhujya Rajkhowa
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define all(x) (x).begin(), (x).end()
#define endl '\n'

const int MOD = 1e9 + 7;
const int INF = INT_MAX;

typedef struct
{
    ll l;
    ll r;
    int idx;
} Range;

void solve() {
    int n;
    cin >> n;
    vector<Range> ranges(n);
    for (int i = 0; i < n; ++i) {
        cin >> ranges[i].l >> ranges[i].r;
        ranges[i].idx = i;
    }

    vi is_covered(n, 0);  
    vi covers(n, 0);     
    // Part 1: Check if this interval is covered by another
    {
        sort(all(ranges), [](const Range &a, const Range &b) {
            if (a.l == b.l) return a.r > b.r; 
            return a.l < b.l;                
        });

        ll max_r = -1;
        for (int i = 0; i < n; ++i) {
            if (ranges[i].r <= max_r)
                is_covered[ranges[i].idx] = 1;
            max_r = max(max_r, ranges[i].r);
        }
    }

    // Part 2: Check if this interval covers another
    {
        sort(all(ranges), [](const Range &a, const Range &b) {
            if (a.l == b.l) return a.r < b.r; // tie-break by ascending r
            return a.l > b.l;                 // decreasing l
        });

        ll min_r = INF;
        for (int i = 0; i < n; ++i) {
            if (ranges[i].r >= min_r)
                covers[ranges[i].idx] = 1;
            min_r = min(min_r, ranges[i].r);
        }
    }

    // Output
    for (int x : covers) cout << x << " ";
    cout << '\n';
    for (int x : is_covered) cout << x << " ";
    cout << '\n';
}



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    while (t--)
        solve();
    return 0;
}