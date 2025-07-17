#include <bits/stdc++.h>
using namespace std;

vector<int> par, size;
int components, max_size = 1;

int find(int x) {
    if (par[x] != x)
        par[x] = find(par[x]);
    return par[x];
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) {
        if (size[a] < size[b])
            swap(a, b);
        par[b] = a;
        size[a] += size[b];
        components--;
        max_size = max(max_size, size[a]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    par.resize(n + 1);
    size.resize(n + 1, 1);

    for (int i = 1; i <= n; i++)
        par[i] = i;

    components = n;

    while (m--) {
        int a, b;
        cin >> a >> b;
        unite(a, b);
        cout << components << " " << max_size << '\n';
    }

    return 0;
}
