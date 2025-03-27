#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> applicants(n);
    vector<int> apartments(m);

    for (int i = 0; i < n; i++) cin >> applicants[i];
    for (int i = 0; i < m; i++) cin >> apartments[i];

    // Sort both arrays
    sort(applicants.begin(), applicants.end());
    sort(apartments.begin(), apartments.end());

    int i = 0, j = 0, matches = 0;

    while (i < n && j < m) {
        // If the apartment size fits the applicant's range
        if (abs(apartments[j] - applicants[i]) <= k) {
            matches++;
            i++;
            j++;
        }
        // If the apartment size is too small
        else if (apartments[j] < applicants[i] - k) {
            j++;
        }
        // If the apartment size is too large
        else {
            i++;
        }
    }

    cout << matches << endl;
    return 0;
}
