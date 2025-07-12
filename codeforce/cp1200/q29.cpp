#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt;cin>>tt;while(tt--)
    {
        int n,k;cin>>n>>k;
        if(n%2==0)
        {
            if(k%n==0)
            {
                cout<<n<<endl;
            }
            else{
            cout<<k%n<<endl;
            }
        }
        else{
            int mid=n/2;
            int skip=(k-1)/mid;
            int ans=k%n+skip;
            if(ans>n)
            { 
                if(ans%n==0)
                {
                    cout<<n<<endl;
                }
                else{
                cout<<ans%n<<endl;
                }
            }else{
                cout<<ans<<endl;
            }

        }
    }
    return 0;
}