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
string s;cin>>s;
int freq[26]={0};
for(int i=0;i<s.length();i++)
{
    freq[s[i]-'A']++;
}
int odd=0;
int odd_idx=-1;
for(int i=0;i<26;i++)
{
    if(freq[i]%2!=0)
{
    odd++;
    odd_idx=i;
}
}
if(odd>1)
{
    cout<<"NO SOLUTION"<<endl;
    return;
}
string f1="";
for(int i=0;i<26;i++)
{
    if(i!=odd_idx)
    {
    f1+=string(freq[i]/2,'A'+i);
    }
}

string f2=f1;
reverse(all(f2));
string mid="";
if(odd_idx!=-1)
{
    mid=string(freq[odd_idx],'A'+odd_idx);
}
cout<<f1+mid+f2<<endl;


}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    while (t--) solve();
    return 0;
}