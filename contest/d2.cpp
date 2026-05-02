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

// Fast exponentiation (a^b % mod)
ll modpow(ll a, ll b, ll mod = MOD)
{
    ll res = 1;
    while (b)
    {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

ll modinv(ll a, ll mod = MOD)
{
    return modpow(a, mod - 2, mod);
}

// GCD
ll gcd(ll a, ll b)
{
    return b ? gcd(b, a % b) : a;
}

// LCM
ll lcm(ll a, ll b)
{
    return a / gcd(a, b) * b;
}

bool ask(const vi &v)
{
    cout << "? " << v.size();
    for (auto x : v)
    {
        cout << " " << x;
    }
    cout << endl;
    cout.flush();

    int f;
    cin >> f;
    if (f == -1)
    {
        exit(0);
    }
    return (((int)v.size() + f) % 2 == 1);
}

void solve()
{
    int n;
    cin >> n;

    int total = 2 * n + 1;

   
    int lo = 1, hi = total;
    while (lo < hi)
    {
        int mid = (lo + hi) / 2;

        vi s;
        for (int i = 1; i <= mid; i++)
        {
            s.push_back(i);
        }

        if (ask(s))
        {
            hi = mid;
        }
        else
        {
            lo = mid + 1;
        }
    }
    int r = lo;

    lo = 1, hi = total;
    while (lo < hi)
    {
        int mid = (lo + hi + 1) / 2;

        vi s;
        for (int i = mid; i <= total; i++)
        {
            s.push_back(i);
        }

        if (ask(s))
        {
            lo = mid;
        }
        else
        {
            hi = mid - 1;
        }
    }
    int l = lo;
    lo = l + 1;
    hi = r - 1;

    while (lo < hi)
    {
        int mid = (lo + hi) / 2;

        vi s;
        s.push_back(l);

        for (int i = l + 1; i <= mid; i++)
        {
            s.push_back(i);
        }

        s.push_back(r);

        if (ask(s))
        {
            hi = mid;
        }
        else
        {
            lo = mid + 1;
        }
    }
    int m = lo;

    cout << "! " << l << " " << m << " " << r << endl;
    cout.flush();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}