#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    set<int> nums;
    for(int i=0;i<n;i++)
    {
        int a;cin>>a;nums.insert(a);
    }
    cout<<nums.size()<<endl;
    return 0;
}