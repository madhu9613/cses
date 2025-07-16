#include <bits/stdc++.h>
using namespace std;

multiset<int> LeftHalf, RightHalf;
long long sumLeft = 0, sumRight = 0;

void balance() {
    while (LeftHalf.size() < RightHalf.size()) {
        auto it = RightHalf.begin();
        LeftHalf.insert(*it);
        sumLeft += *it;
        sumRight -= *it;
        RightHalf.erase(it);
    }
    while (LeftHalf.size() > RightHalf.size() + 1) {
        auto it = prev(LeftHalf.end());
        RightHalf.insert(*it);
        sumLeft -= *it;
        sumRight += *it;
        LeftHalf.erase(it);
    }
}

void insert(int val) {
    if (LeftHalf.empty() || val <= *LeftHalf.rbegin()) {
        LeftHalf.insert(val);
        sumLeft += val;
    } else {
        RightHalf.insert(val);
        sumRight += val;
    }
    balance();
}

void erase(int val) {
    auto it = LeftHalf.find(val);
    if (it != LeftHalf.end()) {
        sumLeft -= val;
        LeftHalf.erase(it);
    } else {
        it = RightHalf.find(val);
        if (it != RightHalf.end()) {
            sumRight -= val;
            RightHalf.erase(it);
        }
    }
    balance();
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    for (int i = 0; i < n; ++i) {
        insert(a[i]);
        if (i >= k) erase(a[i - k]);

        if (i >= k - 1) {
            int median = *LeftHalf.rbegin();
            long long cost = 1LL * median * LeftHalf.size() - sumLeft
                           + sumRight - 1LL * median * RightHalf.size();
            cout << cost << " ";
        }
    }

    cout << endl;
    return 0;
}
