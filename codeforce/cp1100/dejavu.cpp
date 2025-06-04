#include<bits/stdc++.h>
using namespace std;
void solve(int n,int q,vector<int>&a,vector<int> x)
{
    int prev=31;
    for(int i=0;i<q;i++)
    {
        if(x[i]>=prev)
        {
            continue;
        }
        else{
            int val=pow(2,x[i]);
        for(int j=0;j<n;j++)
        {

            if(a[j]%val==0)
            {
                a[j]+=val/2;
            }
            
        }
        prev=x[i];
    }

    }
    
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,q;
        cin>>n>>q;
        vector<int>a(n),x(q);
        for(int i=0;i<n;i++)
            {
                cin>>a[i];
            }
        for(int i=0;i<q;i++)
        {
            cin>>x[i];
        }
        solve(n,q,a,x);
        for(int i=0;i<n;i++)
        {
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
    return 0;

}