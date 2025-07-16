#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    unordered_map<ll, ll> freq;
    map<ll, set<ll>> CountToNum;

    auto insert = [&](ll val)
    {
        ll oldfreq = freq[val]++;
        if (oldfreq > 0)
        {
            CountToNum[oldfreq].erase(val);
        }
        CountToNum[oldfreq + 1].insert(val);
        // if now oldFreq become empty erase it
        if (CountToNum[oldfreq].empty())
        {
            CountToNum.erase(oldfreq);
        }
    };

    auto remove = [&](ll val)
    {
        ll oldfreq = freq[val]--;
        if (oldfreq > 0)
        {
            CountToNum[oldfreq].erase(val);
        }
        CountToNum[oldfreq - 1].insert(val);
        if (CountToNum[oldfreq].empty())
        {
            CountToNum.erase(oldfreq);
        }
    };

    vector<ll> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        insert(a[i]);
        if (i >= k)
        {
            remove(a[i - k]);
        }

        if(i>=k-1)
        {
            ll max_freq=CountToNum.rbegin()->first;
            ll mode=*CountToNum.rbegin()->second.begin();
            cout<<mode<<" ";
        }
    }
    cout<<endl;
}