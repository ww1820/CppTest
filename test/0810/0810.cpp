#include<bits/stdc++.h>

using namespace std;

vector<int> nodes; // 红蓝节点之差 + R - B
vector<bool> visited;
void dfs(int v, string color, vector<vector<int>> &edges) {
    visited[v] = true;
    nodes[v] += color[v] == 'R' ? 1 : -1;
    for (const auto &u : edges[v])
    {
        if(!visited[u]) {
            nodes[u] = nodes[v];
            dfs(u, color, edges);
        }
    }
}

int main() {
    vector<vector<int>> vec{{2, 5}, {1, 5}, {4, 1}, {3, 5}};
    string color = "RBRBB";
    int n = color.length();
    vector<vector<int>> edges(n);
    nodes.resize(n); // 记录红蓝节点数量之差
    visited.resize(n); // 记录节点是否已访问

    for(const auto& elem : vec) {
        edges[elem[0] - 1].emplace_back(elem[1] - 1);
        edges[elem[1] - 1].emplace_back(elem[0] - 1);
    }

    dfs(0, color, edges);

    int res = 0;
    for(auto i : nodes) {
        res += abs(i);
    }

    cout << res << endl;
    return 0;
}