// You are given an array containing n positive integers.
// Your task is to divide the array into k subarrays so that the maximum sum in a subarray is as small as possible./
#include<bits/stdc++.h>
using namespace std;
bool isValid(vector<int> &arr,int k, long long mid)
{
    int count=1;
    long long sum=0;
    for(int num:arr)
    {
        if(sum+num >mid)
        {
            count++;
            sum=num;
           //starting of new subarrey okay lets see...
           if(count>k)
           {
            return false; //why we need more than k number of arrey to maintain smallest possible sum

           }
          
        }
        else{
            sum+=num;
           }
       
    }
    return true;
}
int main()
{
    int n,k;cin>>n>>k;
    vector<int>arr(n);
    long long left=0,right=0, mid=0;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        left=max(left,(long long)arr[i]);
        right+=arr[i];
    }
 
    while(left<right)
    {
        mid=left+(right-left)/2 ;
        if(isValid(arr,k,mid))

        {
            //try for smaller value:
            right=mid;
        }
        else{
            left=mid+1;
        }
    }


   cout<<left<<endl;

    return 0;
}