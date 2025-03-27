#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007

using namespace std;
ll power(ll a,ll b,ll mod)
{
ll res=1;
a=a%mod;
while(b>0)
{
    if(b&1)
    {
        res=(res*a)%mod ;
    }
    a=(a*a)%mod;
    b>>=1;
}
return res;
}
int main()
{
   int t;cin>>t;
   while(t--)
   {
      ll a,b,c; cin>>a>>b>>c;
        
      ll x=power(b,c,MOD-1);
      cout<<power(a,x,MOD)<<endl;
   }

    
    return 0;
}