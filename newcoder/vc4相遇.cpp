/*
输入：
4 5 4
1 2
1 3
2 4
2 3
3 4
4
1
2
3
4
输出：
3
2
1
1
*/

#include<bits/stdc++.h>
#include<vector>

using namespace std;

const int MOD = 100007;
int n, m, t, q;
unordered_map<int, int> record;
vector<vector<int>> graph;
int dfs(int v)
{
    
    if(record.find(v) != record.end()) {
        return record[v];
    }

    int cnt = 0;
    for (int i = 0; i < graph[v].size(); ++i) {
        cnt += dfs(graph[v][i]);
    }

    record[v] = cnt;
    return cnt;
}

int main()
{
    freopen("test.in", "r", stdin);
    cin >> n >> m >> t;
    record[t] = 1;
    graph.resize(n + 1);
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        graph[u].emplace_back(v);
    }

    cin >> q;

    while (q--)
    {
        int s;
        cin >> s;
        cout << dfs(s) << endl;
    }
}