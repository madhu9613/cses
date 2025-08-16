#include <bits/stdc++.h>
using namespace std;

// ---------- Tarjan SCC ----------
struct Tarjan {
    int n, timer = 0, comp_cnt = 0;
    vector<vector<int>> g;
    vector<int> disc, low, comp_id;
    vector<char> in_st;
    vector<int> st;

    Tarjan(int n): n(n), g(n), disc(n,0), low(n,0), comp_id(n,-1), in_st(n,0) {}

    void add_edge(int u,int v){ g[u].push_back(v); }

    void dfs(int u){
        disc[u]=low[u]=++timer;
        st.push_back(u); in_st[u]=1;
        for(int v: g[u]){
            if(!disc[v]){ dfs(v); low[u]=min(low[u],low[v]); }
            else if(in_st[v]) low[u]=min(low[u],disc[v]);
        }
        if(low[u]==disc[u]){
            while(true){
                int w=st.back(); st.pop_back(); in_st[w]=0;
                comp_id[w]=comp_cnt;
                if(w==u) break;
            }
            comp_cnt++;
        }
    }

    // returns number of components and fills comp_id
    int run(){
        for(int i=0;i<n;i++) if(!disc[i]) dfs(i);
        return comp_cnt;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; 
    if(!(cin >> n >> m)) return 0;
    Tarjan tj(n);
    vector<pair<int,int>> edges; edges.reserve(m);
    for(int i=0;i<m;i++){
        int a,b; cin >> a >> b; --a; --b;
        tj.add_edge(a,b);
        edges.emplace_back(a,b);
    }

    // 1) SCCs
    int comps = tj.run(); // comp ids are 0..comps-1

    // sizes of SCCs
    vector<int> comp_sz(comps,0);
    for(int i=0;i<n;i++) comp_sz[tj.comp_id[i]]++;

    // 2) Build SCC DAG (dedup edges)
    vector<vector<int>> dag(comps);
    {
        vector<vector<int>> tmp(comps);
        for(auto [u,v] : edges){
            int cu = tj.comp_id[u], cv = tj.comp_id[v];
            if(cu!=cv) tmp[cu].push_back(cv);
        }
        for(int u=0; u<comps; ++u){
            auto &a = tmp[u];
            sort(a.begin(), a.end());
            a.erase(unique(a.begin(), a.end()), a.end());
            dag[u] = move(a);
        }
    }

    // 3) Minimal edges inside SCCs (make each SCC strongly connected by a cycle)
    long long inside_edges = 0;
    for(int i=0;i<comps;i++) if(comp_sz[i] > 1) inside_edges += comp_sz[i];

    // 4) Topological order for the DAG (and index)
    vector<int> indeg(comps,0);
    for(int u=0;u<comps;u++) for(int v:dag[u]) indeg[v]++;
    queue<int> q;
    for(int i=0;i<comps;i++) if(indeg[i]==0) q.push(i);
    vector<int> topo;
    topo.reserve(comps);
    while(!q.empty()){
        int u=q.front(); q.pop();
        topo.push_back(u);
        for(int v:dag[u]) if(--indeg[v]==0) q.push(v);
    }
    // topo index
    vector<int> tpos(comps, -1);
    for(int i=0;i<comps;i++) tpos[topo[i]] = i;

    // Sort each adjacency by topological index
    for(int u=0;u<comps;u++){
        auto &a = dag[u];
        sort(a.begin(), a.end(), [&](int x,int y){ return tpos[x] < tpos[y]; });
    }

    // 5) Transitive reduction count.
    // For each u, process its out-neighbors in increasing topo order.
    // Keep an on-the-fly "covered" set: nodes already reachable from some *kept* neighbor.
    // For neighbor v:
    //   if v already covered -> edge (u,v) redundant
    //   else keep it, then DFS from v to mark everything reachable as covered.
    // Implementation uses timestamp arrays to avoid clearing vectors.
    long long kept_dag_edges = 0;
    vector<int> covered_tag(comps, 0), seen_tag(comps, 0);
    int COVER_T = 0, SEEN_T = 0;

    for(int u=0; u<comps; ++u){
        ++COVER_T; ++SEEN_T;
        for(int v : dag[u]){
            if(covered_tag[v]==COVER_T) {
                // already reachable from some previous kept neighbor -> redundant
                continue;
            }
            // keep edge (u, v)
            kept_dag_edges++;

            // DFS from v to mark coverage (including v)
            vector<int> st; st.push_back(v);
            seen_tag[v] = SEEN_T;
            while(!st.empty()){
                int x = st.back(); st.pop_back();
                if(covered_tag[x] != COVER_T) covered_tag[x] = COVER_T;
                for(int y : dag[x]){
                    if(seen_tag[y] != SEEN_T){
                        seen_tag[y] = SEEN_T;
                        st.push_back(y);
                    }
                }
            }
            // next neighbor; if it is reachable from v (or from earlier kept neighbors),
            // it will now be marked covered and thus be skipped.
        }
    }

    cout << (inside_edges + kept_dag_edges) << '\n';
    return 0;
}
