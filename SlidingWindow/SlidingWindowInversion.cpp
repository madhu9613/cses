// It maintains:

// bit[i] = how many times value i has appeared (so far)

// And:

// query(i) = total frequency of values from 1 to i

// range(l, r) = frequency of values in range [l, r]

#include <bits/stdc++.h>
using namespace std;
class BIT
{
public:
    vector<int> bit;
    int n;
    BIT(int size)
    {
        n = size + 2;
        bit.resize(n, 0);
    }

    void update(int i, int delta)
    {
        while (i < n)
        {
            bit[i] += delta;
            i += (i & -i);
        }
    }

    //total freq of value form 1 to i;

    int query(int i)
    {
        int freq=0;
        while(i>0)
        {
            freq+=bit[i];
            i-=(i&-i);
        }
        return freq;
    }
//in range [l,r] we need freq of values;
    int range(int l,int r)
    {
        return query(r)-query(l-1);
    }

};
int main()
{
    int n,k;cin>>n>>k;
    vector<int>a(n);vector<int>b;//for coordinate compreession
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        b.push_back(a[i]);
    }

    //coordinate comparision;

    sort(b.begin(),b.end());
    b.erase(unique(b.begin(),b.end()),b.end());
    for(int i=0;i<n;i++)
    {
        a[i]=lower_bound(b.begin(),b.end(),a[i])-b.begin()+1;

    }

    BIT bit(n+2);
    long long inversion=0;
    for(int i=0;i<n;i++)
    {
        inversion+=bit.range(a[i]+1,n);
        bit.update(a[i],1);

        if(i>=k)
        {
            bit.update(a[i-k],-1);
            inversion-=bit.range(1,a[i-k]-1);
        }
        if(i>=k-1)
        {
            cout<<inversion<<" ";
        }
    }
    cout<<endl;


    return 0;
}