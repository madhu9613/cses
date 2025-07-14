#include <bits/stdc++.h>
using namespace std;

typedef struct
{
    int x;
    int y;
} point;

int main()
{
    int n;
    cin >> n;
    vector<string> grid(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> grid[i];
    }

    // Starting BFS-like traversal
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    queue<point> q;
    q.push({0, 0});
    visited[0][0] = true;

    string result = "";
    result += grid[0][0];

    for (int step = 0; step < 2 * n - 2; ++step)
    {
          int sz = q.size();
          vector<point> next_positions;
          char minChar = 'Z' + 1;

          while (!q.empty())
          {
            point p=q.front(); q.pop();
            //now move to right from the p
            if(p.y+1<n && !visited[p.x][p.y+1])
            {
                minChar=min(minChar,grid[p.x][p.y+1]);
                next_positions.push_back({p.x,p.y+1});

            }
            //move to down position
            if(p.x+1<n && !visited[p.x+1][p.y])
            {
                minChar=min(minChar,grid[p.x+1][p.y]);
                next_positions.push_back({p.x+1,p.y});
            }
          }

           for(auto &np:next_positions)
           {
            if(grid[np.x][np.y]==minChar && !visited[np.x][np.y])
            {
                visited[np.x][np.y]=true;
                q.push({np.x,np.y});
            }

           }

           result+=minChar;
          
       
    }

    cout << result << endl;

    return 0;
}
