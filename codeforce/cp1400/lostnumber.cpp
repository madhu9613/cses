#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> special = {4, 8, 15, 16, 23, 42};

    vector<long long> prod(4);
    cout << "? 1 2" << endl; cout.flush();
    cin >> prod[0];
    cout << "? 2 3" << endl; cout.flush();
    cin >> prod[1];
    cout << "? 3 4" << endl; cout.flush();
    cin >> prod[2];
    cout << "? 4 5" << endl; cout.flush();
    cin >> prod[3];

    vector<int> perm;
    do {
        if (1LL * special[0] * special[1] == prod[0] &&
            1LL * special[1] * special[2] == prod[1] &&
            1LL * special[2] * special[3] == prod[2] &&
            1LL * special[3] * special[4] == prod[3]) {
            perm = special;
            break;
        }
    } while (next_permutation(special.begin(), special.end()));

    cout << "! ";
    for (int x : perm) cout << x << " ";
    cout << endl;
}
