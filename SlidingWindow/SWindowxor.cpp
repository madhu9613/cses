#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    ll x, a, b, c;
    cin >> x >> a >> b >> c;

    ll *buffer = new ll[k]; 
    ll window_xor = 0;     
    ll result = 0;

    for (int i = 0; i < n; ++i)
    {
        if (i != 0)
            x = (a * x + b) % c;

        int pos = i % k;

        if (i >= k)
        {
            window_xor ^= buffer[pos];
        }

        buffer[pos] = x;
        window_xor ^= x; 
        if (i >= k - 1)
        {
            result ^= window_xor;
        }
    }

    cout << result << "\n";
    delete[] buffer;
    return 0;
}
