#include<bits/stdc++.h>
using namespace std;
int main()
{
     int n;cin>>n;
     queue<int>q;
     for(int i=1;i<=n;i++)
     {
        if(i%2==0)
        {
            cout<<i<<" ";
        }
        else{
            q.push(i);
        }
     }
     if(n%2!=0)
     {
     while(!q.empty())
     {
        cout<<q.front()<<" ";
        q.pop();
        q.push(q.front());
        q.pop();
     }
    }else{

    while(!q.empty())
     {
        q.push(q.front());
        q.pop();
        cout<<q.front()<<" ";
        q.pop();
        
     }
    }


    return 0;
}