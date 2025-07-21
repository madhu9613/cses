#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> tasks(n); // {duration, deadline}
    for (int i = 0; i < n; ++i) {
        cin >> tasks[i].first >> tasks[i].second;
    }

    sort(tasks.begin(), tasks.end()); // Sort by duration

    long long current_time = 0;
    long long total_reward = 0;

    for (auto [duration, deadline] : tasks) {
        current_time += duration;
        total_reward += (deadline - current_time);
    }

    cout << total_reward << '\n';
    return 0;
}
