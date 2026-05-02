#include <bits/stdc++.h>
using namespace std;

bool query(const vector<int> &indices)
{
    cout << "? " << indices.size();
    for (int idx : indices)
        cout << " " << idx;
    cout << endl;
    int f;
    cin >> f;
    if (f == -1)
        exit(0);
    // returns true iff the set contains an odd number of the three special positions
    return ((indices.size() + f) % 2 == 1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int total = 2 * n + 1;

        // 1. Find leftmost special index p1 (smallest prefix with odd parity)
        int lo = 1, hi = total;
        while (lo < hi)
        {
            int mid = (lo + hi) / 2;
            vector<int> s;
            for (int i = 1; i <= mid; ++i)
                s.push_back(i);
            if (query(s))
                hi = mid;
            else
                lo = mid + 1;
        }
        int p1 = lo;

        // 2. Find rightmost special index p3
        // We search for the smallest suffix length L such that the suffix [total-L+1 .. total] has odd parity.
        // Then p3 = total - L + 1.
        lo = 1, hi = total;
        while (lo < hi)
        {
            int mid = (lo + hi) / 2; // mid = candidate length
            vector<int> s;
            int start = total - mid + 1;
            for (int i = start; i <= total; ++i)
                s.push_back(i);
            if (query(s))
                hi = mid;
            else
                lo = mid + 1;
        }
        int p3 = total - lo + 1;

        // 3. Find middle special index p2 (between p1 and p3)
        lo = p1 + 1, hi = p3 - 1;
        while (lo < hi)
        {
            int mid = (lo + hi) / 2;
            vector<int> s;
            s.push_back(p1);
            for (int i = p1 + 1; i <= mid; ++i)
                s.push_back(i);
            s.push_back(p3);
            if (query(s))
                hi = mid;
            else
                lo = mid + 1;
        }
        int p2 = lo;

        cout << "! " << p1 << " " << p2 << " " << p3 << endl;
    }
    return 0;
}