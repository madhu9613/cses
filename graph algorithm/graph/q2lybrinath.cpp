#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<string> grid;
vector<pair<pair<int,int>,char> > dir={{{0,-1},'L'},{{0,1},'R'},{{-1,0},'U'},{{1,0},'D'}};
vector<vector<bool>>visited;
vector<vector<pair<int,int>> >parent;
int main()
{

cin>>n>>m;
grid.resize(n);
visited.resize(n,vector<bool>(m,false));
parent.resize(n,vector<pair<int,int>>(m,{-1,-1}));
queue<pair<int,int> >q;
pair<int,int> start,end;
for(int i=0;i<n;i++)
{
    cin>>grid[i];
    for(int j=0;j<m;j++)
    {
     if(grid[i][j]=='A') start={i,j};
     if(grid[i][j]=='B') end={i,j};
    
    }
}
//now doing bfs from a to b:
q.push(start);
visited[start.first][start.second]=true;

while(!q.empty())
{
    pair<int,int>cur=q.front();
    q.pop();

    if(cur.first==end.first && cur.second==end.second) break; //we have reached b

    for(int d=0;d<4;d++)
    {
        int nx=cur.first+dir[d].first.first;
        int ny=cur.second+dir[d].first.second;

        if(nx>=0 && ny>=0 && nx<n && ny<m && !visited[nx][ny] && grid[nx][ny]!='#')
        {
            visited[nx][ny]=true;
            parent[nx][ny]={cur.first, cur.second};
            q.push({nx,ny});
        }
    
    }
}
//bfs end after bfs end check that is we reach B 

if(!visited[end.first][end.second])
{
    cout<<"NO"<<endl;
    return 0;
}

//now we need the path>

string path;
pair<int,int> cur=end;
while(cur.first!=start.first || cur.second!=start.second)
{
    pair<int,int> prev=parent[cur.first][cur.second];
    for(int d=0;d<4;d++)
    {
        if(prev.first+dir[d].first.first==cur.first && prev.second+dir[d].first.second==cur.second)
        {
            path+=dir[d].second;
            break;
        }
    }
    cur=prev;
}

reverse(path.begin(),path.end());
cout<<"YES\n";
cout<<path.length()<<endl;
cout<<path<<"\n";

    return 0;
}