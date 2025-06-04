#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<int> solve(int n,vector<int> pre, vector<pair<int,int>>p)
{
    vector<int> ans(n);
    for(int i=0;i<n;i++)
    {
        int j=i;
        int total=i;
        while(j<n)
        {
            pair<int,int> temp={pre[j]+1,INT_MIN};
            int idx=lower_bound(p.begin(),p.end(),temp)-p.begin();
            idx--;
            if(idx==j)
            {
                break;
            }
            total+=idx-j;
            j=idx;
        }

        ans[p[i].second]=total;
    }
    return ans;

}
int32_t main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<pair<int,int> > v;
        for(int i=0;i<n;i++)
        {
            int a;
            cin>>a;
            v.push_back({a,i});
        }

        vector<int> pre(n);
        sort(v.begin(),v.end());
        pre[0]=v[0].first;
        for(int i=1;i<n;i++)
        {
            pre[i]=pre[i-1]+v[i].first;
        }
       vector<int>ans=solve(n,pre,v);
       for(auto i: ans)
       {
        cout<<i<<" ";
       }cout<<endl;
    }
    return 0;
}