#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INFLL = (ll)4e18;

struct SegTree {
    int n;
    vector<ll> st;
    SegTree(int sz = 0) {
        n = 1;
        while (n < sz) n <<= 1;
        st.assign(2*n, INFLL);
    }
    void reset(int sz) {
        n = 1;
        while (n < sz) n <<= 1;
        st.assign(2*n, INFLL);
    }
    void update(int pos, ll val) {
        pos += n;
        if (st[pos] <= val) return;
        st[pos] = val;
        for (pos >>= 1; pos; pos >>= 1)
            st[pos] = min(st[2*pos], st[2*pos + 1]);
    }
    ll query(int l, int r) {
        if (l > r) return INFLL;
        l += n; r += n;
        ll res = INFLL;
        while (l <= r) {
            if (l & 1) res = min(res, st[l++]);
            if (!(r & 1)) res = min(res, st[r--]);
            l >>= 1; r >>= 1;
        }
        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    if (!(cin >> n >> m)) return 0;
    vector<pair<int,int>> resv(n), freec(m);
    for (int i = 0; i < n; ++i) cin >> resv[i].first >> resv[i].second;
    for (int i = 0; i < m; ++i) cin >> freec[i].first >> freec[i].second;

    vector<ll> mindist(m, INFLL);

    // 4 sign combinations (sx, sy) in {-1, +1}
    for (int sx : {1, -1}) {
        for (int sy : {1, -1}) {
            // build events and y-list (transformed)
            vector<tuple<int,int,int>> ev; // (x', y', id) id=-1 => reserved, else query id
            ev.reserve(n + m);
            vector<int> ys; ys.reserve(n + m);

            for (auto &p : resv) {
                int xp = sx * p.first;
                int yp = sy * p.second;
                ev.emplace_back(xp, yp, -1);
                ys.push_back(yp);
            }
            for (int i = 0; i < m; ++i) {
                int xp = sx * freec[i].first;
                int yp = sy * freec[i].second;
                ev.emplace_back(xp, yp, i);
                ys.push_back(yp);
            }

            sort(ys.begin(), ys.end());
            ys.erase(unique(ys.begin(), ys.end()), ys.end());
            auto getYidx = [&](int y) {
                return int(lower_bound(ys.begin(), ys.end(), y) - ys.begin());
            };

            // sort events by x' descending; when x' equal, reserved (id==-1) must come BEFORE queries
            sort(ev.begin(), ev.end(), [](const auto &a, const auto &b) {
                if (get<0>(a) != get<0>(b)) return get<0>(a) > get<0>(b);
                return get<2>(a) < get<2>(b); // -1 (reserved) first
            });

            SegTree seg((int)ys.size());
            for (auto &t : ev) {
                int x = get<0>(t), y = get<1>(t), id = get<2>(t);
                int yi = getYidx(y);
                if (id == -1) {
                    // reserved point: store x'+y' at y-index
                    seg.update(yi, (ll)x + (ll)y);
                } else {
                    // query: want min over y' >= y  of (x'+y')  => suffix min
                    ll best = seg.query(yi, (int)ys.size() - 1);
                    if (best != INFLL) {
                        ll cand = best - ((ll)x + (ll)y); // (x'+y') - (x'+y')
                        if (cand < mindist[id]) mindist[id] = cand;
                    }
                }
            }
        }
    }

    // print results (in input order)
    for (int i = 0; i < m; ++i) {
        // constraints guarantee at least one reserved point; mindist should be finite.
        cout << mindist[i] << (i + 1 == m ? '\n' : ' ');
    }
    return 0;
}
