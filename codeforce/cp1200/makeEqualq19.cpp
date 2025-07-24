// Author: Madhujya Rajkhowa
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define all(x) (x).begin(), (x).end()
#define endl '\n'

const int MOD = 1e9 + 7;
const int INF = INT_MAX;

void solve()
{
    int n;
    char c;
    cin >> n >> c;
    string s;
    cin >> s;
    bool isallsame = true;
    for (int i = 0; i < n; i++)
    {
        if (s[i] != c)
        {
            isallsame = false;
            break;
        }
    }
    if (isallsame)
    {
        cout << 0 << endl;
        return;
    }

    //check fr 1 operation

    int idx = -1;
    for (int i = 2; i <= n; i++)
    {
        bool isPoss = true;
        for (int j = i; j <= n; j += i)
        {
            if (s[j - 1] != c)
            {
                isPoss = false;
                break;
            }
        }

        if (isPoss)
        {
            idx = i;
            break;
        }
    }
    if(idx!=-1)
    {
        cout<<1<<endl;
        cout<<idx<<endl;
        return;
    }

    cout<<2<<endl;
    cout<<n-1<<" "<<n<<endl;
    
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}