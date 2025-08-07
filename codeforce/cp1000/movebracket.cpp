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
int n;cin>>n;string s;cin>>s;
vi opening(51);
vi closing(51);
int copen,cend;
int depth=0;
for(int i=0;i<n;i++)
{
    if(s[i]=='(')
    {
        depth++;
        copen++;
    }
    if(s[i]==')')
    {
        if(depth)
        {
            depth--;
            copen--;           
        }
        else{
            cend++;
        }
    }
}
cout<<depth<<endl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}