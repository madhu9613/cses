#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;cin>>n;
    vector<pair<int,int> > event; //a,1 or a,-1 1 for arrival and -1 for departure
    for(int i=0;i<n;i++)
    {
      int a,b;cin>>a>>b;
    event.push_back({a,1});
    event.push_back({b,-1});
    }

    sort(event.begin(),event.end());

    int maxi=0,ans=0;
    for(auto & i :event)
    {
        ans+=i.second;
        
      maxi=max(maxi,ans);
        
    }
    cout<<maxi<<endl;
    return 0;
}