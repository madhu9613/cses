#include <bits/stdc++.h>
using namespace std;

int josephus(int n, int k) {
    int result = 0; // The position of the last remaining person
    for (int i = 1; i <= n; ++i) {
        result = (result + k) % i;
    }
    return result + 1; // Convert zero-based index to one-based index
}

int main() {
    int n, k;
    cin >> n >> k;
    cout << josephus(n, k) << endl;
    return 0;
}