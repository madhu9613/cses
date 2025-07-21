#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> movies(n);
    for (int i = 0; i < n; ++i) {
        cin >> movies[i].second >> movies[i].first; // (end, start) for sorting
    }

    sort(movies.begin(), movies.end()); // sort by end time

    multiset<int> end_times; // stores the end time of the last movie watched by each member

    // Initially all k members are free at time 0
    for (int i = 0; i < k; ++i) {
        end_times.insert(0);
    }

    int count = 0;

    for (auto [end, start] : movies) {
        // Find a member who is free before the movie starts
        auto it = end_times.upper_bound(start);
        if (it == end_times.begin()) continue; // No one free before start
        --it; // Now it points to member who is free latest but before `start`
        end_times.erase(it);     // Use this member
        end_times.insert(end);   // Update availability after watching this movie
        count++;
    }

    cout << count << '\n';
    return 0;
}
