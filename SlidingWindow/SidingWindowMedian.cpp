#include <bits/stdc++.h>
using namespace std;

multiset<int> LeftHalf, RightHalf;
void balance()
{
    while (LeftHalf.size() < RightHalf.size())
    {
        auto it = RightHalf.begin();
        LeftHalf.insert(*it);
        RightHalf.erase(it);
    }
    while (LeftHalf.size() > RightHalf.size() + 1)
    {
        auto it = prev(LeftHalf.end());
        RightHalf.insert(*it);
        LeftHalf.erase(it);
    }
}

void insert(int val)
{
    if (LeftHalf.empty() || val <= *LeftHalf.rbegin())
    {
        LeftHalf.insert(val);
    }
    else
    {
        RightHalf.insert(val);
    }
    balance();
}

//TIps:i was using erase(val) direct without it casuse delete all occurence of val
void erase(int val)
{
    auto it = LeftHalf.find(val);
    if (it != LeftHalf.end())
    {
        LeftHalf.erase(it); 
    }
    else
    {
        it = RightHalf.find(val);
        if (it != RightHalf.end())
            RightHalf.erase(it);  
    }

    balance();
}

int main()
{

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        insert(a[i]);
        if (i >= k)
        {
            erase(a[i - k]);
        }
        if (i >= k - 1)
        {

            cout << *LeftHalf.rbegin() << " ";
        }
    }
    cout << endl;
    return 0;
}
