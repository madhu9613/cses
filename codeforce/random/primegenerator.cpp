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

vector<int>primes;

void sieve()
{
    vector<bool> isprime(MAXN + 1, true);
    isprime[0] = isprime[1] = false;

    for (int i = 2; i * i <= MAXN; i++)
    {
        if (isprime[i])
        {
            for (int j = i * i; j <= MAXN; j += i)
            {
                isprime[j] = false;
            }
        }
    }

    for (int i = 2; i <= MAXN; i++)
    {
        if (isprime[i])
            primes.push_back(i);
    }
}

void solve() {
ll m,n;cin>>m>>n;

vector<bool>isprime(n-m+1,true);
for(int p:primes)
{
    if((ll)p*p>n) break;
    ll start=max((ll)p*p,((m+p-1)/p)*p);
    for(ll j=start;j<=n;j+=p)
    {
        isprime[j-m]=false;
    }

}
if(m==1)
{
    isprime[0]=false;

}

for(ll i=0;i<=n-m;i++)
{
    if(isprime[i])
    {
        cout<<(m+i)<<endl;
    }
}
cout<<endl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    sieve();

    int t = 1;
    cin >> t;
    while (t--)
        solve();

    return 0;
}