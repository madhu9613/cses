#include<bits/stdc++.h>
using namespace std;

const int INF=1e9;
const int dx[]={-1,1,0,0};
const int dy[]={0,0,-1,1};
const char dir[]={'U','D','L','R'};
int n,m;
vector< string> grid;
vector<vector<int>> monstertime,playertime;
pair<int,int> start;
queue<pair<int,int>> monsterqueu,playerqueue;
map<pair<int,int> ,pair<int,int> > parent;

bool isvalid(int x,int y)
{
    return x>=0 && x<n && y>=0 && y<m && grid[x][y]!='#';
}

//it will update all the time from 
void bfsmonster()
{
    while(!monsterqueu.empty())
    {
        auto [x,y]=monsterqueu.front();
        monsterqueu.pop();
        for(int d=0;d<4;d++)
        {
            int nx=x+dx[d];int ny=y+dy[d];
            //if its time is not update then only we will update it 
            if(isvalid(nx,ny) && monstertime[nx][ny]==INF)
            {
                monstertime[nx][ny]=monstertime[x][y]+1; //+1 time from x,y cell t0 nx and ny
                monsterqueu.push({nx,ny});
            }
        }
    }
}

bool bfsplayer()
{
    while(!playerqueue.empty())
    {
        auto [x,y]=playerqueue.front(); playerqueue.pop();
        //if we reach the boundary point then we will check the condition's is it reach here before monster
        if(x==0 || x==n-1 || y==0 || y==m-1)
        {
            string path="";
            pair<int,int> cur={x,y};
            while(cur!=start)
            {
                pair<int,int> prev=parent[cur];
                for(int d=0;d<4;d++)
                {
                    if(prev.first+dx[d]==cur.first && prev.second+dy[d]==cur.second)
                    {
                        path+=dir[d];
                        break;
                    }
                }
                cur=prev;
            }
            reverse(path.begin(), path.end());
            cout << "YES\n"
                 << path.size() << "\n"
                 << path << "\n";
            return true;
        }
        for(int d=0;d<4;d++)
      {
        int nx=x+dx[d],ny=y+dy[d];
        if(isvalid(nx,ny) && playertime[nx][ny]==INF)
         {
            if(playertime[x][y]+1 <monstertime[nx][ny])
            {
                playertime[nx][ny]=playertime[x][y]+1;
                parent[{nx,ny}]={x,y};
                playerqueue.push({nx,ny});
            }
         }
     }
     return false;
       
    }
}
int main()
{
    cin >> n >> m;
    grid.resize(n);
    monstertime.assign(n, vector<int>(m, INF));
    playertime.assign(n, vector<int>(m, INF));
    for(int i=0;i<n;i++)
    {
      cin>>grid[i];
      for(int j=0;j<m;j++)
      {
        if(grid[i][j]=='A')
        {
            start={i,j};
            playerqueue.push({i,j});//players starting point
            playertime[i][j]=0; //timne to reach this cell is zero

        }
        else if(grid[i][j]=='M')
        {
            monsterqueu.push({i,j});
            monstertime[i][j]=0;
        }
      }
    }
    bfsmonster(); //with this bfs we will mark min time by monster to reach a cell ...min time optina;
    if (!bfsplayer ())
    {
        cout << "NO\n";
    }

    return 0;
}