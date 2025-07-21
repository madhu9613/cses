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

void solve() {
int n;cin>>n;
ll Wmax; cin>>Wmax;
vll w(n);for(int i=0;i<n;i++) cin>>w[i];
//sort the gondola (why>. i need to buy minimum number of gondolas..what greedy say:if i combine smallest weight child with maximum child i can minimize it .. if two smallest comes together we will have to give single to largest ...trying greedy)

sort(all(w));
int count=0;int i=0,j=n-1;
while (i<=j)  //why i<=j ..(reason if i do i<j it will skip when i==j means one unpaired child will be left out..)
{
    if((w[i]+w[j])<=Wmax)
    {
        //this belongs to (i,j)
        i++; j--;count++;
    }else{
      //give j one i mean alone
      j--;count++;
    }

}
cout<<count<<endl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    while (t--) solve();
    return 0;
}