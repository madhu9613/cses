#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    unordered_map<ll, ll> freq;
    set<ll> MEX;
    // we need to find MEX in a window of k so its gurrented that MEX will be <k;
    vector<ll> a(n);
    for(int i=0;i<=k;i++)
    {
        MEX.insert(i);
    }
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if(a[i]<=k)
         {
            freq[a[i]]++;
            if( freq[a[i]]==1)
            {
                MEX.erase(a[i]); // for now its not a MEX candidate;
            }
         }

         if(i>=k)
         {
            ll remove_val=a[i-k];
            if(remove_val<=k)
            {
                freq[remove_val]--;
                if(freq[remove_val]==0)
                {
                    MEX.insert(remove_val);
                }
            }

         }
         if(i>=k-1)
         {
            cout<<*MEX.begin()<<" ";
         }
    }
    cout<<endl;


    return 0;
}