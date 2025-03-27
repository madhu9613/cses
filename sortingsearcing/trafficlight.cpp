#include <bits/stdc++.h>
using namespace std;

int main() {
    long long x, n;
    scanf("%lld %lld", &x, &n);

    set<long long> lights = {0, x};
    multiset<long long> segments = {x};

    for (int i = 0; i < n; ++i) {
        long long p;
        scanf("%lld", &p);

        auto upper = lights.upper_bound(p);
        auto lower = prev(upper);

        long long left = *lower;
        long long right = *upper;

        segments.erase(segments.find(right - left));
        segments.insert(p - left);
        segments.insert(right - p);

        lights.insert(p);

        printf("%lld ", *segments.rbegin());
    }

    return 0;
}
