#include<bits/stdc++.h>
using namespace std;
int solve(vector<int>&num1,vector<int>&num2,int index,bool swapped)
{
    if(index>=num1.size())
    {
        return 0;
    }
    int ans=INT_MAX;
    int prev1=num1[index-1];
    int prev2=num2[index-1];
    if(swapped)
    {
        swap(prev1,prev2);
    }
    if(num1[index]>prev1 && num2[index]>prev2)
    {
        //no swap requiered
        ans=solve(num1,num2,index+1,false);
    }
    else{
        ans=min(ans,1+solve(num1,num2,index+1,true));
    }

    return ans;
}
int main()
{
    int n;cin>>n;
    vector<int> num1(n),num2(n);
    for(int i=0;i<n;i++)
    {
        cin>>num1[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>num2[i];
    }
    num1.insert(num1.begin(),-1);
    num2.insert(num2.begin(),-1);
    bool swapped=false;
    int ans=solve(num1,num2,1,swapped);
    cout<<ans<<endl;
    
    return 0;
}