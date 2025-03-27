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
        movies.push_back({a, b}); // starting time of the movie and ending time of the movie
    }
    sort(movies.begin(), movies.end(), [](const pair<int, int> &a, const pair<int, int> &b)
         { return a.second < b.second; });

    int last_end=0;
   int  count=0;
    for(auto it: movies)

    {
        if(it.first>=last_end)
        {
            count++;
            last_end=it.second;
        }
        

    }
    cout<<count<<endl;
    return 0;
}
navdeep saharan
navsnavdeep saharan 
