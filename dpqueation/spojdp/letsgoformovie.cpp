#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct DP
{
    ll price;
    ll tickets;
    ll single;
    ll family;
};

ll S, F;
vector<vector<int>> tree;
vector<DP> dp;

DP better(const DP &a, const DP &b)
{
    if (a.price != b.price)
        return (a.price < b.price ? a : b);
    if (a.tickets != b.tickets)
        return (a.tickets < b.tickets ? a : b);
    return a;
}

void dfs(int u)
{
    // leaf default
    dp[u] = {S, 1, 1, 0};

    if (tree[u].empty())
        return;

    DP optSingle = {S, 1, 1, 0};
    DP optFamily = {F, 1, 0, 1};

    for (int v : tree[u])
    {
        dfs(v);

        // SINGLE: children choose optimally
        optSingle.price += dp[v].price;
        optSingle.tickets += dp[v].tickets;
        optSingle.single += dp[v].single;
        optSingle.family += dp[v].family;

        // FAMILY: skip child, add grandchildren
        for (int g : tree[v])
        {
            optFamily.price += dp[g].price;
            optFamily.tickets += dp[g].tickets;
            optFamily.single += dp[g].single;
            optFamily.family += dp[g].family;
        }
    }

    dp[u] = better(optSingle, optFamily);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc = 1;
    while (cin >> S >> F)
    {
        if (S == 0 && F == 0)
            break;

        unordered_map<string, int> id;
        vector<string> names;
        tree.clear();

        auto getId = [&](const string &s)
        {
            if (!id.count(s))
            {
                id[s] = names.size();
                names.push_back(s);
                tree.emplace_back();
            }
            return id[s];
        };

        string line;
        getline(cin, line);

        vector<int> hasParent;
        while (true)
        {
            streampos pos = cin.tellg();
            if (!getline(cin, line))
                break;
            if (line.empty())
                continue;
            if (isdigit(line[0]))
            {
                cin.seekg(pos);
                break;
            }

            stringstream ss(line);
            string p;
            ss >> p;
            int u = getId(p);

            if ((int)hasParent.size() < (int)names.size())
                hasParent.resize(names.size(), 0);

            string c;
            while (ss >> c)
            {
                int v = getId(c);
                if ((int)hasParent.size() < (int)names.size())
                    hasParent.resize(names.size(), 0);
                tree[u].push_back(v);
                hasParent[v] = 1;
            }
        }

        int n = names.size();
        dp.assign(n, {});

        DP ans = {0, 0, 0, 0};

        for (int i = 0; i < n; i++)
        {
            if (i >= (int)hasParent.size() || !hasParent[i])
            {
                dfs(i);
                ans.price += dp[i].price;
                ans.tickets += dp[i].tickets;
                ans.single += dp[i].single;
                ans.family += dp[i].family;
            }
        }

        cout << tc++ << ". "
             << ans.single << " "
             << ans.family << " "
             << ans.price << "\n";
    }
}
