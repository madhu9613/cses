// for example 1 5 11 5 two partition are 1 5 5 and 11 
//if total sum is odd direct return 0 as its impossible to make two set

#include<bits/stdc++.h>
using namespace std;
bool solve(vector<int> nums, int target,int index)
{

    //is sum==target possible if yes then okay
    if(index>=nums.size())
    {
        return false;
    }
    if(target==0)
    {
        return true;
    }
    int exclude=solve(nums,target,index+1);
    int include=0;
    if(target-nums[index]>=0)
    {
        include=solve(nums,target-nums[index],index+1);
    }
    return include || exclude ;
}

int main()
{
    int n;
    cin>>n;
    vector<int> nums(n);
    int sum=0;
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
        sum+=nums[i];
    }
    int target;
    if((sum&1)==0)
    {
        target=sum/2;
    }
    else{
        cout<<0;
        return 0;
    }

   if(solve(nums,target,0))
   {
    cout<<1;
   }
   else{
    cout<<0;
   }
    return 0;
}