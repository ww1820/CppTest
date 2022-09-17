/*
输入：
4 3
0 1
0 3
0 4
0 10
输出：
4
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> father;

int find(int x) {
    return father[x] == x ? x : father[x] = find(father[x]);
}

int main() {
    freopen("test.in", "r", stdin);
    int n, k;
    cin >> n >> k;

    if(k == 1) { // k = 1 时，w = 0. 基站自己与自己通信
        printf("0\n");
        return 0;
    }

    vector<pair<int,int>> points(n);
    father.resize(n);

    for (int i = 0; i < n; ++i) {
        cin >> points[i].first >> points[i].second;
    }

    vector<vector<int>> edges;
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j) {
            int dis = (points[i].first - points[j].first) * (points[i].first - points[j].first) + (points[i].second - points[j].second) * (points[i].second - points[j].second);
            edges.emplace_back(vector<int>{i, j, dis});
        }
    }

    sort(edges.begin(), edges.end(), [](vector<int>& a, vector<int>& b) { 
        return a[2] < b[2]; 
    });

    
    vector<int> sz(n, 1);

    for (int i = 0; i < n; ++i) {
        father[i] = i;
    }

    for (auto e : edges)
    {
        int p = find(e[0]);
        int q = find(e[1]);
        if(p ^ q) { // p != q // 合并两个集合
            father[p] = q; // p 的 根节点改为 q
            sz[q] += sz[p]; 
            if(sz[q] >= k) {
                printf("%d\n", e[2]);
                return 0;
            }
        }
    }
    return 0;
}