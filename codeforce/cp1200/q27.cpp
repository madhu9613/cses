//flippable 

#include<bits/stdc++.h>
using namespace std;
int main()

{
    int tt;cin>>tt;while (tt--)
    {
        int n;cin>>n;
        string a,b;cin>>a>>b;
        vector<int>flipable(n,false); //index in which i can perform flip operation
        int c=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]=='0')
            {
                c-=1;
            }
            if(a[i]=='1')
            {
                c+=1;
            }
            if(c==0)
            {
                flipable[i]=true; //means i can flip index i;
            }
        }
        bool isflipped=false;
        bool ispossible=true;
        for(int i=n-1;i>=0;i--)
        {
            if(isflipped==false)
            {
              if(a[i]!=b[i])
              {
                if(flipable[i])
               {
                isflipped^=true;
               }
               else{
                ispossible=false;
                break;
               }
            }
            }
            else{

                if(a[i]==b[i])
                {
                    if(flipable[i])
                    {
                        isflipped^=true;

                    }
                    else{
                        ispossible=false;
                        break;
                    }
                }
            }

            
        }
        if(ispossible)
        {
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    
    return 0;
}