// if last interger is >= 10^m Sasha wins else anna wins
//

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

pair<int, int> extract(int num)
{
    int trailling = 0;
    int temp = num;
    while (temp % 10 == 0 && temp != 0)
    {
        trailling++;
        temp /= 10;
    }
    int len = 0;
    temp = num;
    if (temp == 0)
        len = 1;
    else
    {
        while (temp > 0)
        {
            len++;
            temp /= 10;
        }
    }
    return {trailling, len - trailling};
}
void solve()
{
    int n, m;
    cin >> n >> m;
    vi a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    vector<pair<int, int>> res;
    for (int i = 0; i < n; i++)
    {
        res.pb(extract(a[i]));
    }


    sort(all(res));
    reverse(all(res));
    int cl=0;
    int l=0,r=n-1;
    for(l=0;l<n;l+=2)
    {
        cl+=res[l].second;
        if(l+1<n)
        {
        cl+=res[l+1].first+res[l+1].second;
        }
    }
    if(cl>m)
    {
        cout<<"Sasha"<<endl;
    }else{
        cout<<"Anna"<<endl;
    }
    

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