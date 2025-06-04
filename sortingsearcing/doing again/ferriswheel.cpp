 #include<bits/stdc++.h>
 using namespace std;
 int main()
 {
    int n,x;
    cin>>n>>x;
    vector<int> w;
    for(int i=0;i<n;i++)
    {
        int data;cin>>data;
        w.push_back(data);
    }
    sort(w.begin(),w.end());
    
    
    return 0;
 }