#include <iostream>
#include <iomanip> // For setw()
using namespace std;

int main()
{
    int n;
    cin >> n;

    // Determine the maximum width needed for printing
    int max_val = n * n;
    int width = to_string(max_val).length() + 1; // Width based on the largest number

    for (int x = 1; x <= n; x++)
    {
        for (int y = 1; y <= n; y++)
        {
            int ans;
            if (x < y) // Column is bigger
            {
                if (y % 2 == 0)
                {
                    ans = (y - 1) * (y - 1) + x;
                }
                else
                {
                    ans = y * y - x + 1;
                }
            }
            else // Row is bigger or equal
            {
                if (x % 2 != 0)
                {
                    ans = (x - 1) * (x - 1) + y;
                }
                else
                {
                    ans = x * x - y + 1;
                }
            }

            cout << setw(width) << ans << " ";
        }
        cout << endl;
    }
    
    return 0;
}
