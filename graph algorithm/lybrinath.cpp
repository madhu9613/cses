#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int> > directions = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
vector<char> dirChars = {'L', 'R', 'U', 'D'};

int main()
{
    int n,m;cin>>n>>m;
    vector<string> grid(n);
    vector<vector<bool> >visited(n,vector<bool> (m,false));
    vector<vector<pair<int,int>> > parent(n,vector<pair<int,int> >(m,{-1,-1}));
    queue<pair<int,int> >q;
    pair<int,int> start,end;
    for(int i=0;i<n;i++)
    {
        cin>>grid[i];
        for(int j=0;j<m;j++)
        {
            if(grid[i][j]=='A') start={i,j}; //index of startign cell;
            if(grid[i][j]=='B') end={i,j}; //end cell's index

        }
        
    }
    q.push(start);
    visited[start.first][start.second]=true;
    while(!q.empty())
    {
        pair<int,int> current=q.front(); q.pop();
        if(current.first==end.first && current.second==end.second) break;
          
        for(int d=0;d<4;d++)
        {
            int nx=current.first+directions[d].first;
            int ny=current.second + directions[d].second;
            if(nx>=0 && ny>=0 && nx<n && ny<m && !visited[nx][ny] && grid[nx][ny]!='#')
            {
                visited[nx][ny]=true;
                parent[nx][ny]={current.first,current.second};
                q.push({nx,ny});
            }
        }

    }

    //if last cell is not visited starting from cell 'A' then its mean it can't be reach from A
    if(!visited[end.first][end.second])
    {
        cout<<"NO"<<endl;
        return 0;
    }
    //now retrace the path:
    string path;
    pair<int,int> cur=end;
    while(cur.first!=start.first || cur.second!=start.second)
    {
        pair<int,int> prev=parent[cur.first][cur.second];
        for(int d=0;d<4;d++)
        {
            if(prev.first+directions[d].first==cur.first && prev.second+directions[d].second==cur.second)
            {
                path += dirChars[d];
                break;
            }
        }
        cur=prev;
    }
    reverse(path.begin(),path.end());
    cout << "YES\n";
    cout << path.length() << "\n";
    cout << path << "\n";
    

    return 0;
}