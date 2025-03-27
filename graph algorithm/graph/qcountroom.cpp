#include<bits/stdc++.h>
using namespace std;
vector<vector<char> > grid;
int n,m;
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1}; //right,left,down,up

void dfs(int x,int y)
{
    if(x>=n || y>=m || grid[x][y]=='#' || x<0 || y<0)
    {
        return ;
    }
    //mark this cell as visited or you can mark it as #
    grid[x][y]='#';
    for(int i=0;i<4;i++)
    {
        dfs(x+dx[i],y+dy[i]);
    }

}


//using bfs;
void bfs(int x,int y)
{
    queue<pair<int,int>>q;
    q.push({x,y});
    //mark this cell as visited;
    grid[x][y]='#';
    while(!q.empty())
    {
        x=q.front().first;
        y=q.front().second;
        q.pop();

        //visite its neighbour
        for(int i=0;i<4;i++)
        {
            int nx=x+dx[i];
            int ny=y+dy[i];
            //its valid point and mark as '.' mark it '#'
            if(nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny]=='.')
            { 
            grid[nx][ny]='#';
            q.push({nx,ny});

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
    //count room using dfs;
    int count=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(grid[i][j]=='.') //if its a floor increase the count of room and mark all connected floor as visited for it
            {
                count++;
                bfs(i,j);
            }
        }
    }
cout<<count<<endl;
    return 0;
}