#include <iostream>
using namespace std;

const int MOD = 1e9 + 7;
const int MAXN = 1e6;

long long derangements[MAXN + 1];

void precompute() {
    derangements[1] = 0;
    derangements[2] = 1;
    for (int i = 3; i <= MAXN; i++) {
        derangements[i] = ( (i - 1) * (derangements[i - 1] + derangements[i - 2]) ) % MOD;
    }
}

int main() {
    precompute();
    int n;
    cin >> n;
    cout << derangements[n] << endl;
    return 0;
}
