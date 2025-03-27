#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Binary search to find the largest ticket <= maxprice
int find_ticket(const vector<int>& ticket, int maxprice) {
    int l = 0, r = ticket.size() - 1, result = -1;

    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (ticket[mid] <= maxprice) {
            result = mid;  // Update result and search for larger ticket
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    return result; // Index of the ticket, or -1 if none found
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> ticket(n);
    for (int i = 0; i < n; i++) {
        cin >> ticket[i];
    }

    sort(ticket.begin(), ticket.end()); // Sort tickets initially

    vector<int> maxi(m);
    for (int i = 0; i < m; i++) {
        cin >> maxi[i];
    }

    for (int i = 0; i < m; i++) {
        int maxprice = maxi[i];
        int index = find_ticket(ticket, maxprice);

        if (index == -1) {
            cout << -1 << endl; // No ticket available
        } else {
            cout << ticket[index] << endl; // Print the ticket price
            ticket.erase(ticket.begin() + index); // Remove the ticket
        }
    }

    return 0;
}
