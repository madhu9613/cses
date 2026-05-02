#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int MAXA = 200000;

vector<int> spf(MAXA + 1);

ll gcdll(ll a, ll b) {
    return b == 0 ? a : gcdll(b, a % b);
}

void build_spf() {
    for (int i = 1; i <= MAXA; i++) spf[i] = i;
    for (int i = 2; i * i <= MAXA; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j <= MAXA; j += i) {
                if (spf[j] == j)
                    spf[j] = i;
            }
        }
    }
}

vector<pair<ll, int>> factorize(ll x) {
    vector<pair<ll, int>> f;
    while (x > 1) {
        ll p = spf[x];
        int cnt = 0;
        while (x % p == 0) {
            x /= p;
            cnt++;
        }
        f.push_back({ p, cnt });
    }
    return f;
}

void gen_divisors(
    int idx,
    ll cur,
    const vector<pair<ll, int>>& f,
    vector<ll>& divs
) {
    if (idx == (int)f.size()) {
        divs.push_back(cur);
        return;
    }
    ll p = f[idx].first;
    int cnt = f[idx].second;

    for (int i = 0; i <= cnt; i++) {
        gen_divisors(idx + 1, cur, f, divs);
        cur *= p;
    }
}

void solve() {
    int n;
    cin >> n;

    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    ll L, R;
    cin >> L >> R;
    ll low = max(2LL, L);

    vector<int> divs;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            divs.push_back(i);
            if (i != n / i) divs.push_back(n / i);
        }
    }

    unordered_map<ll, ll> memo;
    ll answer = 0;

    for (int k : divs) {
        ll g = 0;
        for (int i = 0; i + k < n; i++) {
            g = gcdll(g, llabs(a[i] - a[i + k]));
            if (g == 1) break;
        }

        if (g == 1) continue;

        if (memo.count(g)) {
            answer += memo[g];
            continue;
        }

        ll cnt = 0;

        if (g == 0) {
            if (low <= R)
                cnt = R - low + 1;
        }
        else {
            auto factors = factorize(g);
            vector<ll> d;
            gen_divisors(0, 1, factors, d);
            for (ll m : d) {
                if (m >= low && m <= R)
                    cnt++;
            }
        }

        memo[g] = cnt;
        answer += cnt;
    }

    cout << answer << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    build_spf();

    int t;
    cin >> t;
    while (t--) solve();
}
