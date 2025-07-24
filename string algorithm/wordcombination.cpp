#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

struct TrieNode {
    unordered_map<char, TrieNode*> children;
    bool is_end = false;
};

void insert(TrieNode* root, const string& word) {
    TrieNode* node = root;
    for (char ch : word) {
        if (!node->children.count(ch))
            node->children[ch] = new TrieNode();
        node = node->children[ch];
    }
    node->is_end = true;
}

int main() {
    string s;
    cin >> s;
    int n = s.size();

    int k;
    cin >> k;
    
    TrieNode* root = new TrieNode();
    for (int i = 0; i < k; ++i) {
        string word;
        cin >> word;
        insert(root, word);
    }

    vector<int> dp(n + 1, 0);
    dp[0] = 1;

    for (int i = 0; i < n; ++i) {
        if (dp[i] == 0) continue;

        TrieNode* node = root;
        for (int j = i; j < n; ++j) {
            char ch = s[j];
            if (!node->children.count(ch)) break;

            node = node->children[ch];
            if (node->is_end) {
                dp[j + 1] = (dp[j + 1] + dp[i]) % MOD;
            }
        }
    }

    cout << dp[n] << '\n';
    return 0;
}
