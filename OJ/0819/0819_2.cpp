#include<bits/stdc++.h>

using namespace std;


constexpr static int dx[4] = {0, 1, 0, -1};
constexpr static int dy[4] = {1, 0, -1, 0};

void dfs(int x, int y, vector<vector<int>> &grid, int n, int m, int &S,int &L) {
    if (x < 0 || x >= n || y < 0 || y >= m || grid[x][y] == 0) {
        L += 1;
        return;
    }
    if (grid[x][y] == 2) {
        return;
    }
    grid[x][y] = 2;
    ++S;
    int res = 0;
    for (int i = 0; i < 4; ++i) {
        int tx = x + dx[i];
        int ty = y + dy[i];
        dfs(tx, ty, grid, n, m, S, L);
    }
    return;
}
int PerimeterOfMaxAreq(vector<vector<int>> &grid) {
    int n = grid.size(), m = grid[0].size();
    int maxArea = 0;
    int Perimeter = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int S = 0, L = 0;
            if (grid[i][j] == 1){
                dfs(i, j, grid, n, m, S, L);
                Perimeter = S > maxArea ? L : Perimeter;
                maxArea = max(maxArea, S);
            }
        }
    }
    return Perimeter;
}

int main() {
    vector<vector<int>> grid = {
        {0, 0, 1, 0, 0},
        {0, 0, 1, 1, 1},
        {0, 0, 0, 0, 0},
        {1, 0, 0, 1, 0},
        {1, 0, 0, 1, 1}
    };
    printf("%d\n", PerimeterOfMaxAreq(grid));
    return 0;
}