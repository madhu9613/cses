#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string dna;
    cin >> dna;

    int max_count = 1, current_count = 1;
    
    for (int i = 1; i < dna.size(); ++i) {
        if (dna[i] == dna[i - 1]) {
            current_count++;
        } else {
            max_count = max(max_count, current_count);
            current_count = 1; 
        }
    }
    
    max_count = max(max_count, current_count);
    
    cout << max_count << endl;
    
    return 0;
}
