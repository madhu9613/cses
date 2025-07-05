#include <bits/stdc++.h>
using namespace std;

int main()
{
    int tt;
    cin >> tt;
    while (tt--)
    {
        int n;
        cin >> n;
        vector<int> w(n);
        int sum=0;
        for (int i = 0; i < n; i++)
        {
            cin >> w[i];
            sum+=w[i];
        }

        

       map<int, int> suffix_pos; 
       vector<int>suffix_sum;
        int sum = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            sum += w[i];
            suffix_pos[sum] = i; 
            suffix_sum[i]=sum;

        }

        int psum = 0,ans=0;
        for (int i = 0; i <= n; i++)
        {
            suffix_pos

        }

        cout << ans << endl;
    }
    return 0;
}
