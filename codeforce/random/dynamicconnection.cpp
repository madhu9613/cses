#include <bits/stdc++.h>
using namespace std;

struct Change {
    int v, old;
    bool isParent;
};

struct DSU {
    vector<int> parent, sz;
    vector<Change> changes;

    DSU(int n) {
        parent.resize(n);
        sz.assign(n, 1);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int x) {
        while (parent[x] != x) x = parent[x];
        return x;
    }

    void unite(int x, int y) {
        x = find(x); y = find(y);
        if (x == y) return;
        if (sz[x] < sz[y]) swap(x, y);

        changes.push_back({ y, parent[y], true });
        parent[y] = x;

        changes.push_back({ x, sz[x], false });
        sz[x] += sz[y];
    }

    int snapshot() {
        return changes.size();
    }

    void rollback(int snap) {
        while ((int)changes.size() > snap) {
            auto c = changes.back();
            changes.pop_back();
            if (c.isParent)
                parent[c.v] = c.old;
            else
                sz[c.v] = c.old;
        }
    }
};

struct Edge { int u, v; };
struct Query { string type; int u, v; };

int N, M;
vector<Query> queries;
vector<vector<Edge>> segTree;

void addInterval(int node, int l, int r, int ql, int qr, Edge e) {
    if (qr <= l || r <= ql) return;
    if (ql <= l && r <= qr) {
        segTree[node].push_back(e);
        return;
    }
    int mid = (l + r) / 2;
    addInterval(node * 2, l, mid, ql, qr, e);
    addInterval(node * 2 + 1, mid, r, ql, qr, e);
}

void dfs(int node, int l, int r, DSU& dsu, vector<string>& ans) {
    int snap = dsu.snapshot();

    for (auto& e : segTree[node])
        dsu.unite(e.u, e.v);

    if (l + 1 == r) {
        if (l < M && queries[l].type == "conn") {
            ans.push_back(
                dsu.find(queries[l].u) == dsu.find(queries[l].v)
                ? "YES" : "NO"
            );
        }
    }
    else {
        int mid = (l + r) / 2;
        dfs(node * 2, l, mid, dsu, ans);
        dfs(node * 2 + 1, mid, r, dsu, ans);
    }

    dsu.rollback(snap);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    queries.resize(M);

    for (int i = 0; i < M; i++) {
        cin >> queries[i].type >> queries[i].u >> queries[i].v;
        queries[i].u--; queries[i].v--;
        if (queries[i].u > queries[i].v)
            swap(queries[i].u, queries[i].v);
    }

    map<pair<int, int>, int> last;
    vector<pair<Edge, pair<int, int>>> intervals;

    for (int i = 0; i < M; i++) {
        auto& q = queries[i];
        if (q.type == "add") {
            last[{q.u, q.v}] = i;
        }
        else if (q.type == "rem") {
            int st = last[{q.u, q.v}];
            intervals.push_back({ {q.u, q.v}, {st, i} });
            last.erase({ q.u, q.v });
        }
    }

    for (auto& p : last)
        intervals.push_back({ {p.first.first, p.first.second}, {p.second, M} });

    int SZ = 1;
    while (SZ < M) SZ <<= 1;
    segTree.resize(2 * SZ);

    for (auto& it : intervals)
        addInterval(1, 0, SZ, it.second.first, it.second.second, it.first);

    DSU dsu(N);
    vector<string> ans;
    dfs(1, 0, SZ, dsu, ans);

    for (auto& s : ans)
        cout << s << "\n";
}
