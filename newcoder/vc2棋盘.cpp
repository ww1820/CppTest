# include <bits/stdc++.h>

using namespace std;
/*
3 3
1 2 3
4 5 6
7 8 9
1 1 1
1 1 1
1 1 1
3
1 2
2 2
3 3
*/
const int MOD = 100007;
const int direction[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int n, m, q;
int dfs(vector<vector<int>> &A, vector<vector<int>> &B, vector<vector<int>> &record, int x, int y){
    if(x < 0 || x >= n || y < 0 || y >= m){
        return 0;
    }
    if(record[x][y]){
        return record[x][y];
    }
    record[x][y] = 1;

    int cnt = 0;
    for(int i = 0; i < 4; ++i) {
        int pre_x = x + direction[i][0];
        int pre_y = y + direction[i][1];
        if(pre_x >= 0 && pre_x < n && pre_y >= 0 && pre_y < m && A[pre_x][pre_y] + B[pre_x][pre_y] <= A[x][y]) {
            record[x][y] += dfs(A, B, record, pre_x, pre_y); // 前一步能到达该点的路径数
        }
    }
    record[x][y] % MOD;
    return record[x][y];
}

int main() {

    freopen("/data/workspace/cpp_test/test.txt", "r", stdin);
    cin >> n >> m;
    vector<vector<int>> A(n, vector<int>(m));
    vector<vector<int>> B(n, vector<int>(m));
    
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            cin >> A[i][j];
        }
    }
    
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            cin >> B[i][j];
        }
    }
    
    cin >> q;
    
    vector<vector<int>> record(n, vector<int>(m, 0)); // record[i][j] 存储能到达该点的点的路径数
    while(q--) {
        // code
        int x, y;
        cin >> x >> y;
        --x;
        --y;
        cout << dfs(A, B, record, x, y) << endl;
        
    }
}