#include <bits/stdc++.h>
using namespace std;

// Custom hash function to reduce collisions in unordered_map
struct CustomHash {
    size_t operator()(int x) const {
        return x ^ (x >> 16); // XOR and bit-shifting for better distribution
    }
};

void solve(vector<int>& nums, int target) {
    int n = nums.size();
    unordered_map<int, int, CustomHash> index; // Use custom hash function

    for (int i = 0; i < n; i++) {
        int x = target - nums[i];
        if (index.count(x)) {
            cout << index[x] + 1 << " " << i + 1 << "\n"; // Output 1-based indices
            return;
        }
        index[nums[i]] = i;
    }
    cout << "IMPOSSIBLE\n";
}

int main() {
    ios::sync_with_stdio(false); // Disable synchronization with C-style I/O
    cin.tie(nullptr);            // Untie cin and cout for faster I/O

    int n, x;
    cin >> n >> x;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    solve(nums, x);

    return 0;
}
