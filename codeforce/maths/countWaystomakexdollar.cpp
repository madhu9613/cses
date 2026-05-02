/**
 *  given X;
 * and a,b,c count such that i*a+j*b+c*k=X count possible triplet of(i,j,k) and they are intergers
 * 
 *
 */


#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll extended_gcd(ll a, ll b, ll& x, ll& y) {
    if (b == 0) {
        x = 1; y = 0;
        return a;
    }
    ll x1, y1;
    ll g = extended_gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return g;
}

// modular inverse of a mod m
ll modInverse(ll a, ll m) {
    ll x, y;
    extended_gcd(a, m, x, y);
    // cout<<x<<" "<<y<<endl; 
       return (x % m + m) % m;
}

int main() {
    ll a, b, c, x;
    cin >> a >> b >> c >> x;

    ll ways = 0;

    for (ll i = 0; i * a <= x; i++) {
        ll rem = x - i * a;

        ll g = gcd(b, c);
        if (rem % g != 0) continue;

        ll b1 = b / g;
        ll c1 = c / g;
        ll rem1 = rem / g;

        // solve b1 * j ≡ rem1 (mod c1)
        ll inv = modInverse(b1, c1);
        ll j0 = (rem1 % c1 * inv) % c1;

        // max j allowed
        ll max_j = rem / b;

        if (j0 > max_j) continue;

        // count valid j
        ll count = (max_j - j0) / c1 + 1;

        ways += count;
    }

    cout << ways << endl;
    return 0;
}