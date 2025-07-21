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
    ll n,m,k;cin>>n>>m>>k;
    vll a(n),b(m);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<m;i++) cin>>b[i];
    sort(all(a));
    sort(all(b));
// i will try to give small appertment to the person whose desired is less.if we cant give this to him we cant sell to other with greater desire 

int sell=0;
int i=0,j=0;
while (i<n && j<m)
{
    //can i give jth appertment to ith person
    if(b[j]>=(a[i]-k) && b[j]<=(a[i]+k))
    {
        i++;
        j++;
        sell++;

    }else if(b[j]<a[i]-k){
        j++;
        //why i need as if i do j++ without this check i may losse a soltion as this is large ennough for a[i];
    }
    else{
        i++;
    }

}
cout<<sell<<endl;




}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    while (t--) solve();
    return 0;
}