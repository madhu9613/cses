/**
 * There are n applicants and m free apartments. Your task is to distribute the apartments so that as many applicants as possible will get an apartment.
Each applicant has a desired apartment size, and they will accept any apartment whose size is close enough to the desired size.
*/
//
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> applicant(n);
    vector<int> appartment(m);
    for (int i = 0; i < n; i++)
    {
        cin >> applicant[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> appartment[i];
    }
    int i = 0;
    int j = 0;
    int cnt = 0;
    sort(applicant.begin(), applicant.end());
    sort(appartment.begin(), appartment.end());
    while (i < n && j < m)
    {
        if (abs(applicant[i] - appartment[j]) <= k)
        {
            // it will be sell
            cnt++;
            i++;
            j++;
        }
        else if(appartment[j]<applicant[i]-k)
        {
            j++;
        }
        else{
            i++;
        }

       
    }
    cout<<cnt<<endl;
    return 0;
}