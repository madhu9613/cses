#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>adj;
vector<int> subcount;

void dfs(int e)
{
    subcount[e]=0;
    for(int s:adj[e])
    {
        dfs(s);

        subcount[e]+=subcount[s]+1;
    }

}
int main()
{
    int n;
    cin>>n;
    adj.resize(n+1);
    subcount.resize(n+1);
    for(int i=2;i<=n;i++)
    {
        int boss;cin>>boss;
        adj[boss].push_back(i);
    }
    dfs(1);

    for(int i=1;i<=n;i++)
    {
        cout<<subcount[i]<<" ";
    }
    
    cout<<endl;

    return 0;

}