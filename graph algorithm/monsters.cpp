#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int dx[] = {-1, 1, 0, 0}; // U, D, L, R
const int dy[] = {0, 0, -1, 1};
const char dir[] = {'U', 'D', 'L', 'R'};

int n, m;
vector<string> grid;
vector<vector<int>> monsterTime, playerTime;
pair<int, int> start;
queue<pair<int, int>> monsterQueue, playerQueue;
map<pair<int, int>, pair<int, int>> parent; // For backtracking path

bool isValid(int x, int y)
{
    return x >= 0 && x < n && y >= 0 && y < m && grid[x][y] != '#';
}

void bfsMonsters()
{
    while (!monsterQueue.empty())
    {
        auto [x, y] = monsterQueue.front();
        monsterQueue.pop();
        for (int d = 0; d < 4; d++)
        {
            int nx = x + dx[d], ny = y + dy[d];
            if (isValid(nx, ny) && monsterTime[nx][ny] == INF)
            {
                monsterTime[nx][ny] = monsterTime[x][y] + 1;
                monsterQueue.push({nx, ny});
            }
        }
    }
}

bool bfsPlayer()
{
    while (!playerQueue.empty())
    {
        auto [x, y] = playerQueue.front();
        playerQueue.pop();

        // If we reach a boundary, reconstruct the path and return success
        if (x == 0 || x == n - 1 || y == 0 || y == m - 1)
        {
            string path = "";
            pair<int, int> cur = {x, y};
            while (cur != start)
            {
                pair<int, int> prev = parent[cur];
                for (int d = 0; d < 4; d++)
                {
                    if (prev.first + dx[d] == cur.first && prev.second + dy[d] == cur.second)
                    {
                        path += dir[d];
                        break;
                    }
                }
                cur = prev;
            }
            reverse(path.begin(), path.end());
            cout << "YES\n"
                 << path.size() << "\n"
                 << path << "\n";
            return true;
        }

        for (int d = 0; d < 4; d++)
        {
            int nx = x + dx[d], ny = y + dy[d];
            if (isValid(nx, ny) && playerTime[nx][ny] == INF)
            {
                if (playerTime[x][y] + 1 < monsterTime[nx][ny])
                {
                    playerTime[nx][ny] = playerTime[x][y] + 1;
                    parent[{nx, ny}] = {x, y};
                    playerQueue.push({nx, ny});
                }
            }
        }
    }
    return false;
}

int main()
{
    cin >> n >> m;
    grid.resize(n);
    monsterTime.assign(n, vector<int>(m, INF));
    playerTime.assign(n, vector<int>(m, INF));

    for (int i = 0; i < n; i++)
    {
        cin >> grid[i];
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 'A')
            {
                start = {i, j};
                playerQueue.push({i, j});
                playerTime[i][j] = 0;
            }
            else if (grid[i][j] == 'M')
            {
                monsterQueue.push({i, j});
                monsterTime[i][j] = 0;
            }
        }
    }

    bfsMonsters();
    if (!bfsPlayer())
    {
        cout << "NO\n";
    }

    return 0;
}
