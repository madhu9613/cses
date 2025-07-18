#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;cin>>s;
    map<char,bool>used;
    for(auto&c:s)
    {
        used[c]=1;
        if(used.size()==4)
        {
            cout<<c;
            used.clear();
        }
    }
    if(!used['A'])cout<<'A';
    else if(!used['C'])cout<<'C';
    else if(!used['G'])cout<<'G';
    else cout<<'T';
}