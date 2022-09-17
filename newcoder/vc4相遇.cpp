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
vector<vector<int>> graph;
vector<int> ind;
stack<int> stk;
// unordered_map<int, int> record;
// int dfs(int v)
// {

//     if(record.find(v) != record.end()) {
//         return record[v];
//     }

//     int cnt = 0;
//     for (int i = 0; i < graph[v].size(); ++i) {
//         cnt += dfs(graph[v][i]);
//     }

//     record[v] = cnt;
//     return cnt;
// }

int main()
{
    freopen("test.in", "r", stdin);
    cin >> n >> m >> t;
    // record[t] = 1;
    graph.resize(n + 1);
    ind.resize(n + 1);

    while (m--)
    {
        int u, v;
        cin >> u >> v;
        graph[u].emplace_back(v);
        ++ind[v]; // 统计入度
    }
    queue<int> que;
    stack<int> sorted;
    for (int i = 1; i <= n; ++i)
    {
        if(ind[i] == 0) // 入度为0的点加入队列
            que.emplace(i);
    }

    while (!que.empty())
    {
        int u = que.front();
        que.pop();
        sorted.emplace(u); // 已排序的点
        for (int v : graph[u])
        {
            if(--ind[v] == 0) {// u的下一跳入度减一，入度为0的点加入队列
                que.emplace(v);
            }
        }
    }

    vector<int> dp(n + 1);
    dp[t] = 1;
    while (!sorted.empty())
    {
        int u = sorted.top();
        sorted.pop();
        for (int v : graph[u]) { // 能到达该点的个数为 能达到上一跳点的个数之和
            dp[u] = (dp[u] + dp[v]) % MOD;
        }
    }

    cin >> q;
    while (q--)
    {
        int s;
        cin >> s;
        cout << dp[s] << endl;
    }
}