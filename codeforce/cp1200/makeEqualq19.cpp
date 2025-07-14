#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;cin>>t;
    while (t--)
    {
        int n;
        char c;
        string s;
        cin>>n>>c>>s;
        bool isOdd=false;
        int max_even=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]!=c)
            {
                if((i+1)%2==0)
                 {
                    max_even=max(max_even,i+1);
                 }
                 else{
                    isOdd=true;
                 }                
            }
        }
        if(max_even==0 && !isOdd)
        {
            cout<<0<<endl;
        }
        else if(max_even==0 && isOdd)
        {
            cout<<1<<endl;
            cout<<2<<endl;
        }
        else if(max_even!=0 && !isOdd)
        {
            cout<<1<<endl;
            if(max_even/2%2==0)
            {
                cout<<max_even/2+1<<endl;
            }
            else{
                cout<<max_even/2+2<<endl;
            }
        }
        else{
            cout<<2<<endl;
            cout<<2<<" ";
                 if(max_even/2%2==0)
            {
                cout<<max_even/2+1<<endl;
            }
            else{
                cout<<max_even/2+2<<endl;
            }
        }
    }

    
    return 0;
}