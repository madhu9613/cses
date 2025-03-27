#include<bits/stdc++.h>
using namespace std;
long long solve(vector<long long> nums)
{
    int n=nums.size();
    sort(nums.begin(),nums.end());
    long long minsum=1;
    for(auto &i:nums)
    {
        if(i>minsum)
        {
            break;
        }
        minsum+=i;
    }
    return minsum;
}
int main()
{
    int n;cin>>n;
    vector<long long> nums(n);
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }
    long long ans=solve(nums);
    cout<<ans<<endl;
    return 0;
}