#include<bits/stdc++.h>
using namespace std;
    
int main()
{
    int n,m;cin>>n>>m;
    multiset<int> ticket;
    for(int i=0;i<n;i++)
    {
        int a;cin>>a;ticket.insert(a);
    }
    
    for(int i=0;i<m;i++)
    {
        int b;cin>>b;
        auto it=ticket.upper_bound(b);
        if(it!=ticket.begin())

        {
            it--;
            cout<<*it<<endl;
            ticket.erase(it);
        }
        else{
            cout<<-1<<endl;
        }

    }
    return 0;
}