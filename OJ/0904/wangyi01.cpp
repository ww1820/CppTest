#include<bits/stdc++.h>
#include "/data/workspace/cpp_test/tool.h"

using namespace std;

/*
3
1 2 3
1 2
1 3
*/

vector<vector<int>> tree;
unordered_map<int, int> weight;
vector<int> ans;

unordered_set<int> dfs(int v)
{
    unordered_set<int> factors;
    int product = 1;
    for (int i = 0; i < tree[v].size(); ++i)
    {
        unordered_set<int> tmp = dfs(tree[v][i]);
        factors.insert(tmp.begin(), tmp.end());
        product *= weight[tree[v][i]];
    }

    int w = weight[v];
    product *= w;

    factors.insert(1);
    factors.insert(product);

    for(int i = 2; i * i <= w; ++i) {
        if (w % i == 0)
        {
            factors.insert(w);
        }
    }

    ans[v] = factors.size();
    return factors;
}

int main() {
    int n;
    infile >> n;

    tree.resize(n);
    ans.resize(n);

    for (int i = 0; i < n; ++i)
    { // 权重
        int w;
        infile >> w;
        weight.emplace(i,w);
    }

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        infile >> u >> v;
        tree[u - 1].emplace_back(v - 1);
    }

    dfs(0);

    cout << accumulate(ans.begin(), ans.end(), 0);
    return 0;
}