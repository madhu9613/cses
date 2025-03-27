#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int min_teleportations(int a, int b, const vector<int>& teleport) {
    unordered_map<int, int> visited; // Map to store steps taken
    int steps = 0;

    while (true) {
        if (visited.count(a)) return -1; // Cycle detected, cannot reach b
        visited[a] = steps; // Store step count

        if (a == b) return steps; // Found destination

        a = teleport[a]; // Move to next planet
        steps++;
    }

    return -1; // Should not reach here
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    vector<int> teleport(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> teleport[i];
    }

    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << min_teleportations(a, b, teleport) << "\n";
    }

    return 0;
}
