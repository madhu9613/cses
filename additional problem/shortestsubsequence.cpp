#include <bits/stdc++.h>
using namespace std;

string findMissingDNA(string &s) {
    unordered_set<string> seen1, seen2, seen3;
    int n = s.size();

    // Store all single, double, and triple character sequences
    for (int i = 0; i < n; i++) {
        seen1.insert(string(1, s[i]));  // Single character
        if (i > 0) seen2.insert(s.substr(i - 1, 2));  // Two characters
        if (i > 1) seen3.insert(s.substr(i - 2, 3));  // Three characters
    }

    // Check single character sequences
    for (char c : {'A', 'C', 'G', 'T'}) {
        string t(1, c);
        if (!seen1.count(t)) return t;
    }

    // Check two-character sequences
    for (char c1 : {'A', 'C', 'G', 'T'}) {
        for (char c2 : {'A', 'C', 'G', 'T'}) {
            string t = {c1, c2};
            if (!seen2.count(t)) return t;
        }
    }

    // Check three-character sequences
    for (char c1 : {'A', 'C', 'G', 'T'}) {
        for (char c2 : {'A', 'C', 'G', 'T'}) {
            for (char c3 : {'A', 'C', 'G', 'T'}) {
                string t = {c1, c2, c3};
                if (!seen3.count(t)) return t;
            }
        }
    }

    return "";  // This should never happen
}

int main() {
    string s;
    cin >> s;
    cout << findMissingDNA(s) << endl;
    return 0;
}
