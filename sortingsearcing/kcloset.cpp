#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    int left = 0, right = arr.size() - 1;

    while (right - left >= k) {
        if (abs(arr[left] - x) > abs(arr[right] - x)) {
            left++;
        } else {
            right--;
        }
    }

    vector<int> result(arr.begin() + left, arr.begin() + right+1);
    return result;
}

int main() {
    int n, k, x;
    cin >> n >> k >> x;
    
    vector<int> num(n);  
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }

    vector<int> ans = findClosestElements(num, k, x);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    
    
    return 0;
}
