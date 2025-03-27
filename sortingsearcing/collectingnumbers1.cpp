#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<int> position(n + 1); // To store positions of numbers 1 to n
    
    // Read the array and store the positions of each number
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        position[arr[i]] = i; // Store the index of number i+1
    }
    
    int rounds = 1;
    int last_position = position[1]; // The position of the first number (1)
    
    // Traverse through the numbers from 2 to n
    for (int i = 2; i <= n; i++) {
        if (position[i] < last_position) {
            // If the position of i is before the position of i-1, start a new round
            rounds++;
        }
        last_position = position[i]; // Update last_position to current number's position
    }
    
    cout << rounds << endl; // Output the total rounds
    
    return 0;
}
