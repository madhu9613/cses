#include<bits/stdc++.h>
#define int long long
using namespace std;
int32_t main()
{
    int tt;cin>>tt;while (tt--)
    {
        int n;cin>>n;
        vector<int>a(n);
        unordered_map<int,int>count;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            count[a[i]-i]++;
        }
        long long ans=0;
        for(auto &[diff,count]:count)
        {
            ans+=count*(count-1)/2;
        }
        cout<<ans<<endl;
    }
    
    return 0;
}