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
    int n;cin>>n;
    //if i go and write code for bubble sort it will slow o(n^2) i mean bad ;
    vi a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    vi sorteda=a;
    sort(all(sorteda));
     unordered_map<int,queue<int>>posmap;
     for(int i=0;i<n;i++)
     {
        posmap[sorteda[i]].push(i);
     }
     int round=0;
     for(int i=0;i<n;i++)
     {
        int sortedpos=posmap[a[i]].front();
        posmap[a[i]].pop();
        round=max(round,i-sortedpos);
     }

     cout<<round<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
 
    while (t--) solve();
    return 0;
}