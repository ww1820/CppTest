#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> PII;
const int N = 11;

bool st[N];

// S[i] 记录 i 能正常到达的点
map<int, set<int>> S = {
    {1, {2, 4, 5, 8, 6}}, 
    {2, {1, 3, 4, 5, 6, 7, 9}}, 
    {3, {2, 5, 6, 4, 8}}, 
    {4, {1, 2, 5, 7, 8, 3, 9}}, 
    {5, {1, 2, 3, 4, 6, 7, 8, 9}}, 
    {6, {1, 2, 3, 5, 7, 8, 9}}, 
    {7, {2, 6, 4, 5, 8}}, 
    {8, {1, 3, 4, 5, 6, 7, 9}}, 
    {9, {2, 4, 5, 6, 8}}, 
};

// L[{i, j}] 表示 (i -> j) 需要跨过哪个点
map<PII, int> L = {
    {{1, 3}, 2}, {{1, 9}, 5}, {{1, 7}, 4},
    {{2, 8}, 5},
    {{3, 1}, 2}, {{3, 7}, 5}, {{3, 9}, 6},     
    {{4, 6}, 5},     
    {{6, 4}, 5},     
    {{7, 1}, 4}, {{7, 3}, 5}, {{7, 9}, 8},     
    {{8, 2}, 5},     
    {{9, 3}, 6}, {{9, 1}, 5}, {{9, 7}, 8},     
};

vector<int> points;

bool ok(int u, int i) {
    // 初始情况，返回true
    if(u == -1) return true;
    // 点不能重复走
    if(st[i]) return false;
    // u能正常到达i
    if(S[u].count(i)) return true;
    // u到i直接需要跨过的点已经遍历过
    if(st[L[{u, i}]]) return true;
    
    return false;
}

int dfs(int u, int len) {
    if(len == 1) return 0;
    int res = 0;
    for (int i = 0; i < points.size(); ++i) {
        if(ok(u, points[i])) {
            st[i] = true;
            res += dfs(i, len - 1);
            st[i] = false;
        }
    };
    return res;
}


int main() {
    vector<vector<char>> graph = {
        {'.', '.', '.'},
        {'*', '*', '*'},
        {'*', '*', '*'}
    };

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if(graph[i][j] == '.') {
                points.emplace_back(i * 3 + j + 1);
            }
        }
    }

    int res = 0;
    for (int i = 2; i <= points.size(); ++i) {
        memset(st, 0, sizeof(st));
        res += dfs(-1,i);
    }

    cout << res << endl;
    return 0;
}