#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18; // Increased to handle large numbers properly
const int MAXN = 100;

int n, m;
long long k;
vector<vector<long long>> adj(MAXN, vector<long long>(MAXN, INF));

// Min-Plus Multiplication for matrices
vector<vector<long long>> multiply(const vector<vector<long long>> &A, const vector<vector<long long>> &B) {
    vector<vector<long long>> C(n, vector<long long>(n, INF));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int p = 0; p < n; p++) {
                if (A[i][p] < INF && B[p][j] < INF) {
                    C[i][j] = min(C[i][j], A[i][p] + B[p][j]);
                }
            }
        }
    }
    return C;
}

// Matrix exponentiation
vector<vector<long long>> matrix_exponentiation(vector<vector<long long>> A, long long exp) {
    vector<vector<long long>> res(n, vector<long long>(n, INF));

    // Identity matrix for min-plus multiplication (all INF except diagonal 0)
    for (int i = 0; i < n; i++)
        res[i][i] = 0;

    while (exp) {
        if (exp % 2) res = multiply(res, A);
        A = multiply(A, A);
        exp /= 2;
    }
    return res;
}

int main() {
    cin >> n >> m >> k;

    for (int i = 0; i < m; i++) {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        a--, b--; // Convert to 0-based index
        adj[a][b] = min(adj[a][b], c); // Store minimum edge weight
    }

    vector<vector<long long>> result = matrix_exponentiation(adj, k);
    
    long long answer = result[0][n - 1];
    cout << (answer >= INF ? -1 : answer) << endl; // Ensure proper output formatting

    return 0;
}