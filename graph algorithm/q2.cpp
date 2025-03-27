// You are given a map of a labyrinth, and your task is to find a path from start to end. You can walk left, right, up and down
#include<bits/stdc++.h>

using namespace std;

struct Point {
    int x, y;
};

// Directions: Left, Right, Up, Down
vector<Point> directions = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
vector<char> dirChars = {'L', 'R', 'U', 'D'};

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<string> grid(n);
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<vector<Point>> parent(n, vector<Point>(m, {-1, -1}));
    queue<Point> q;
    
    Point start, end;
    
    // Read input and find start ('A') and end ('B')
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'A') start = {i, j};
            if (grid[i][j] == 'B') end = {i, j};
        }
    }
    
    q.push(start);
    visited[start.x][start.y] = true;
    
    while (!q.empty()) {
        Point cur = q.front();
        q.pop();
        
        if (cur.x == end.x && cur.y == end.y) break; 
        
        for (int d = 0; d < 4; d++) {
            int nx = cur.x + directions[d].x;
            int ny = cur.y + directions[d].y;
            
            if (nx >= 0 && ny >= 0 && nx < n && ny < m && !visited[nx][ny] && grid[nx][ny] != '#') {
                visited[nx][ny] = true;
                parent[nx][ny] = {cur.x, cur.y}; 
                q.push({nx, ny});
            }
        }
    }
    
    if (!visited[end.x][end.y]) {
        cout << "NO" << endl;
        return 0;
    }
    
    string path;
    Point cur = end;
    
    while (cur.x != start.x || cur.y != start.y) {
        Point prev = parent[cur.x][cur.y];
        
        for (int d = 0; d < 4; d++) {
            if (prev.x + directions[d].x == cur.x && prev.y + directions[d].y == cur.y) {
                path += dirChars[d];
                break;
            }
        }
        
        cur = prev;
    }
    
    reverse(path.begin(), path.end());
    
    cout << "YES\n";
    cout << path.length() << "\n";
    cout << path << "\n";
    
    return 0;
}