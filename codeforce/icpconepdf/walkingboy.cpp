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

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

const int MOD = 1e9 + 7;
const int INF = INT_MAX;
const ll LINF = 1e18;

const int MAXN = 40005;

void solve() {
    int n;cin >> n;
    vi a(n);
    for (int i = 0;i < n;i++)
    {
        cin >> a[i];
    }
    int last=a[n-1];
    int first=a[0];
    int c = 0;
    int found = false;
    a.insert(a.begin(),0);
    a.push_back(1440);
    for (int i = 0;i < n+1;i++)
    {
        if ((a[i + 1] - a[i]) >= 240)
        {
            found = true;
            break;
        }
        if ((a[i + 1] - a[i]) >= 120)
        {
            c++;
            if (c == 2)
            {
                found = true;
                break;
            }
        }
    }
    if(found)
    {
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
   

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--)
        solve();

    return 0;
}