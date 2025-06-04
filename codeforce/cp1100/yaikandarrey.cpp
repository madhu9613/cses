#include<bits/stdc++.h>
using namespace std;
int solve(int n,int arr[])
{
    int i=0,j=0;
    int sum=0;
    int ans=INT_MIN;
    while(j<n)
    {
        if(sum<0)
        {
            sum=0;
            i=j;
        }
        if(i<j)
        {
            //if arr[j-1] and arr[j] are different parity then
           if((arr[j-1]^arr[j])&1)
           {
            sum+=arr[j];
            j++;
           }
           else{
            sum=arr[j];
            i=j;
            j++;
           }
        }
        else{
            sum=arr[j];
            j++;
        }
        ans=max(ans,sum);
    }
    return ans;
}
int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        int ans=solve(n,arr);
        cout<<ans<<endl;
    }
    
    return 0;
}