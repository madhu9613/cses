#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<pair<long long, long long>> a(n);

        for (int i = 0; i < n; i++)
        {
            cin >> a[i].first;
            a[i].second = i + 1;
        }

        sort(a.begin(), a.end()); 

        int ans = 0;

        //as (i<j) maximum value of i+j can be 2n-1 if we sort a; if smaller numbers product already greater than 2n no point in cheking others right?

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (a[i].first * a[j].first >= 2 * n)
                    break;

                if (a[i].first * a[j].first == a[i].second + a[j].second)
                    ans++;
            }
        } 
    

        cout << ans << "\n";
    }

    return 0;
}
