#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;  

    if (n == 1) {
        cout << 1 << endl;  
    } else if (n == 2 || n == 3) {
        cout << "NO SOLUTION" << endl;  
    } else {
        vector<int> result;

        
        for (int i = 2; i <= n; i += 2) {
            result.push_back(i);
        }
        
        
        for (int i = 1; i <= n; i += 2) {
            result.push_back(i);
        }

       
        for (int i = 0; i < result.size(); i++) {
            cout << result[i] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
