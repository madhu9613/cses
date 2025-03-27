//its one d dp
#include<bits/stdc++.h>
using namespace std;
int solve(int target,vector<int> nums)
{
    if(target<0)
    {
        return 0;
    }
    if(target==0)
    {
        return 1; //one wat to make target>
    }
    int ans=0;
    for(int i=0;i<nums.size();i++)
    {
        ans+=solve(target-nums[i],nums);
    }
    return ans;
}

int main()
{
    int n,target;cin>>n>>target;
    vector<int> nums(n);
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }
    int ans=solve(target,nums);
    cout<<ans<<endl;

    return 0;
}