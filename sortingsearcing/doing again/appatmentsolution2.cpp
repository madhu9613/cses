/*
not more optimaL BUT GOOD SOLUTION
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> applicant(n);
    vector<int> apartment(m);

    for (int i = 0; i < n; i++) {
        cin >> applicant[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> apartment[i];
    }

    sort(applicant.begin(), applicant.end());
    sort(apartment.begin(), apartment.end());

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        // Find the lower and upper bounds for the current applicant
        int lower = applicant[i] - k;
        int upper = applicant[i] + k;
        
        // Find the first apartment that is >= lower and <= upper
        auto lowerBound = lower_bound(apartment.begin(), apartment.end(), lower);
        auto upperBound = upper_bound(apartment.begin(), apartment.end(), upper);

        // If there is an apartment within the range
        if (lowerBound != upperBound) {
            cnt++;
            // Remove the selected apartment from the available apartments
            apartment.erase(lowerBound);
        }
    }

    cout << cnt << endl;
    return 0;
}
