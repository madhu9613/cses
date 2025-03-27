/*Time limit: 1.00 s
Memory limit: 512 MB

Given an array of n positive integers, your task is to count the number of subarrays having sum x.

here all number are positive so i can use two pointer approach here..
*/
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

    int left = 0, right = 0, currentsum = 0, count = 0;

    while (right < n) 
    {
        currentsum += nums[right];

        while (currentsum > x && left <= right)
        {
            currentsum -= nums[left];
            left++;
        }

        if (currentsum == x)
        {
            count++;
        }

        right++;
    }

    cout << count << endl;

    return 0;
}
