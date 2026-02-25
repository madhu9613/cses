#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define max3(a, b, c) max(max(a, b), c)
#define max4(a, b, c, d) max(max(a, b), max(c, d))
#define pii pair<int, int>
#define pll pair<ll, ll>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endl '\n'

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}
ll pow(ll a,ll b,ll m)
{
if(b==0)
 return 1;
if(b==1) return a%m;
 ll temp=pow(a,b/2,m);
 if(b%2==0)
 {
 return (temp*temp)%m;
}
else
{
return (a*(temp*temp)%m)%m ;
}
}

const int MOD = 1e9 + 7;
const int INF = INT_MAX;
const ll LINF = 1e18;

const int MAXN = 40005;

void solve() {
    int n,m,k;cin>>n>>m>>k;
    vector<vector<int>>adj(n+1);
    for(int i=0;i<m;i++)
    {
        int a,b;cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int>visited(n+1,-1);
    vector<int>dist(n+1,-1);
    vector<int>strength(k); //strength of solder (i)
    queue<int>q;
    queue<int>qid;
    for(int i=0;i<k;i++)
    {
        int city,s;cin>>city>>s;
        strength[i]=s;
        if (visited[city] != -1)
        {

            cout<<"No"<<endl;
            return;
        }
        visited[city]=i;
        dist[city]=0;
        q.push(city);
        qid.push(i);
    }
    while(!q.empty())

    {
        int u=q.front();q.pop();
        int sid=qid.front(); qid.pop();
        if(dist[u]==strength[sid]) continue;

      for(auto v:adj[u])
      {
        if(visited[v]==-1)
        {
            visited[v]=sid;
            dist[v]=dist[u]+1;
            q.push(v);
            qid.push(sid);
        }
        else if(visited[v]!=sid)

        {
            cout<<"No"<<endl;
            return;
        }
      }
    }
    for(int i=1;i<=n;i++)
    {
        if(visited[i]==-1)
        {
            cout<<"No"<<endl;
            return;
        }
    }
    cout<<"Yes"<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--)
        solve();

    return 0;
}