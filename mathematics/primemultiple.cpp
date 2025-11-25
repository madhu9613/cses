#include <bits/stdc++.h>
using namespace std;
using vll = vector<long long>;

#define ll long long
using i128 = __int128_t;

i128 LCM(i128 a, i128 b)
{
    return a / __gcd((ll)a, (ll)b) * b;
}

void solve()
{
  
    ll n, k;
    cin >> n >> k;
    ll a[k];
    for (int i = 0; i < k; i++)
    {
        cin >> a[i];
    }
    ll ans = 0;
    for (int i = 0; i < (1ll << k); i++)
    {
        vll v;
        for (int j = 0; j < k; j++)
        {
            if ((i & (1 << j)) != 0)
            {
                v.push_back(a[j]);
            }
        }
        ll prod = 1;
        for (int j = 0; j < v.size(); j++)
        {
            if (prod > n / v[j])
            {
                prod = n + 1;
                break;
            }
            prod *= v[j];
        }
        if (v.size() % 2 == 0)
            ans -= n / prod;
        else
            ans += n / prod;
    }
    ans += n;
    cout << ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
