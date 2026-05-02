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

ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
}
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
const int MOD = 1e9 + 7;
const int INF = INT_MAX;
const ll LINF = 1e18;

void solve()
{

    auto isrbs = [&](string s)
    {
        int d = 0;

        for (char c : s)
        {
            d += (c == '(' ? 1 : -1);
            if (d < 0)
                return false;
        }

        return d == 0;
    };

    int n;string s;cin>>n>>s;
    int open=count(all(s),'(');
    int close=n-open;
    if(open!=close)
    {
        cout<<-1<<endl;
        return;
    }
    string rs=s;reverse(all(rs));
    if(isrbs(s) || isrbs(rs))   
    {
        cout<<1<<endl;
        for(int i=0;i<n;i++)
        {
            cout<<1<<" ";
        }cout<<endl;
        return ;
    }
    vi color(n,2);
    vi st; st.reserve(n);
    for(int i=0;i<n;++i)
    {
        if(s[i]=='(')

        {
            st.pb(i);
        }else{
            if(!st.empty())
            {

                int j=st.back();st.pop_back();

                color[i]=color[j]=1;
            }
        }
    }
    cout<<2<<endl;

    for(auto i:color)
    {
        cout<<i<<" ";
    }cout<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
