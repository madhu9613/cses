#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 200000;
const int LOG = 30;  

int up[MAX_N + 1][LOG];  
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        cin >> up[i][0]; 
    }

    for (int j = 1; j < LOG; j++) {
        for (int i = 1; i <= n; i++) {
            up[i][j] = up[up[i][j - 1]][j - 1];  
        }
    }

    while (q--) {
        int x, k;
        cin >> x >> k;

        for (int j = 0; j < LOG; j++) {
            if (k & (1 << j)) { 
                x = up[x][j];
            }
        }

        cout << x << '\n';
    }

    return 0;
}
