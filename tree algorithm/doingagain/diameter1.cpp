#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>tree;
int n;

pair<int,int> bfs(int node)
{
    int farthest=node;
    int maxdistance=0;

    vector<bool> visited(n+1,false);
    vector<int>distance(n+1,-1);
    queue<int>q;
    visited[node]=true;
    distance[node]=0;
    q.push(node);
    while (!q.empty())
    {
        int n=q.front(); q.pop();
       
        for(auto & neighb:tree[n])
        {
            if(!visited[neighb])
            {
                distance[neighb]=distance[n]+1;
                visited[neighb]=true;
                q.push(neighb);
                if(distance[neighb]>maxdistance)

                {
                    farthest=neighb;
                    maxdistance=distance[neighb];
                }
            }
        }


    }
    return {farthest,maxdistance};
    
}


int main()
{
    cin>>n;
    tree.resize(n+1);
    for(int i=0;i<n-1;i++)
    {
        int a,b; cin>>a>>b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    
    }
    pair<int,int> first=bfs(1);
    pair<int,int> second=bfs(first.first);
    cout<<second.second<<" "<<endl;
    return 0;
}