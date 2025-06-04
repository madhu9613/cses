#include<bits/stdc++.h>
using namespace std;

long long findSubarray(vector<long long> num,long long n,long long x)
{
    map<long long,long long> prefix_count;
    prefix_count[0]=1;
    long long prefixSum=0;
    long long ans=0;
    for(int i=0;i<n;i++)
    {
        prefixSum+=num[i];

        if(prefix_count.find(prefixSum-x)!=prefix_count.end())
        {
            ans+=prefix_count[prefixSum-x];
        }
        prefix_count[prefixSum]++;
    }
    return ans;
}
int main()
{
    long long n,x;cin>>n>>x;
    vector<long long>num;
    for(int i=0;i<n;i++)
    {
        int a;cin>>a;
        num.push_back(a);
    }
    cout<<findSubarray(num,n,x);
    return 0;
}