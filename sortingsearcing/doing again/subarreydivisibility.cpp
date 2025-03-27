// Given an array of n integers, your task is to count the number of subarrays where the sum of values is divisible by n.
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    long long arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    unordered_map<int, int> count_map;
    count_map[0] = 1; 
    
    long long prefix_sum = 0;
    long long count = 0;
    
    for (int i = 0; i < n; i++) {
        prefix_sum += arr[i];
        
        int remainder = ((prefix_sum % n) + n) % n;
        
        if (count_map.find(remainder) != count_map.end()) {
            count += count_map[remainder];
        }
        
        count_map[remainder]++;
    }
    
    cout << count << endl;
    return 0;
}
