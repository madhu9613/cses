#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int low = 1, high = 1e9;
    while (low < high) {
        int mid = low + (high - low) / 2;
        cout << "? " << mid << endl;
        string response;
        cin >> response;
        if (response == "YES") {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    cout << "! " << low << endl;
    return 0;
}
