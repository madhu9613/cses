#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define max3(a, b, c) max(max(a, b), c)
#define max4(a, b, c, d) max(max(a, b), max(c, d))
#define pii pair<int, int>
#define pll pair<ll, ll>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endl '\n'

ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
}
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
const int MOD = 1e9 + 7;
const int INF = INT_MAX;
const ll LINF = 1e18;

struct Matrix
{
    int n, m;
    vector<vector<ll>> mat;

    Matrix(int _n, int _m, ll val = 0) : n(_n), m(_m)
    {
        mat.assign(n, vector<ll>(m, val));
    }

    static Matrix identity(int size)
    {
        Matrix I(size, size, 0);
        for (int i = 0; i < size; i++)
            I.mat[i][i] = 1;
        return I;
    }

    Matrix operator*(const Matrix &other) const
    {
        assert(m == other.n);
        Matrix res(n, other.m, 0);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < other.m; j++)
            {
                for (int k = 0; k < m; k++)
                {
                    res.mat[i][j] = (res.mat[i][j] + mat[i][k] * other.mat[k][j]) % MOD;
                }
            }
        }
        return res;
    }

    Matrix pow(ll K) const
    {
        assert(n == m);
        Matrix res = identity(n);
        Matrix base = *this;
        while (K)
        {
            if (K & 1)
                res = res * base;
            base = base * base;
            K >>= 1;
        }
        return res;
    }
};

void solve()
{
    int n;
    ll k;
    cin >> n >> k;
    Matrix adj(n, n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> adj.mat[i][j];
        }
    }

    Matrix res = adj.pow(k);
    ll total = 0;
    for (int i = 0; i < n; i++)

    {
        for (int j = 0; j < n; j++)

        {
            total = (total + res.mat[i][j]) % MOD;
        }
    }

    cout<<total<<endl;
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