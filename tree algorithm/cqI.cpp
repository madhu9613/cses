#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 200005;
const int MAX_LOG = 18;

int parent[MAX_N][MAX_LOG];
int depth[MAX_N];


void preprocess(int n) {
    for (int j = 1; j < MAX_LOG; ++j) {
        for (int i = 1; i <= n; ++i) {
            if (parent[i][j-1] != -1) {
                parent[i][j] = parent[parent[i][j-1]][j-1];
            }
        }
    }
}


int find_kth_ancestor(int x, int k) {
    for (int i = 0; i < MAX_LOG; ++i) {
        if (k & (1 << i)) {
            x = parent[x][i];
            if (x == -1) return -1;
        }
    }
    return x;
}

int main()
{
    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < MAX_LOG; j++)
        {
            parent[i][j] = -1;
        }
    }
    for (int i = 2; i <= n; ++i)
    {
        int boss;
        cin >> boss;
        parent[i][0] = boss;
    }
      preprocess(n);
    
    while (q--) {
        int x, k;
        cin >> x >> k;
        cout << find_kth_ancestor(x, k) << '\n';
    }

    return 0;
}