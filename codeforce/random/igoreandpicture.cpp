#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
#define vi vector<int>
#define vll vector<ll>
#define vpi vector<pii>
#define vpll vector<pll>

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

const ll INF = 1e18;
const int MOD = 1000000007;

// Fast exponentiation (a^b % mod)
ll modpow(ll a, ll b, ll mod = MOD) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

ll modinv(ll a, ll mod = MOD) {
    return modpow(a, mod - 2, mod);
}

// GCD
ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}

// LCM
ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

const int MAXN=1005;
int n,m,k;
string grid[MAXN];
int comp[MAXN][MAXN];
int ans[1000005];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
void solve() {
    int x,y;cin>>x>>y;
    x--,y--;
    cout<<ans[comp[x][y]]<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
// preprocess;

    int t = 1;
cin>>n>>m>>t;
for(int i=0;i<n;i++){
    cin>>grid[i];
}
int id=0;
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        if(grid[i][j]=='.' && comp[i][j]==0){
            id++;

            queue<pair<int,int>>q;
          
            q.push({i,j});
            comp[i][j]=id;
            int pic=0;
            while(!q.empty()){
                auto [x,y]=q.front();
                q.pop();

                for(int d=0;d<4;d++){
                    int nx=x+dx[d];
                    int ny=y+dy[d];
                    if(grid[nx][ny]=='*'){
                        pic++;
                    }else if (grid[nx][ny]=='.' && comp[nx][ny]==0){
                        comp[nx][ny]=id;
                        q.push({nx,ny});
                    }
                }
            }

            ans[id]=pic;
        }
    }
}

    while (t--) solve();

    return 0;
}