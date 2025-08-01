#include <bits/stdc++.h>
using namespace std;

#define pb push_back
int n;
vector<vector<string>> solutions;
vector<string> borad;

bool isSafe(int r, int c)
{
    for (int i = 0; i < r; i++)
        if (borad[i][c] == 'Q') return false;

    for (int i = r - 1, j = c - 1; i >= 0 && j >= 0; i--, j--)
        if (borad[i][j] == 'Q') return false;

    for (int i = r - 1, j = c + 1; i >= 0 && j < n; i--, j++)
        if (borad[i][j] == 'Q') return false;

    return true;
}

void dfs(int r)
{
    if (r == n)
    {
        solutions.pb(borad);
        return;
    }

    for (int c = 0; c < n; c++)
    {
        if (isSafe(r, c))
        {
            borad[r][c] = 'Q';
            dfs(r + 1);
            borad[r][c] = '.';
        }
    }
}

void solve()
{
    cin >> n;
    borad = vector<string>(n, string(n, '.'));
    dfs(0);

   
    cout << "Number of solutions: " << solutions.size() << "\n";
    for (auto &sol : solutions)
    {
        for (auto &row : sol)
            cout << row << "\n";
        cout << "\n";
        break;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
