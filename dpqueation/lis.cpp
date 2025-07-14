#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    vector<int> tail;  

    for (int x : a) {
        auto it = lower_bound(tail.begin(), tail.end(), x);
        if (it == tail.end()) {
            tail.push_back(x);  
        } else {
            *it = x;  
        }
    }

    cout << tail.size() << "\n";  
    return 0;
}
