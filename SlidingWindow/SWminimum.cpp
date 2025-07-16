#include<bits/stdc++.h>
#define ll long long

using namespace std;
int main()
{
    int n,k;cin>>n>>k;
    ll x,a,b,c;cin>>x>>a>>b>>c;
    vector<ll>buffer(k);
    deque<int>dq; //will store indexs
    ll xor_res=0;
    for(int i=0;i<n;i++)
    {
        if(i!=0)
        {
            x=(a*x+b)%c;
        }
        int pos=i%k;
        buffer[pos]=x;

        while (!dq.empty() && buffer[dq.back()%k]>=x)
        {
            dq.pop_back();
        }
        dq.push_back(i);

        while(!dq.empty() && dq.front()<=i-k)
        {
            dq.pop_front();
        }

        if(i>=k-1)
        {
            xor_res^=buffer[dq.front()%k];
        }
        

    }
    cout<<xor_res<<endl;
    return 0;
}