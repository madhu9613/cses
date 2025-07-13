#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

string find_mex(const string &s) {
    unordered_set<string> substrings;
    int n = s.size();

    for (int len = 1; len <= 3; ++len) {
        for (int i = 0; i + len <= n; ++i) {
            substrings.insert(s.substr(i, len));
        }
    }

    for (char c = 'a'; c <= 'z'; ++c) {
        string str(1, c);
        if (!substrings.count(str)) return str;
    }

    for (char c1 = 'a'; c1 <= 'z'; ++c1) {
        for (char c2 = 'a'; c2 <= 'z'; ++c2) {
            string str = {c1, c2};
            if (!substrings.count(str)) return str;
        }
    }

    for (char c1 = 'a'; c1 <= 'z'; ++c1) {
        for (char c2 = 'a'; c2 <= 'z'; ++c2) {
            for (char c3 = 'a'; c3 <= 'z'; ++c3) {
                string str = {c1, c2, c3};
                if (!substrings.count(str)) return str;
            }
        }
    }

    return ""; 
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        cout << find_mex(s) << '\n';
    }
    return 0;
}
