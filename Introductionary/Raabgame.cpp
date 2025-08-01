#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>

void solve() {
    int n, a, b;
    cin >> n >> a >> b;

    if (a + b >= n) {
        cout << "NO\n";
        return;
    }

    if(n==2)
    {
        if(a==0 || b==0)
        {
            cout<<"NO"<<endl;
            return ;
        }
    }

    vi p1(n), p2(n);
    iota(p1.begin(), p1.end(), 1);
    iota(p2.begin(), p2.end(), 1); 

    sort(p1.rbegin(), p1.rend());
    sort(p2.begin(), p2.end());

    vi A(n), B(n);
    int idx = 0;

    
    for (int i = 0; i < a; i++) {
        A[idx] = p1[i];
        B[idx] = p2[i];
        idx++;
    }

    for (int i = 0; i < b; i++) {
        A[idx] = p2[i];
        B[idx] = p1[i];
        idx++;
    }

    int val = 1;
    while (idx < n) {
        A[idx] = val;
        B[idx] = val;
        idx++;
        val++;
    }

    cout << "YES\n";
    for (int i = 0; i < n; i++) cout << A[i] << " ";
    cout << "\n";
    for (int i = 0; i < n; i++) cout << B[i] << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}
