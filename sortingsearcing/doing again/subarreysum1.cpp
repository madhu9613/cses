#include<bits/stdc++.h>
using namespace  std;
int main()
{
    int n,x;cin>>n>>x;
    vector<int> num;
    for(int i=0;i<n;i++)
    {
        int a;cin>>a;num.push_back(a);
    }
    int left=0,right=0,cs=0,c=0;
    while(right<n)
    {
        cs+=num[right];
        while(cs>x && left<=right)
        {
            cs-=num[left];
            left++;
        }

        if(cs==x)

        {
            c++;
        }
        right++;
    
    }
    cout<<c<<endl;
    return 0;
}