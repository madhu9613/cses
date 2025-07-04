#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int &x : a) cin >> x;

    vector<int> queries(q);
    for (int &x : queries) cin >> x;

    // Store first appearance position of each color
    unordered_map<int, int> pos;
    vector<int> order;

    for (int i = 0; i < n; ++i) {
        if (!pos.count(a[i])) {
            pos[a[i]] = i;
            order.push_back(a[i]);
        }
    }

    for(auto &t:queries)
    {
        cout<<pos[t]+1<<" "; //to make it 1 based index now as i have only 50 diff color for each color now position will be changed i mean as i mov this to above whose position is
        for(auto &x:pos)
        {
            if(x.second<pos[t])
            {
                x.second+=1;
            }
        }
        pos[t]=0;
    }
    

    cout << "\n";
    return 0;
}
