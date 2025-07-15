#include <bits/stdc++.h>
using namespace std;
vector<int> segTree;
vector<int> arr;

void BuildTree(int node, int l, int r)
{
   if (l == r)
   {
      segTree[node] = arr[l];
   }
   else
   {
      int mid = l + (r - l) / 2;
      BuildTree(2 * node, l, mid);
      BuildTree(2 * node + 1, mid + 1, r);
      segTree[node] = min(segTree[2 * node], segTree[2 * node + 1]);
   }
}

int query(int node, int l, int r, int ql, int qr)
{
   if (ql > r || qr < l)
      return INT_MAX; // here its out of bound
   if (ql <= l && r <= qr)
   {
      // conpletly overlapping
      return segTree[node];
   }
   int mid = l + (r - l) / 2;
   return min(query(2 * node, l, mid, ql, qr),
              query(2 * node + 1, mid + 1, r, ql, qr));
}

int main()
{
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   int n, q;
   cin >> n >> q;
   segTree.resize(4 * n);
   arr.resize(n + 1);
   for (int i = 1; i <= n; i++)
   {
      cin >> arr[i];
   }

   BuildTree(1,1,n);
   while (q--)
   {
      int a,b;
      cin>>a>>b;
      cout<<query(1,1,n,a,b)<<"\n";
   }
   
   return 0;
}