#include <bits/stdc++.h>
using namespace std;
int mininrange(int l, int u, vector<int> arr)
{
    int min =arr[l];
    for(int i=l;i<=u;i++)
    {
         if(arr[i]<min)
         {
            min=arr[i];
         }
    }
    return min;
}
int main() {
    int n, q;
    cin >> n >> q;
    vector<int> arr;
    vector<int> result;
    for(int i=0;i<n;i++)
    {
           int d;
           cin>>d;
           arr.push_back(d);

    }
    for(int i=0;i<q;i++)
    {


       int a,b;
       cin>>a>>b;
       a--,b--;
       int ans=mininrange(a,b,arr);
       result.push_back(ans);
      
    }
 for(int i: result)
 {
    cout<<i<<endl;
 }
return 0;
    
    }

 