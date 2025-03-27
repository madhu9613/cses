#include<bits/stdc++.h>
using  namespace std;
int main()
{
    int n;
    cin>>n;
    map<int,int> event ; //time :type arrival or depature:
    for(int i=0;i<n;i++)
    {
        
        int a,b;
        cin>>a>>b;
        event[a]+=1;
        event[b]-=1;

    }
    int cur=0,maxi=0;
    for(auto it: event)
    {

   cur+=it.second;
   maxi=max(cur,maxi);
    }
    cout<<maxi<<endl;


return 0;

}