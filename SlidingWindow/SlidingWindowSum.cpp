#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int n,k;cin>>n>>k;
    ll x,a,b,c;cin>>x>>a>>b>>c;
    vector<ll>window;
    ll sum=0; ll xor_res=0;
    for(int i=0;i<n;i++)
    {
        if(i==0)
        {
            window.push_back(x);
        }
        else{
            x=(a*x+b)%c;
            window.push_back(x);
        }

        sum+=window.back();
        if(i>=k)
        {
            sum-=window[i-k];
        }

         if (i >= k - 1) 
            xor_res ^= sum;
        }
    
    cout<<xor_res<<endl;
    return 0;
}
