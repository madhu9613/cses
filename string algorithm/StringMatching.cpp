// Author: Madhujya Rajkhowa
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define all(x) (x).begin(), (x).end()
#define endl '\n'

const int MOD = 1e9 + 7;
const int INF = INT_MAX;


mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll Z = 1111111111111111111;  // large prime
const ll C = uniform_int_distribution<ll>(Z / 10, Z / 10 * 9)(rng);  // random base

struct HashString {
    ll mul(ll a, ll b) { return __int128(a) * b % Z; }

    int n;
    vector<ll> pows, sums;

    HashString(const string& s) : n(s.size()), pows(n + 1, 1), sums(n + 1) {
        for (int i = 1; i <= n; i++) {
            pows[i] = mul(pows[i - 1], C);
            sums[i] = (mul(sums[i - 1], C) + s[i - 1]) % Z;
        }
    }

    // Hash of substring [l, r)
    ll hash(int l, int r) {
        ll h = sums[r] - mul(sums[l], pows[r - l]);
        return (h % Z + Z) % Z;
    }
};


//Goal howmany times pattern appear in the text;
// here i am using hash based algo also called rabin-karp algo its new to me lets learn it in details also i heard about z algo also learn it latter after this ...

void solve() {
    string text, pattern;
    cin >> text >> pattern;

    
    int n = text.size(), m = pattern.size();

    if (m > n) {
        cout << 0 << endl;
        return ;
    }

    HashString h_text(text);
    HashString h_pattern(pattern);

    ll pattern_hash = h_pattern.hash(0, m); //hash value of the pattern (for eg>{"pp"})
    int count = 0;

    for (int i = 0; i + m <= n; i++) {
        //cheking in window size of m if we found hashing is equal then we matched a patter 
        // "for the "saippuakauppias" we will check {"sa","ai","ip","pp":we found count++,} like this;
        
        if (h_text.hash(i, i + m) == pattern_hash) {
            count++;
        }
    }

    cout << count << '\n';

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    while (t--) solve();
    return 0;
}