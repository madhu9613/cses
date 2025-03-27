/* minimum tower needed can we place maintain a data structure which will trac
 the top element of the tower we will find upper-bound if we found it erase it and place it in the
 top of it lets do it...
 */
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;cin>>n;
    multiset<int> topelements;
    for(int i=0;i<n;i++)
    {
        int p;cin>>p;
        auto it=topelements.upper_bound(p);
        if(it!=topelements.end())
        { 
            topelements.erase(it);
            topelements.insert(p);
        }
        else{
            topelements.insert(p);
        }

    }
    cout<<topelements.size()<<endl;
    return 0;
}