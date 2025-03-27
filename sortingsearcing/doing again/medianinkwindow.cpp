#include<bits/stdc++.h>
using namespace std;

class SlidingMedian {
    multiset<int> left, right;

    void balance() {
        while (left.size() > right.size() + 1) {
            right.insert(*left.rbegin());
            left.erase(--left.end());
        }
        while (right.size() > left.size()) {
            left.insert(*right.begin());
            right.erase(right.begin());
        }
    }

public:
    void insert(int num) {
        if (left.empty() || num <= *left.rbegin()) {
            left.insert(num);
        } else {
            right.insert(num);
        }
        balance();
    }

    void remove(int num) {
        if (left.find(num) != left.end()) {
            left.erase(left.find(num));
        } else {
            right.erase(right.find(num));
        }
        balance();
    }

    int getMedian() {
        return *left.rbegin();
    }
};

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    SlidingMedian medianFinder;

    for (int i = 0; i < k; i++) {
        medianFinder.insert(arr[i]);
    }
    cout << medianFinder.getMedian() << " ";

    for (int i = k; i < n; i++) {
        medianFinder.insert(arr[i]);
        medianFinder.remove(arr[i - k]);
        cout << medianFinder.getMedian() << " ";
    }
    cout << endl;
    return 0;
}
