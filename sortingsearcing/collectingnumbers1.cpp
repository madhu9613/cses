// Author: Madhujya Rajkhowa
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define all(x) (x).begin(), (x).end()
#define endl '\n'

const int MOD = 1e9 + 7;
const int INF = INT_MAX;

void solve() {
int n;cin>>n;
vi a(n);for(int i=1;i<=n;i++) cin>>a[i];
vi pos(n+1); for(int i=1;i<=n;i++) {pos[a[i]]=i;}
//i need to collect first 1.2.3.4.... i mean before collecting x i need to collect x-1;for eg: if 2 appear before 1 i need  a extra round if 2 appear after 1 i can collect them in one go

int round=1;
for(int i=2;i<=n;i++)
{
   if(pos[i]<pos[i-1]) round++;
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