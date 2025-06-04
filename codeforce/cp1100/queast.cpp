#include<bits/stdc++.h>
using namespace std;
int solve(vector<int>a,vector<int> b,int k)
{
    int n=a.size();
    int maxi=0;
    int sum=0;
    int ans=0;
    for(int i=0;i<min(n,k);i++)
    {
        //he will solve only till ith queast so sum till ai and k-i times max of b till i
     sum+=a[i];
    maxi=max(maxi,b[i]);
    ans=max(ans,sum+(k-i-1)*maxi);
         
    }
    return ans;
}
int  main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        vector<int>first(n); vector<int> second(n);
        for(int i=0;i<n;i++)
        {
          cin>>first[i];
        }
        for(int i=0;i<n;i++)
        {
            cin>>second[i];
        }
        cout<<solve(first,second,k)<<endl;
    }
    return 0;
}