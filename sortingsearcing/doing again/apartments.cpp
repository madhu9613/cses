#include <bits/stdc++.h>

using namespace std;
int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> applicant, apertment;
    for (int i = 0; i < n; i++)
    {
        int data;
        cin >> data;
        applicant.push_back(data);
    }
    for (int i = 0; i < m; i++)
    {
        int a;
        cin >> a;
        apertment.push_back(a);
    }
    sort(applicant.begin(), applicant.end()); //nlogn
    sort(apertment.begin(), apertment.end());
    int i = 0;
    int j = 0;
    int count = 0;
    while (i < n && j < m) //o(n);
    {
        if (abs(applicant[i] - apertment[j]) <= k)
        {
            // i can sell this appertment
            i++;
            j++;
            count++;
        }else if(apertment[j]<applicant[i]-k)
        {
            j++;
        }
        else{
            i++;
        }
    }
    cout<<count<<endl;

    return 0;
}