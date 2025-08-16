#include <bits/stdc++.h>
using namespace std;

#define INF INT_MAX

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> resv(n), freec(m);
    for (int i = 0; i < n; i++) cin >> resv[i].first >> resv[i].second;
    for (int i = 0; i < m; i++) cin >> freec[i].first >> freec[i].second;

    vector<int> mindist(m, INF);

    vector<array<int,4>> pts;
    pts.reserve(n + m);
    for (auto &p : resv) pts.push_back({p.first, 0, p.second, -1});
    for (int i = 0; i < m; ++i) {
        auto [x,y] = freec[i];
        pts.push_back({x, 1, y, i});
    }

    auto sweep = [&](bool revX, bool revY) {
        sort(pts.begin(), pts.end(), [&](auto &a, auto &b) {
            if (a[0] != b[0]) return revX ? a[0] > b[0] : a[0] < b[0];
            return revY ? a[2] > b[2] : a[2] < b[2];
        });

        set<pair<int,int>> s; // {y, x}
        for (auto &arr : pts) {
            int x = arr[0], type = arr[1], y = arr[2], id = arr[3];
            if (type == 0) {
                s.insert({y, x});
            } else {
                if (!s.empty()) {
                    auto it = s.lower_bound({y, INT_MIN});
                    if (it != s.end())
                        mindist[id] = min(mindist[id], abs(it->first - y) + abs(it->second - x));
                    if (it != s.begin()) {
                        --it;
                        mindist[id] = min(mindist[id], abs(it->first - y) + abs(it->second - x));
                    }
                }
            }
        }
    };

    // 4 directional sweeps
    sweep(false, false);
    sweep(false, true);
    sweep(true, false);
    sweep(true, true);

    for (int d : mindist) cout << d << " ";
    cout << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
