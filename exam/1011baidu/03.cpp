# include<bits/stdc++.h>

using namespace std;

unordered_map<int, long long> weight;
vector<vector<int>> edges;
vector<int> res;

void operate(int x, long long y, int cnt)
{
    res[x] += cnt;
    weight[x] *= y;
    for(int v : edges[x]) {
        operate(v, y, cnt);
    }
    while(weight[x] >= 10 && weight[x] % 10 == 0) {
        ++res[x];
        weight[x] /= 10;
    }
}

long long dfs(int v) {
    long long w = 1;
    for(int u : edges[v]) {
        w *= dfs(u);
        res[v] += res[u];
    }

    w *= weight[v];
    while(w >= 10 && w % 10 == 0) {
        ++res[v];
        w /= 10;
    }
    return w;
}

// long long dfs(int v) {
//     for(int u : edges[v]) {
//         weight[v] *= dfs(u);
//     }
//     return weight[v];
// }

int main() {

    freopen("../test.in", "r", stdin);
    int n;
    cin >> n;
    
    edges.resize(n + 1);
    res.resize(n + 1);

    for (int i = 1; i <= n; ++i)
    {
        long long w;
        cin >> w;
        weight[i] = w;
    }

    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
    }

    int q;

    cin >> q;

    while (q--)
    {
        int x;
        long long y;
        cin >> x >> y;
        int cnt = 0;
        while (y >= 10 && y % 10 == 0)
        {
            ++cnt;
            y /= 10;
        }
        operate(x, y, cnt);
    }

    dfs(1);

    for (int i = 1; i < n; ++i) {
        cout << res[i] << " ";
    }
    cout << res[n];
    // for (int i = 1; i <= n; ++i) {
    //     int cnt = 0;
    //     while(weight[i] >= 10 && weight[i] % 10 == 0) {
    //         ++cnt;
    //         weight[i] /= 10;
    //     }
    //     cout << cnt << " ";
    // }
}