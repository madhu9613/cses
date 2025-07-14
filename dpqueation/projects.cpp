#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Project {
    ll start, end, reward;
};

bool compare(Project &a, Project &b) {
    return a.end < b.end;
}

int main() {
    int n;
    cin >> n;
    vector<Project> projects(n);
    
    for (int i = 0; i < n; ++i)
        cin >> projects[i].start >> projects[i].end >> projects[i].reward;

    sort(projects.begin(), projects.end(), compare);

    // dp[end_time] = max reward up to that time
    map<ll, ll> dp;
    dp[0] = 0;  // base case: no reward before day 0

    for (auto &[a, b, p] : projects) {
        // Find last project that ends before a
        auto it = dp.upper_bound(a - 1);
        --it;
        ll curr = it->second + p;

        // Update dp[b] = max(dp[b], curr)
        if (curr > dp.rbegin()->second)
            dp[b] = curr;
    }

    cout << dp.rbegin()->second << "\n";
    return 0;
}
