/**
 * smallest kth set element
 */
#include <iostream>
using namespace std;

int smallestNumberWithKSetBits(int K)
{
    return (1 << K) - 1;
}

int main()
{
    int k;
    cin >> k;
 
    cout << "Smallest number with " << k << " set bits: "
         << smallestNumberWithKSetBits(k) << endl;

    return 0;
}
