#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	vector<int> out(n + 1);           
	vector<vector<int>> radj(n + 1);  

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		radj[b].push_back(a);
		out[a]++;
	}

	/*
	 * Any node with out[i] == 0 can be used, so we store all possible
	 * nodes in a max heap to get the node with the maximum id.
	 */
	priority_queue<int> pq;
	for (int i = 1; i <= n; i++) {
		if (out[i] == 0) { pq.push(i); }
	}

	vector<int> ans;
	while (pq.size()) {
		// Remove the node with the greatest id.
		int x = pq.top();
		pq.pop();
		ans.push_back(x);

		// Remove all edges that begin at `x`.
		for (int t : radj[x]) {
			out[t]--;
			if (!out[t]) { pq.push(t); }
		}
	}
	reverse(ans.begin(), ans.end());
	for (int t : ans) { cout << t << " "; }
}
