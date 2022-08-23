#include<bits/stdc++.h>

using namespace std;

// int n = 100000, m = 100000;
int n = 100, m = 100;
int p = 14, q = 10;
// vector<vector<char>> board(n, vector<char>(m, 'c'));
vector<vector<bool>> board(n, vector<bool>(m, true));
//三种状态 a: 未被包围 b: 绘制的边界 c: 被包围

void dfs(vector<vector<bool>>& board, int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= m || !board[x][y]) {
        return;
    }
    board[x][y] = false;
    dfs(board, x + 1, y);
    dfs(board, x - 1, y);
    dfs(board, x, y + 1);
    dfs(board, x, y - 1);
}

int main() {
    
    // 这两个数组不需要存
    vector<vector<int>> boundary = {{1, 1}, {1, 2}, {1, 3}, {1, 4}, {1, 5}, {2, 1}, {2, 5}, {3, 1}, {3, 4}, {3, 5}, {4, 1}, {4, 2}, {4, 3}, {4, 4}};
    vector<vector<int>> test = {{0, 0}, {1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}, {60, 60}, {70, 70}, {80, 80}, {90, 90}};

    unordered_set<string> tmp;
    // unordered_set<string> tmp = {"1,1", "1,2", ... , "4,3", "4,4"};

    for (int i = 0; i < p; ++i) {
        int x = boundary[i][0];
        int y = boundary[i][1];
        tmp.insert((to_string(x) + "," +to_string(y)));
        board[x][y] = false;
    }

    for (int i = 0; i < n; i++) {
        dfs(board, i, 0);
        dfs(board, i, m - 1);
    }
    for (int i = 1; i < m - 1; i++) {
        dfs(board, 0, i);
        dfs(board, n - 1, i);
    }

    for (int i = 0; i < q; ++i) {
        int x = test[i][0];
        int y = test[i][1];
        string s = (to_string(x) + "," +to_string(y));
        if(tmp.find(s) != tmp.end()) {
            cout << "1";
        }
        else
        {
            cout << board[x][y];
        }
    }

    return 0;
}
