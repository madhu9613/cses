// here key concept is Minimum  value of summation of absolutte difference between |ai-x| is occure when we take it as a median
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> sticks(n);
    
    for (int i = 0; i < n; i++) {
        cin >> sticks[i];
    }
    
    sort(sticks.begin(), sticks.end());
    
    // Step 2: Find the median
    int median = sticks[n / 2];
    
    long long cost = 0;
    for (int i = 0; i < n; i++) {
        cost += abs(sticks[i] - median);
    }
    
    cout << cost << endl;
    
    return 0;
}

// key point to note is 
// Key Difference Between Mean and Median for Optimization

// Mean minimizes the sum of squared differences:
