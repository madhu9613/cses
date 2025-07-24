#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    TrieNode* child[2];
    TrieNode() {
        child[0] = child[1] = nullptr;
    }
};

void insert(TrieNode* root, int num) {
    TrieNode* node = root;
    for (int i = 31; i >= 0; --i) {
        int bit = (num >> i) & 1;
        if (!node->child[bit])
            node->child[bit] = new TrieNode();
        node = node->child[bit];
    }
}

int query(TrieNode* root, int num) {
    TrieNode* node = root;
    int maxXor = 0;
    for (int i = 31; i >= 0; --i) {
        int bit = (num >> i) & 1;
        int opposite = 1 - bit;
        if (node->child[opposite]) {
            maxXor |= (1 << i);
            node = node->child[opposite];
        } else {
            node = node->child[bit];
        }
    }
    return maxXor;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    TrieNode* root = new TrieNode();
    insert(root, 0);  // Important: for subarrays starting at index 0

    int prefixXor = 0, maxResult = 0;
    for (int i = 0; i < n; ++i) {
        prefixXor ^= a[i];
        maxResult = max(maxResult, query(root, prefixXor));
        insert(root, prefixXor);
    }

    cout << maxResult << '\n';
    return 0;
}
