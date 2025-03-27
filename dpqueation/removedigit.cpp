#include <iostream>
#include <algorithm>
using namespace std;

int min_steps_to_zero(int n) {
    int steps = 0;
    while (n > 0) {
        // Find the largest digit in the current number
        int largest_digit = 0;
        int temp = n;
        while (temp > 0) {
            largest_digit = max(largest_digit, temp % 10);
            temp /= 10;
        }
        // Subtract the largest digit from the number
        n -= largest_digit;
        // Increment step count
        steps++;
    }
    return steps;
}

int main() {
    int n;
    cin >> n;
    
    // Output the result
    cout << min_steps_to_zero(n) << endl;
    
    return 0;
}
