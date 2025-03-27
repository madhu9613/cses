#include <iostream>
#include <map>
#include <vector>
using namespace std;

long long countSubarraysWithSumX(const vector<int>& arr, int n, int x) {
    map<long long, int> prefixSumCount; 
    prefixSumCount[0] = 1; 
    long long prefixSum = 0;
    long long count = 0; 

    for (int i = 0; i < n; ++i) {
        prefixSum += arr[i];

        if (prefixSumCount.find(prefixSum - x) != prefixSumCount.end()) {
            count += prefixSumCount[prefixSum - x];
        }

        prefixSumCount[prefixSum]++;
    }

    return count;
}

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << countSubarraysWithSumX(arr, n, x) << endl;
    return 0;
}
