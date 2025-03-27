#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> movies;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        movies.push_back({a, b});
    }
    sort(movies.begin(), movies.end(), [](const pair<int, int> &a, const pair<int, int> &b)
         { return a.second < b.second; });

    int prevend = 0;
    int maxi = 0,ans=0;
    for (auto i : movies)
    {
        if(i.first>=prevend)
        {
            ans++;
            maxi=max(maxi,ans);
            prevend=i.second;
        }
    }
    cout<<maxi<<endl;
    return 0;
}