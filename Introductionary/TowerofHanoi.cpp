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
void toh(int n,int left,int mid,int right)
{
    if(n==0) return;
    toh(n-1,left,right,mid);
    cout<<left<<" "<<right<<" "<<endl;
    toh(n-1,mid,left,right);
}
void solve() {
    int n;cin>>n;
    cout<<(1<<n)-1<<endl;
    toh(n,1,2,3);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    while (t--) solve();
    return 0;
}