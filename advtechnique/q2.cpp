/**The Hamming distance between two strings a and b of equal length is the number of positions where the strings differ.
You are given n bit strings, each of length k and your task is to calculate the minimum Hamming distance between two strings. */
#include<bits/stdc++.h>
using  namespace std;
int solve(string a, string b)
{
     int a_int = 0, b_int = 0;

    for (int i = 0; i < a.length(); ++i) {
        a_int = a_int * 2 + (a[i] - '0');
        b_int = b_int * 2 + (b[i] - '0'); 
    }

    int xor_result = a_int ^ b_int;

    return bitset<32>(xor_result).count(); 
}

int main()
{
    int n,k;
    cin>>n>>k;
     vector<string> strings(n);
    for (int i = 0; i < n; ++i) {
        cin >> strings[i];
    }
   
//  int mini=INT_MAX;
//     for(int i=0;i<n;i++)
//     {
//         for(int j=i+1;j<n;j++)
//         {
//             int dist=solve(strings[i],strings[j]);
//             mini=min(mini,dist);
//         }
//     }
//     cout<<mini<<endl;
    // --- do one thing sort the strings in lexicographical order 
    sort(strings.begin(),strings.end());

 int mini=INT_MAX;
    for(int i=0;i<n-1;i++)
    {
          int dist=solve(strings[i],strings[i+1]);
            mini=min(mini,dist);
       
    }
    cout<<mini<<endl;
    return 0;
}