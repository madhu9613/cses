#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        long long x, y;
        cin >> x >> y;
        long long ans;

        if(x < y) // Column is bigger
        {
            if(y % 2 == 0)
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
            if(x % 2 != 0)
            {
                ans = (x - 1) * (x - 1) + y;
            }
            else
            {
                ans = x * x - y + 1;
            }
        }

        cout << ans << endl;
    }

    return 0;
}
