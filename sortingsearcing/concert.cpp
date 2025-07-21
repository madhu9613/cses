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
int n,m;cin>>n>>m;
vll h(n),t(m);
multiset<ll>p;
for(int i=0;i<n;i++ ) cin>>h[i];
p.insert(all(h));
for(int i=0;i<m;i++) cin>>t[i];

for(auto price:t)
{
    auto it=upper_bound(all(p),price);
    if(it==p.begin()){
        cout<<-1<<endl;
    }else{
        it--;
        cout<<*it<<endl;
        p.erase(it);
    }

}



}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    
    while (t--) solve();
    return 0;
}