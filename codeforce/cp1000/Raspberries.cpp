#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define endl '\n'

void solve(int n, int k, const vi &a)
{
    int mini = INT_MAX;
    int evenc = 0;

    for (int val : a)
    {
        if (val % 2 == 0)
            evenc++;

        int mod_val = (k - (val % k)) % k;
        mini = min(mini, mod_val);
        if (mod_val == 0)
        {
            cout << 0 << endl;
            return;
        }
    }

    if (k == 4)
    {
        if (evenc == 0)
        {
            cout << min(2, mini) << endl;
        }
        else if (evenc == 1)
        {
            if (n > 1)
                cout << min(1, mini) << endl;
            else
                cout << (k - (a[0] % k)) % k << endl;
        }
        else
        {
            cout << 0 << endl;
        }
    }
    else
    {
        cout << mini << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vi a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        solve(n, k, a);
    }

    return 0;
}
