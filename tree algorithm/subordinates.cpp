#include <iostream>
#include <vector>
using namespace std;

vector<int> subordinatesCount; 
vector<vector<int>> adj;  

void dfs(int employee) {
    subordinatesCount[employee] = 0;

    for (int subordinate : adj[employee]) {
        dfs(subordinate);
        
        subordinatesCount[employee] += subordinatesCount[subordinate] + 1; //sub ordinate count of its child and +1 for its this child
    }
}

int main() {
    int n;
    cin >> n;
    
    adj.resize(n + 1); 
    subordinatesCount.resize(n + 1);

    for (int i = 2; i <= n; ++i) {
        int boss;
        cin >> boss;
        adj[boss].push_back(i);  
    }

    dfs(1);

    for (int i = 1; i <= n; ++i) {
        cout << subordinatesCount[i] << " ";
    }

    return 0;
}
