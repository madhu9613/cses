#include<bits/stdc++.h>
#define MAX_VAL 1e6
using namespace std;

vector<int> compute()
{
    vector<int> divisors(MAX_VAL+1,0);
    for(int i=1;i<=MAX_VAL;i++)
    {
        for(int j=i;j<=MAX_VAL;j+=i)
        {
            divisors[j]++;
        }
    }
    return divisors;
}
int main()
{
    vector<int> divisors=compute();
    int n;
    cin>>n;
    while(n--)
    {
        int a;
        cin>>a;
        cout<<divisors[a]<<endl;
    }

    return 0;
}