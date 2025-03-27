#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    int n;cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }
    int cursum=0;
    int ans=nums[0];
    for(auto &x:nums)
    {
        cursum=max(cursum+x,x);
        ans=max(ans,cursum);
    }
    cout<<ans<<endl;
    return 0;

}