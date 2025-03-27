#include <bits/stdc++.h>
using namespace std;
struct trienode
{
    trienode *children[2] = {nullptr, nullptr};
};
// 3 10 5 25 2 8

void insert(trienode* root, int n)
{
    trienode* node=root;
    for(int i=31;i>=0;i--)
    {
        int bit=(n>>i) &1;
        if(!node->children[bit])
        {
            node->children[bit]=new trienode;
        }
        node=node->children[bit];
    }
}

int findmaxXOR(trienode* root,int n)
{
    trienode* node=root;
    int maxXOR=0;
    for(int i=31;i>=0;i--)
    {
        int bit=(n>>i)&1;
        int opposite_bit=1-bit;
        if(node->children[opposite_bit])
        {
            maxXOR |=(1<<i);
            node=node->children[opposite_bit];
        }
        else{
            node=node->children[bit];
        }
    }
    return maxXOR;
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    int ans=0;
    trienode* root=new trienode();
    for(auto i:nums)
    {
        insert(root,i);
    }
    for(auto num:nums)
    {
        ans=max(ans,findmaxXOR(root,num));
    }
    cout<<ans<<endl;


    return 0;
}