#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define vi vector<int>
#define vll vector<ll>
#define vpi vector<pii>
#define vpll vector<pll>

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

const ll INF = 1e18;
const int MOD = 1000000007;

// GCD
ll gcd(ll a, ll b)
{
    return b ? gcd(b, a % b) : a;
}

// LCM
ll lcm(ll a, ll b)
{
    if (a == 0 || b == 0)
        return 0;
    return (a / gcd(a, b)) * b;
}

void solve()
{
    int n;
    cin >> n;

    vll a(n), b(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
       
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
        

    vll g(n - 1);
    for (int i = 0; i < n - 1; i++)
    {
        g[i] = gcd(a[i], a[i + 1]);
    }

    vll L(n);
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            L[i] = g[0];
        }
           
        else if (i == n - 1)
        {
            L[i] = g[n - 2];
        }
           
        else
           {
               L[i] = lcm(g[i - 1], g[i]);
           }
    }

    vll left(n - 1), right(n);
    for (int i = 0; i < n - 1; i++)
    {
        left[i] = L[i] / g[i];
        right[i + 1] = L[i + 1] / g[i];
    }

    vll pp;
    for (ll p = 2; p <= 300; p++)
    {
        bool isPrime = true;
        for (ll j = 2; j * j <= p; j++)
        {
            if (p % j == 0)
            {
                isPrime = false;
                break;
            }
        }
        if (isPrime)
            pp.push_back(p);
    }

    unordered_map<ll, int> cmap;

    auto addcnd = [&](ll k, int gain)
    {
        if (cmap.find(k) == cmap.end())
            cmap[k] = gain;
        else
            cmap[k] = max(cmap[k], gain);
    };

    ll max_k0 = b[0] / L[0];

    addcnd(a[0] / L[0], 0);

    
    if (max_k0 >= 1)
    {
        int gain = (a[0] == L[0] ? 0 : 1);
        addcnd(1, gain);

        if (gain == 0)
        {
            int cnt = 0;
            for (ll p : pp)
            {
                if (p > max_k0)
                    break;
                if (n > 1 && right[1] % p == 0)
                    continue;
                addcnd(p, 1);
                cnt++;
                if (cnt == 30)
                    break;
            }
        }
    }

    vector<pair<ll, int>> dp(all(cmap));

    for (int i = 1; i < n; i++)
    {
        cmap.clear();

        ll max_k = b[i] / L[i];

    
        addcnd(a[i] / L[i], 0);

       
        if (max_k >= 1)
        {
            int gain = (a[i] == L[i] ? 0 : 1);
            addcnd(1, gain);

            if (gain == 0)
            {
                int cnt = 0;
                for (ll p : pp)
                {
                    if (p > max_k)
                        break;

                    bool ok = true;
                    if (i < n - 1 && right[i + 1] % p == 0)
                        ok = false;
                    if (left[i - 1] % p == 0)
                        ok = false;

                    if (ok)
                    {
                        addcnd(p, 1);
                        cnt++;
                        if (cnt == 30)
                            break;
                    }
                }
            }
        }

        vector<pair<ll, int>> ndp;

        for (auto &curr : cmap)
        {
            ll k_curr = curr.first;
            int gain_curr = curr.second;

            int best_prev = -1;

            for (auto &prev : dp)
            {
                if (gcd(k_curr, prev.first) == 1)
                {
                    best_prev = max(best_prev, prev.second);
                }
            }

            if (best_prev != -1)
            {
                ndp.push_back({k_curr, best_prev + gain_curr});
            }
        }

        dp = move(ndp);
    }

    int ans = 0;
    for (auto &p : dp)
    {
        ans = max(ans, p.second);
    }

    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}