#include <bits/stdc++.h>
using namespace std;

int main()
{
    int tt;
    cin >> tt;
    while (tt--)
    {
        int n, k;
        cin >> n >> k;
        set<int> a;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];   a.insert(arr[i]);
        }

        bool found = false;
        for (int i = 0; i < n; i++)
        {
            if (a.count(arr[i] + k))
            {
                found = true;
                break;
            }
         
        }

        if (found)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}
