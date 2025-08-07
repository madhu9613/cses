#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define max3(a, b, c) max(max(a, b), c)
#define max4(a, b, c, d) max(max(a, b), max(c, d))
#define pii pair<int, int>
#define all(x) (x).begin(), (x).end()
#define endl '\n'

ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
}
const int MOD = 1e9 + 7;
const int INF = INT_MAX;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    vi prefix(n + 1), suffix(n + 1);
    int uni1 = 0;
    unordered_map<int, int> freq1;
    for (int i = 0; i < n; i++)
    {
        if (freq1[s[i] - 'a'] == 0)
        {
            uni1++;
        }
        freq1[s[i] - 'a']++;
        prefix[i]=uni1;
    }


    uni1=0;
    unordered_map<int,int>freq2;
    for(int i=n-1;i>=0;--i)
    {
        if(freq2[s[i]-'a']==0)
        {
            uni1++;
        }
        freq2[s[i]-'a']++;
        suffix[i]=uni1;
    }

    int res=INT_MIN;
    for(int i=0;i<n;i++)
    {
        res=max(res,prefix[i]+suffix[i+1]);

    }

    cout<<res<<endl;
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