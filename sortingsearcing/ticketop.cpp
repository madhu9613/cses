#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    multiset<int> ticket;
    for (int i = 0; i < n; i++)
    {
        int d;
        cin >> d;
        ticket.insert(d);
    }
    vector<int> maxi;

    for (int i = 0; i < m; i++)
    {
        int d;
        cin >> d;
        maxi.push_back(d);
    }
for(int i=0;i<m;i++)
{
int max_price=maxi[i];
auto it=ticket.upper_bound(max_price);
if(it==ticket.begin())
{
    cout<<-1<<endl;
}
else{
    it--;
    cout<<*it<<endl;
    ticket.erase(it);
}

}
    return 0;
}
