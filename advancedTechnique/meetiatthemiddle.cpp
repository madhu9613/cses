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
void generateSubsetSums(const vector<long long>& arr, vector<long long>& sums) {
    int n = arr.size();
    for (int mask = 0; mask < (1 << n); ++mask) {
        long long sum = 0;
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                sum += arr[i];
            }
        }
        sums.push_back(sum);
    }
}
void solve() {
    int n;
    long long x;
    cin >> n >> x;
    vector<long long> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
 
    vector<long long> left(arr.begin(), arr.begin() + n / 2);
    vector<long long> right(arr.begin() + n / 2, arr.end());
      vector<long long> leftSums, rightSums;
    generateSubsetSums(left, leftSums);
    generateSubsetSums(right, rightSums);
 
    sort(rightSums.begin(), rightSums.end());
 
    long long count = 0;
    for (long long sum : leftSums) {
        long long target = x - sum;
        count += upper_bound(rightSums.begin(), rightSums.end(), target) -
                 lower_bound(rightSums.begin(), rightSums.end(), target);
    }
 
    cout << count << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    while (t--) solve();
    return 0;
}