#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

const int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
const int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};

ll board[8][8];

bool issafe(int x, int y) {
    return x >= 0 && x < 8 && y >= 0 && y < 8 && board[x][y] == 0;
}

int deg(int x, int y) {
    int s = 0;
    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (issafe(nx, ny))
            s++;
    }
    return s;
}

bool dfs(int x, int y, int move) {
    board[x][y] = move;
    if (move == 64) return true;

    vector<tuple<int, int, int>> vec;
    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (issafe(nx, ny)) {
            vec.emplace_back(deg(nx, ny), nx, ny);
        }
    }

    sort(vec.begin(), vec.end());

    for (auto &[_, nx, ny] : vec) {
        if (dfs(nx, ny, move + 1))
            return true;
    }

    board[x][y] = 0;
    return false;
}

int main() {
    fastio;
    int y, x;
    cin >> y >> x; 
    x--, y--;

    memset(board, 0, sizeof(board));
    dfs(x, y, 1);

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cout << board[i][j] << " ";
        }
        cout << '\n';
    }

    return 0;
}
