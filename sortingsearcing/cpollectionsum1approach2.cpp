#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<vector<long long>> matrix; // 2D matrix to hold the rows

    for (long long num : arr) {
        bool placed = false;
        for (auto& row : matrix) {
            if (row.back() < num) { // Check if the number can be placed in the current row
                row.push_back(num);
                placed = true;
                break;
            }
        }
        if (!placed) {
            matrix.push_back({num}); // Start a new row if no suitable row exists
        }
    }

    cout << matrix.size() << endl; // Number of rows (diagonals)
    return 0;
}
