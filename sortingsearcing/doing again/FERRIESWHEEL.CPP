/**There are n children who want to go to a Ferris wheel, and your task is to find a gondola for each child.
Each gondola may have one or two children in it, and in addition, the total weight in a gondola may not exceed x. You know the weight of every child. */

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,x;
    cin>>n>>x;
    vector<int> nums(n);
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }
    sort(nums.begin(),nums.end());
    int left=0,right=n-1,cnt=0;
    while(left<=right)
    {
        
        if(nums[left] +nums[right]<=x)
        {
          
            left++;
            right--;
        }
        else 
        {
            right--;
       }
       
          cnt++;
    }
    cout<<cnt<<endl;

    return 0;
}