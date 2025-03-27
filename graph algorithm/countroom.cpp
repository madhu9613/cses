#include<bits/stdc++.h>
using namespace std;
vector<vector<char> >grid;


int n,m;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void dfs(int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= m || grid[x][y] == '#')
        return;

    grid[x][y] = '#'; // mark it visited 

    for (int i = 0; i < 4; i++)
        dfs(x + dx[i], y + dy[i]);
}

// using bfs solution of the room count queation 

void bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});
    grid[x][y] = '#';

    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
             
            //if the next cell is in the grid and it is a floor then mark it as visited and push it to the queue
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == '.') {
                grid[nx][ny] = '#';
                q.push({nx, ny});
            }
        }
    }
}

int main()
{
   
    cin>>n>>m;
    grid.resize(n,vector<char>(m)); 
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>grid[i][j];
        }
    }
    int roomcount=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(grid[i][j]=='.')
            {
                roomcount++;
                bfs(i,j); //connect all the connected floor and mark them as visited or assign them #
            }
        }
    }
    cout<<roomcount<<endl;
    return 0;
}
// Time complexity of the above code is O(n*m) where n is the number of rows and m is the number of columns in the grid.