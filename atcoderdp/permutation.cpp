#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int MOD = 1e9 + 7;

struct ModInt {
    long long v;
    ModInt(long long _v = 0) {
        v = (_v % MOD + MOD) % MOD;
    }
    ModInt& operator+=(const ModInt& other) {
        v = (v + other.v) % MOD;
        return *this;
    }
    ModInt operator+(const ModInt& other) const {
        return ModInt(*this) += other;
    }
    ModInt& operator-=(const ModInt& other) {
        v = (v - other.v + MOD) % MOD;
        return *this;
    }
    ModInt operator-(const ModInt& other) const {
        return ModInt(*this) -= other;
    }
};

void solve() {
    int N;
    string S;
    cin >> N >> S;

    vector<vector<ModInt>> dp(N + 1, vector<ModInt>(N + 1, 0));

    dp[1][1] = 1;

    for (int len = 2; len <= N; len++) {
        vector<ModInt> prefix(len);
        prefix[0] = 0;
        for (int j = 1; j < len; j++) {
            prefix[j] = prefix[j - 1] + dp[len - 1][j];
        }

        for (int j = 1; j <= len; j++) {
         
            if (S[len - 2] == '<') {
               
                dp[len][j] += prefix[j - 1];
            } else { 
                dp[len][j] += prefix[len - 1] - prefix[j - 1];
            }
        }
    }

    ModInt answer = 0;
    for (int j = 1; j <= N; j++) {
        answer += dp[N][j];
    }
    cout << answer.v << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}