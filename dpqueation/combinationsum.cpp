#include<bits/stdc++.h>
using  namespace std;
 void findCombinations(int index, int target, vector<int> &nums, vector<int> & current, vector<vector<int>> &result) {
        if (target == 0) {
            result.push_back(current);
            return;
        }

        for (int i = index; i < nums.size(); i++) {

            if (i > index && nums[i] == nums[i - 1]) continue;

            if (nums[i] > target) break;

            current.push_back(nums[i]);

            findCombinations(i + 1, target - nums[i], nums, current, result);

            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int> &nums, int target) {
        vector<vector<int>> result;
        vector<int> current;

        sort(nums.begin(), nums.end());

        findCombinations(0, target, nums, current, result);
        return result;
    }



int main()
{
 int n, x;
    cin >> n >> x;
    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<vector<int>> ans = combinationSum(nums, x);

    for (const auto &combination : ans) {
        for (int num : combination) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}