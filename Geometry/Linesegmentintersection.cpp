#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll orient(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
    ll vx1 = x2 - x1;
    ll vy1 = y2 - y1;
    ll vx2 = x3 - x1;
    ll vy2 = y3 - y1;
    return vx1 * vy2 - vy1 * vx2;
}

bool onSegment(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
    return min(x1, x2) <= x3 && x3 <= max(x1, x2) &&
           min(y1, y2) <= y3 && y3 <= max(y1, y2);
}

void solve() {
    ll x1, y1, x2, y2, x3, y3, x4, y4;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

    ll o1 = orient(x1, y1, x2, y2, x3, y3);
    ll o2 = orient(x1, y1, x2, y2, x4, y4);
    ll o3 = orient(x3, y3, x4, y4, x1, y1);
    ll o4 = orient(x3, y3, x4, y4, x2, y2);

    if ((o1 > 0 && o2 < 0 || o1 < 0 && o2 > 0) &&
        (o3 > 0 && o4 < 0 || o3 < 0 && o4 > 0)) {
        cout << "YES\n";
        return;
    }

    // Special case: collinear and overlapping
    if (o1 == 0 && onSegment(x1, y1, x2, y2, x3, y3)) { cout << "YES\n"; return; }
    if (o2 == 0 && onSegment(x1, y1, x2, y2, x4, y4)) { cout << "YES\n"; return; }
    if (o3 == 0 && onSegment(x3, y3, x4, y4, x1, y1)) { cout << "YES\n"; return; }
    if (o4 == 0 && onSegment(x3, y3, x4, y4, x2, y2)) { cout << "YES\n"; return; }

    cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
