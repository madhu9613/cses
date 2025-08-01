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

vector<string>board(8);
vector<bool>cols,diag1,diag2;
int ans=0;
void dfs(int r)
{
    if(r==8){
        ans++;
        return;
    }
    for(int c=0;c<8;c++)
    {
        if(board[r][c]=='*') continue;
        if(cols[c] || diag1[r-c+7]||diag2[r+c]) continue;
        cols[c]=diag1[r-c+7]=diag2[r+c]=true;
        dfs(r+1);
        cols[c]=diag1[r-c+7]=diag2[r+c]=false;
    }

}
void solve() {
    for(int i=0;i<8;i++)
    {
        cin>>board[i];
    }
    cols.assign(8,false);
    diag1.assign(15,false);
    diag2.assign(15,false);
    dfs(0);
    cout<<ans<<endl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    while (t--) solve();
    return 0;
}