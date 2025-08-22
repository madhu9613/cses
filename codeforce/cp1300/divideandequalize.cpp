#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define max3(a, b, c) max(max(a, b), c)
#define max4(a, b, c, d) max(max(a, b), max(c, d))
#define pii pair<int,int>
#define pll pair<ll,ll>
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

void countdivs(int x,map<int,int>&divs)
{
    int i=2;
    while (i*i<=x)
    {
        while (x%i==0)
        {
            divs[i]++;

            x/=i;
        }
        i++;
        
    }
    if(x>1) divs[x]++;
    
}

void solve() {
    int n;cin>>n;
    vi a(n);
    map<int,int>divs;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        countdivs(a[i],divs);

    }
    for(auto e:divs)
    {
        if(e.second%n!=0) 
        {
            cout<<"NO"<<endl;
            return;
        }
        
    }
    cout<<"YES"<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
