#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXA = 1000000;

ll lpf[MAXA + 1];   
ll mobius[MAXA + 1]; 
ll freq[MAXA + 1];  

void build_lpf()
{
    lpf[1] = 1;
    for (int i = 2; i <= MAXA; i++)
    {
        if (lpf[i] == 0)
        { // i is prime
            for (int j = i; j <= MAXA; j += i)
            {
                if (lpf[j] == 0)
                    lpf[j] = i;
            }
        }
    }
}

void build_mobius()
{
    mobius[1] = 1;
    for (int i = 2; i <= MAXA; i++)
    {
        int p = lpf[i];
        int x = i / p;
        if (lpf[x] == p) 
            mobius[i] = 0;
        else
            mobius[i] = -mobius[x];
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int mx = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        freq[x]++;
        mx = max(mx, x);
    }

    build_lpf();
    build_mobius();

    ll ans = 0;

    for (int d = 1; d <= mx; d++)
    {
        if (mobius[d] == 0)
            continue;

        ll cnt = 0;
        for (int j = d; j <= mx; j += d)
        {
            cnt += freq[j];
        }

        ans += mobius[d] * (cnt * (cnt - 1) / 2);
    }

    cout << ans << "\n";
}
