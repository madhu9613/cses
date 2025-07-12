//i need to calculate pairs of (i,j) where i<j and a[i]&a[j]>=a[i]^a[j] if maxbits is 1 1 in a[i] amd a[j] thie and will be 1 and xor will be 0 


#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt;cin>>tt;while(tt--)
    {
        int n;cin>>n;
        vector<int>arr(n);
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        vector<long long>maxbits(31,0);
       for(int i=0;i<n;i++)
       {
        for(int bit=30;bit>=0;bit--)
        {
            if(arr[i] & (1 << bit))
            {
                maxbits[bit]++;
                break;

            }
        }
       }

       long long ans=0;
       for(int i=0;i<31;i++)
       { ans+=maxbits[i]*(maxbits[i]-1)/2;

       }
       cout<<ans<<endl;
 
    }
    return 0;
}