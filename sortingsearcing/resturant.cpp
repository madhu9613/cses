#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> event;
    for (int i = 0; i < n; i++)
    {

        int a, b;
        cin >> a >> b;
        event.push_back({a,1});
        event.push_back({b,-1});
    }
    sort(event.begin(),event.end());
    int curr_customer=0,max_custormer=0;
    for(auto it: event)

    {
        curr_customer+=it.second;
        max_custormer=max(curr_customer,max_custormer);

    }
    cout<<max_custormer<<endl;
    return 0;
}