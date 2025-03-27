#include<bits/stdc++.h>
#define MAX_VAL 1e6

using namespace std;

int main()
{
 vector<int> freq(MAX_VAL+1,0);
 int n;cin>>n;
 vector<int> nums;
 for(int i=0;i<n;i++)
 {
    int data;cin>>data;
    nums.push_back(data);
 }

 for(int i=0;i<n;i++)
 {
    freq[nums[i]]++;
 }

for(int g=MAX_VAL;g>=1;g--)
{
    int count=0;
    for(int multiple=g; multiple<=MAX_VAL; multiple+=g)
    {
        count+=freq[multiple];
        if(count>=2)
        {
            cout<<g<<endl;
            return 0;
        }
    }
}
 
    return 0;
}