#include<bits/stdc++.h>
using namespace std;
#define int long long
int find(vector<int>num,int n)
{  
    map<int,int>remcount;
    remcount[0]=1; //means sub array with remainder 0 is 1
    int prefixsum=0;int c=0;
    for(int x:num)
  {
    prefixsum+=x;
    int remainder=((prefixsum%n)+n)%n;
    if(remcount.find(remainder)!=remcount.end())
    {
        c+=remcount[remainder];
    }
     remcount[remainder]++;
   
  }
     
 return c;

}
int32_t main()
{
    int n;
    cin>>n;
    vector<int> num;
    for(int i=0;i<n;i++)
    {
        int a;cin>>a;
        num.push_back(a);
    }
    cout<<find(num,n);
    return 0;
}