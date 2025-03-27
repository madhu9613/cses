#include <bits/stdc++.h>
using namespace std;

struct Customer {
    int arrival, departure, index;
};

// Custom comparator to sort by arrival time
bool cmp(Customer a, Customer b) {
    return a.arrival < b.arrival;
}

int main() {
    int n;
    cin >> n;
    
    vector<Customer> customers(n);
    for (int i = 0; i < n; i++) {
        cin >> customers[i].arrival >> customers[i].departure;
        customers[i].index = i;
    }

    // Sort customers by arrival time
    sort(customers.begin(), customers.end(), cmp);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> roomAssignment(n);
    int maxRooms = 0;

    for (auto cust : customers) {
        // Free rooms that are available before the current arrival
        if (!pq.empty() && pq.top().first < cust.arrival) {
            int room = pq.top().second;
            pq.pop();
            pq.push({cust.departure, room});
            roomAssignment[cust.index] = room;
        } else {
            // Assign new room
            int newRoom = pq.size() + 1;
            pq.push({cust.departure, newRoom});
            roomAssignment[cust.index] = newRoom;
            maxRooms = max(maxRooms, newRoom);
        }
    }

    // Print results
    cout << maxRooms << endl;
    for (int i = 0; i < n; i++) {
        cout << roomAssignment[i] << " ";
    }
    cout << endl;
    return 0;
}
