#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define endl '\n'
 
const int MAX_K = 20;
 
bitset<MAX_K> toBitsetLSB(const string& s) {
    bitset<MAX_K> b;
    int len = s.size();
    for (int i = 0; i < len; ++i) {
        b[i] = (s[len - 1 - i] == '1');  // LSB from rightmost char
    }
    return b;
}
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n, k;
    cin >> n >> k;
 
    vector<bitset<MAX_K>> bits(n);
 
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        bits[i] = toBitsetLSB(s);  // Correct LSB ordering
    }
 
    int minHamming = k + 1;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int hamming = (bits[i] ^ bits[j]).count();
            minHamming = max(minHamming, hamming);
        }
    }
 
    cout << minHamming << endl;
    return 0;
}
