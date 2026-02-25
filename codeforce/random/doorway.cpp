#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

struct Event {
    int x;
    int layer_idx;
    int door_idx;

    bool operator<(const Event& other) const {
        return x < other.x;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> L(n);
    vector<Event> events;
    multiset<int> current_rights;

    for (int i = 0; i < n; ++i) {
        int ki, x1, x2;
        cin >> ki >> x1 >> x2;

        vector<int> lengths(ki);
        for (int j = 0; j < ki; ++j) cin >> lengths[j];

        int current_r = x1;
        events.push_back({ current_r, i, 0 });
        for (int j = 0; j < ki; ++j) {
            current_r += lengths[j];
            events.push_back({ current_r, i, j + 1 });
        }

        L[i].resize(ki + 2);
        int current_l = x2;
        L[i][ki + 1] = x2;
        for (int j = ki; j >= 1; --j) {
            current_l -= lengths[j - 1];
            L[i][j] = current_l;
        }
        L[i][0] = x1;
        current_rights.insert(L[i][1]);
    }

    sort(events.begin(), events.end());
    vector<int> current_gap_idx(n, 0);
    long long max_opening = 0;

    for (const auto& ev : events) {
        int i = ev.layer_idx;
        int j = ev.door_idx;

        if (j > current_gap_idx[i]) {
            auto it = current_rights.find(L[i][current_gap_idx[i] + 1]);
            if (it != current_rights.end()) {
                current_rights.erase(it);
            }

            current_gap_idx[i] = j;
            current_rights.insert(L[i][j + 1]);
        }

        if (!current_rights.empty()) {
            int min_r = *current_rights.begin();
            max_opening = max(max_opening, (long long)min_r - ev.x);
        }
    }

    cout << max_opening << endl;

    return 0;
}