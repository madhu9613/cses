#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
unordered_map<int, int> in_index;
vi preorder, inorder, postorder;

void buildPostorder(int preL, int inL, int inR) {
    if (inL > inR) return;

    int root = preorder[preL];
    int rootIndex = in_index[root];
    int leftSize = rootIndex - inL;

    buildPostorder(preL + 1, inL, rootIndex - 1);               // Left subtree
    buildPostorder(preL + 1 + leftSize, rootIndex + 1, inR);    // Right subtree

    postorder.push_back(root);  
}

void solve() {
    int n;
    cin >> n;

    preorder.resize(n);
    inorder.resize(n);
    postorder.clear();
    in_index.clear();

    for (int i = 0; i < n; i++) cin >> preorder[i];
    for (int i = 0; i < n; i++) {
        cin >> inorder[i];
        in_index[inorder[i]] = i;
    }

    buildPostorder(0, 0, n - 1);

    for (int val : postorder) cout << val << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();  
    return 0;
}
