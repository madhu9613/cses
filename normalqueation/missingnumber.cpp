#include<iostream>
using namespace std;
int missingnumber(int arr[],int n)
{
 
 int ans=0;
 for(int i=1;i<=n;i++)
 {
    ans^=i;
 }
 for(int i=0;i<n-1;i++)
 {
    ans^=arr[i];
 }
 return ans;

}
int main()
{

    int n;
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n-1;i++)
    {
     cin>>arr[i];
    }
    int ans=missingnumber(arr,n);
    cout<<ans;
    return 0;

}