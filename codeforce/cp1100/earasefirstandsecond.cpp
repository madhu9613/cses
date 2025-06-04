#include <iostream>
#include <string>
#include<map>
using namespace std;

long long solve(string s){

    map<char,int> freq;
    long long  ans=0;
    int count=0;
    for(int i=0;i<s.length();i++)
    {
        freq[s[i]]++;
        if(freq[s[i]]==1)
        {
            count++;
        }
        ans+=count;
    }
    return ans;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        cout<<solve(s)<<endl;
      
    }

    return 0;
}
