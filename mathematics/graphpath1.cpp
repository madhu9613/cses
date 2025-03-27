#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int MAXN = 100;

int n, m, k;
vector<vector<long long>> adj(MAXN, vector<long long>(MAXN, 0));

// Multiply two matrices under modulo
vector<vector<long long>> multiply(const vector<vector<long long>> &A, const vector<vector<long long>> &B) {
    vector<vector<long long>> C(n, vector<long long>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int p = 0; p < n; p++) {
                C[i][j] = (C[i][j] + A[i][p] * B[p][j]) % MOD;
            }
        }
    }
    return C;
}

// Matrix exponentiation
vector<vector<long long>> matrix_exponentiation(vector<vector<long long>> A, long long exp) {
    vector<vector<long long>> res(n, vector<long long>(n, 0));
    
    // Identity matrix
    for (int i = 0; i < n; i++) 
        res[i][i] = 1;

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
        cin >> a >> b;
        adj[a - 1][b - 1]++; // Convert to 0-based index
    }
    
    vector<vector<long long>> result = matrix_exponentiation(adj, k);
    cout << result[0][n - 1] << endl;
    return 0;
}
