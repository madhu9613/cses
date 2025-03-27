#include <iostream>
#include <vector>
using namespace std;

int main() {
    long long n;
    cin >> n;

    // Calculate the sum of the first n natural numbers
    long long sum = n * (n + 1) / 2;

    // If the sum is odd, it's not possible to split into two equal parts
    if (sum % 2 != 0) {
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl;

    // Target sum for each set
    long long target = sum / 2;
    vector<int> set1, set2;

    // Start from the largest number and add to sets
    for (int i = n; i >= 1; i--) {
        if (target >= i) {
            set1.push_back(i);
            target -= i;
        } else {
            set2.push_back(i);
        }
    }

    // Output the sets
    cout << set1.size() << endl;
    for (int num : set1) cout << num << " ";
    cout << endl;

    cout << set2.size() << endl;
    for (int num : set2) cout << num << " ";
    cout << endl;

    return 0;
}
