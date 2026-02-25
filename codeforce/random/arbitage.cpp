#include <bits/stdc++.h>
using namespace std;

struct edge {
    int u, v;
    double w;
};

int main() {
  

    int n;
    int caseno = 1;

    while (cin >> n && n) {
        unordered_map<string, int> id;
        for (int i = 0; i < n; i++) {
            string name;
            cin >> name;
            id[name] = i;
        }

        int m;
        cin >> m;

        vector<edge> edges;
        for (int i = 0; i < m; i++) {
            string a, b;
            double r;
            cin >> a >> r >> b;
            edges.push_back({ id[a], id[b], -log(r) });
        }

        vector<double> dist(n, 0.0);
        bool arbitrage = false;
        const double EPS = 1e-12;

        for (int i = 0; i < n; i++) {
            bool updated = false;
            for (auto& e : edges) {
                if (dist[e.v] > dist[e.u] + e.w + EPS) {
                    dist[e.v] = dist[e.u] + e.w;
                    updated = true;
                    if (i == n - 1) {
                        arbitrage = true;
                        break;
                    }
                }
            }
            if (!updated) break;
        }

        cout << "Case " << caseno++ << ": "
            << (arbitrage ? "Yes" : "No") << "\n";
    }

    return 0;
}
