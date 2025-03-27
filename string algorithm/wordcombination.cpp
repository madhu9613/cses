#include <iostream>
#include <unordered_set>
#include <vector>

#define MOD 1000000007

using namespace std;

unordered_set<string> dict;
string s;
int n;
vector<int> dp; // Memoization table

int countWays(int index) {
    if (index == n) return 1;  // If we reach the end, we found a valid way
    if (dp[index] != -1) return dp[index]; // Return already computed result
    
    int ways = 0;
    string temp = "";

    // Try forming words starting from `index`
    for (int i = index; i < n; i++) {
        temp += s[i];  // Add character to current substring
        if (dict.find(temp) != dict.end()) { // Check if it's a valid word
            ways = (ways + countWays(i + 1)) % MOD; // Recursive call
        }
    }

    return dp[index] = ways; // Store result
}

int main() {
    cin >> s;
    int k;
    cin >> k;
    
    dict.clear();
    n = s.length();
    dp.assign(n + 1, -1); // Initialize DP array

    string word;
    for (int i = 0; i < k; i++) {
        cin >> word;
        dict.insert(word);
    }

    cout << countWays(0) << endl;
    return 0;
}
