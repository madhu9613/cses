#include <bits/stdc++.h>
using namespace std;

// Recursive solution
int solve(vector<int> &nums, int target, int index) {
    if (target == 0) {
        return 1; // Found a valid subset
    }
    if (index >= static_cast<int>(nums.size()) || target < 0) {
        return 0; // No valid subset
    }
    // Include the current element
    int include = solve(nums, target - nums[index], index + 1);
    // Exclude the current element
    int exclude = solve(nums, target, index + 1);

    return include + exclude;
}

// Memoized solution
int solvememo(vector<long long> &nums, vector<vector<long long>> &dp, int target, int index) {
    if (target == 0) {
        return 1; // Found a valid subset
    }
    if (index >= static_cast<int>(nums.size()) || target < 0) {
        return 0; // No valid subset
    }
    if (dp[index][target] != -1) {
        return dp[index][target];
    }

    // Include and exclude the current element
    int include = solvememo(nums, dp, target - nums[index], index + 1);
    int exclude = solvememo(nums, dp, target, index + 1);

    dp[index][target] = include + exclude;
    return dp[index][target];
}
// ----------brute force calculate all possible subset and count how much of them with sum =target;


int bruteforce(vector<long long>& nums, long long target)
{
    int n = nums.size();
    long long totalSubsets = 1 << n; // Total subsets = 2^n
    int count = 0;

    // Iterate over all subsets
    for (long long mask = 0; mask < totalSubsets; ++mask) {
        long long sum = 0;

        // Calculate the sum of the current subset
        for (long long i = 0; i < n; ++i) {
            if (mask & (1 << i)) { // Check if the i-th element is included
                sum += nums[i];
            }
        }

        // If the sum matches target, increment the count
        if (sum == target) {
            ++count;
        }
    }

    return count;
}

void generateSubsetSums(const vector<long long>& arr, vector<long long>& sums) {
    int n = arr.size();
    for (int mask = 0; mask < (1 << n); ++mask) {
        long long sum = 0;
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                sum += arr[i];
            }
        }
        sums.push_back(sum);
    }
}

int main() {
    int n;
    long long x;
    cin >> n >> x;
    vector<long long> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    vector<long long> left(arr.begin(), arr.begin() + n / 2);
    vector<long long> right(arr.begin() + n / 2, arr.end());

    vector<long long> leftSums, rightSums;
    generateSubsetSums(left, leftSums);
    generateSubsetSums(right, rightSums);

    sort(rightSums.begin(), rightSums.end());

    long long count = 0;
    for (long long sum : leftSums) {
        long long target = x - sum;
        count += upper_bound(rightSums.begin(), rightSums.end(), target) -
                 lower_bound(rightSums.begin(), rightSums.end(), target);
    }

    cout << count << endl;
    return 0;
}
