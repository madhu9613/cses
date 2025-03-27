#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    int left = 0, right = n - 1;
    int currentsum = 0;
    vector<pair<int, int>> ans;

    while (left < right)
    {
        currentsum = nums[left] + nums[right];

        if (currentsum == x)
        {
            ans.push_back({nums[left], nums[right]});
            left++;  
            right--; 
        }
        else if (currentsum < x)
        {
            left++; 
        }
        else
        {
            right--; // Decrease right pointer to decrease sum
        }
    }

    // Output all pairs
    for (auto i : ans)
    {
        cout << i.first << " " << i.second << endl;
    }

    return 0;
}
