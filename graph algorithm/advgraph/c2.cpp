#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

const int MAXN = 200005;
const int LOGN = 18; 

std::vector<int> adj[MAXN];
int depth[MAXN];
int parent[MAXN][LOGN];
int tin[MAXN];
int tout[MAXN];
int timer;
bool has_coin[MAXN];
std::vector<int> coin_nodes_list;

void dfs(int u, int p, int d) {
    tin[u] = ++timer;
    depth[u] = d;
    parent[u][0] = p;
    for (int k = 1; k < LOGN; ++k) {
        parent[u][k] = parent[parent[u][k-1]][k-1];
    }
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs(v, u, d + 1);
    }
    tout[u] = ++timer;
}

bool is_ancestor(int u, int v) {
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v) {
    if (is_ancestor(u, v)) return u;
    if (is_ancestor(v, u)) return v;
    for (int k = LOGN - 1; k >= 0; --k) {
        if (!is_ancestor(parent[u][k], v)) {
            u = parent[u][k];
        }
    }
    return parent[u][0];
}

long long dist(int u, int v) {
    int ancestor = lca(u, v);
    return (long long)depth[u] + depth[v] - 2 * depth[ancestor];
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, q;
    std::cin >> n >> q;

    for (int i = 1; i <= n; ++i) {
        int c;
        std::cin >> c;
        if (c == 1) {
            has_coin[i] = true;
            coin_nodes_list.push_back(i);
        } else {
            has_coin[i] = false;
        }
    }

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        std::cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 1, 0); // Root at 1, parent of root is itself, depth 0

    std::sort(coin_nodes_list.begin(), coin_nodes_list.end(), [](int u, int v) {
        return tin[u] < tin[v];
    });

    long long initial_D_C = 0;
    int k = coin_nodes_list.size();

    if (k == 1) {
        initial_D_C = 0; // Perimeter of a single point is 0
    } else {
        for (int i = 0; i < k - 1; ++i) {
            initial_D_C += dist(coin_nodes_list[i], coin_nodes_list[i+1]);
        }
        initial_D_C += dist(coin_nodes_list[k-1], coin_nodes_list[0]);
    }

    for (int qi = 0; qi < q; ++qi) {
        int a, b;
        std::cin >> a >> b;

        std::vector<int> query_nodes_to_add;
        if (!has_coin[a]) {
            query_nodes_to_add.push_back(a);
        }
        if (!has_coin[b] && a != b) { // Only add b if it's distinct from a and not a coin
            query_nodes_to_add.push_back(b);
        }
        
        std::sort(query_nodes_to_add.begin(), query_nodes_to_add.end(), [](int u, int v) {
            return tin[u] < tin[v];
        });

        long long current_D = initial_D_C;

        if (query_nodes_to_add.empty()) {
            // a and b are both coin nodes, or a == b is coin node
            // current_D is already correct
        } else if (query_nodes_to_add.size() == 1) {
            int x = query_nodes_to_add[0];
            int prev_x, next_x;

            auto it = std::upper_bound(coin_nodes_list.begin(), coin_nodes_list.end(), tin[x], [](int t_val, int node_val){
                return t_val < tin[node_val];
            });
            
            if (it == coin_nodes_list.end()) {
                next_x = coin_nodes_list.front();
            } else {
                next_x = *it;
            }

            if (it == coin_nodes_list.begin()) {
                prev_x = coin_nodes_list.back();
            } else {
                prev_x = *(--it);
            }
            
            current_D += dist(prev_x, x) + dist(x, next_x) - dist(prev_x, next_x);

        } else { // query_nodes_to_add.size() == 2
            int x = query_nodes_to_add[0]; // has smaller tin
            int y = query_nodes_to_add[1]; // has larger tin

            int prev_x, next_x, prev_y, next_y;

            auto it_x = std::upper_bound(coin_nodes_list.begin(), coin_nodes_list.end(), tin[x], [](int t_val, int node_val){
                return t_val < tin[node_val];
            });
            next_x = (it_x == coin_nodes_list.end()) ? coin_nodes_list.front() : *it_x;
            prev_x = (it_x == coin_nodes_list.begin()) ? coin_nodes_list.back() : *(--it_x);

            auto it_y = std::upper_bound(coin_nodes_list.begin(), coin_nodes_list.end(), tin[y], [](int t_val, int node_val){
                return t_val < tin[node_val];
            });
            next_y = (it_y == coin_nodes_list.end()) ? coin_nodes_list.front() : *it_y;
            prev_y = (it_y == coin_nodes_list.begin()) ? coin_nodes_list.back() : *(--it_y);

            // Check if x and y fall into the same segment of coin_nodes_list
            // This happens if next_x_node == prev_y_node (after y is inserted into tin-sorted coin_nodes)
            // Or more directly if next_x (the element found for x) is the same as next_y
            // i.e., tin[prev_x] < tin[x] < tin[y] < tin[next_x]
            if (next_x == next_y) { 
                current_D += dist(prev_x, x) + dist(x, y) + dist(y, next_x) - dist(prev_x, next_x);
            } else {
                // Different segments
                current_D += dist(prev_x, x) + dist(x, next_x) - dist(prev_x, next_x);
                current_D += dist(prev_y, y) + dist(y, next_y) - dist(prev_y, next_y);
            }
        }
        
        long long ans = current_D - dist(a,b);
        std::cout << ans << "\n";
    }

    return 0;
}