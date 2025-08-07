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


//2x ,4x or 8x; division allowed is amodk=0;

//a->b operation needed;

// power of 2 in a and b; if a has x1 power of 2 and 

map<int, int> factors(int n) {
    map<int, int> f;
    for (int x = 2; x * x <= n; x++) {
        while (n % x == 0) {
            f[x]++;
            n /= x;
        }
    }
    if (n > 1) f[n]++; 
    return f;
}

void solve() {

    ll a,b;cin>>a>>b;
    if(a==b)
    {
        cout<<0<<endl;
        return;
    }

    ll mini=min(a,b);
    ll maxi=max(a,b);
    if(maxi%mini!=0)
    {
        cout<<-1<<endl;
        return ;
    }
    ll diff=maxi/mini;
    if((diff & (diff-1))!=0)
    {

        cout<<-1<<endl;
    }else{

        ll logval=log2(diff);
        if(logval%3==0)
        {
            cout<<logval/3<<endl;
        }else{
            cout<<logval/3+1<<endl;
        }
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}