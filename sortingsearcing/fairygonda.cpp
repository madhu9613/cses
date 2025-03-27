
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> weight(n);
    for (int i = 0; i < n; i++) {
        cin >> weight[i];
    }

    // Sort the weights
    sort(weight.begin(), weight.end());

    int i = 0, j = n - 1; // Two pointers
    int count = 0;

    while (i <= j) {
        if (weight[i] + weight[j] <= k) {
            // Pair the lightest and heaviest weights
            i++;
            j--;
        } else {
            
            j--;
        }
        count++; 
    }

    cout << count << endl;
    return 0;
}
