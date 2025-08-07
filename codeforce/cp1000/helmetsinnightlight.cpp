#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define max3(a, b, c) max(max(a, b), c)
#define max4(a, b, c, d) max(max(a, b), max(c, d))
#define pii pair<int, int>
#define all(x) (x).begin(), (x).end()
#define endl '\n'

ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
}
const int MOD = 1e9 + 7;
const int INF = INT_MAX;

void solve()
{
    int n, k;
    cin >> n >> k;
    vll a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];

    vector<pair<ll, ll>> people(n);
    for (int i = 0; i < n; i++)
    {
        people[i] = {b[i], a[i]};
    }
    sort(all(people));

    ll cost = k;
    int shared = 1;

       
    for (auto it : people)
    {
        ll ittake = it.first;
        ll itcanshare = it.second;

        if(ittake>=k)
        {
            break;
        }
        if (shared + itcanshare > n)
        {
            cost+=(n-shared)*1LL*ittake;
            shared=n;
        }else{
        
            cost+=1LL*itcanshare*ittake;
            shared+=itcanshare;

        }
    }

    cost+=1LL*(n-shared)*k;
    cout<<cost<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}