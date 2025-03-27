#include <iostream>
#include <vector>
#include <set>

using namespace std;

int count_rounds(vector<int>& pos, int n) {
    int rounds = 1;
    for (int i = 2; i <= n; i++) {
        if (pos[i] < pos[i - 1]) {
            rounds++;
        }
    }
    return rounds;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> arr(n + 1), pos(n + 1);
    
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        pos[arr[i]] = i;  // Store the position of each number
    }

    set<pair<int, int>> rounds;
    for (int i = 1; i < n; i++) {
        if (pos[i + 1] < pos[i]) {
                 
            rounds.insert({i, i + 1});
        }
    }

    while (m--) {
        int a, b;
        cin >> a >> b;

        int val1 = arr[a], val2 = arr[b];

        // Remove affected pairs before swapping
        for (int i = -1; i <= 1; i++) {
            if (1 <= val1 + i && val1 + i <= n && pos[val1 + i] < pos[val1]) {
                rounds.erase({val1, val1 + i});
            }
            if (1 <= val2 + i && val2 + i <= n && pos[val2 + i] < pos[val2]) {
                rounds.erase({val2, val2 + i});
            }
        }

        // Swap in position array
        swap(pos[val1], pos[val2]);
        swap(arr[a], arr[b]);

        // Add back affected pairs
        for (int i = -1; i <= 1; i++) {
            if (1 <= val1 + i && val1 + i <= n && pos[val1 + i] < pos[val1]) {
                rounds.insert({val1, val1 + i});
            }
            if (1 <= val2 + i && val2 + i <= n && pos[val2 + i] < pos[val2]) {
                rounds.insert({val2, val2 + i});
            }
        }

        cout << rounds.size() + 1 << "\n";
    }

    return 0;
}
