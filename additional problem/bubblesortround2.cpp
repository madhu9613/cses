#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define max3(a, b, c) max(max(a, b), c)
#define max4(a, b, c, d) max(max(a, b), max(c, d))
#define pii pair<int,int>
#define all(x) (x).begin(), (x).end()
#define endl '\n'

ll gcd(ll a, ll b)
{
 return b == 0 ? a : gcd(b, a % b);
}
const int MOD = 1e9 + 7;
const int INF = INT_MAX;

void solve() {
    int n,k;cin>>n>>k;
    vi a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    priority_queue<int,vi,greater<int>>pq;
    for(int i=0;i<n;++i)
    {
        pq.push(a[i]);
        if((int)pq.size()>k)
        {
            cout<<pq.top()<<" ";
            pq.pop();
        }
    }

    vi lastk;
    while (!pq.empty())
    {
     lastk.pb(pq.top());
        pq.pop();
    }
   
    sort(all(lastk));
    for(int x:lastk) cout<<x<<" ";
    cout<<endl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;

    while (t--) solve();
    return 0;
}