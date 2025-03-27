#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007

using namespace std;
ll power(ll a,ll b)
{
ll res=1;
a=a%MOD;
while(b>0)
{
    if(b&1)
    {
        res=(res*a)%MOD ;
    }
    a=(a*a)%MOD;
    b>>=1;
}
return res;
}
int main()
{
   int t;cin>>t;
   while(t--)
   {
      ll a,b; cin>>a>>b;

      cout<<power(a,b)<<endl;
   }

    
    return 0;
}