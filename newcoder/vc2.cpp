# include <bits/stdc++.h>

using namespace std;

const int MOD = 100007;
const int direction[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int n, m, q;
int dx, dy;
int dfs(vector<vector<int>> &A, vector<vector<int>> &B, vector<vector<int>> &record, int sx, int sy){
    if(sx == dx && sy == dy) {
        record[sx][sy] = 1;
        return 1;
    }
    int cnt = 0;
    for(int i = 0; i < 4; ++i) {
        int next_x = sx + direction[i][0];
        int next_y = sy + direction[i][1];
        
        if(next_x >= 0 && next_x < n && next_y >= 0 && next_y < m && A[next_x][next_y]
          && A[next_x][next_y] >= (A[sx][sy] + B[sx][sy])) {
            int tmp = A[next_x][next_y];
            A[next_x][next_y] = 0;
            if(record[next_x][next_y] != 0){
                cnt += record[next_x][next_y];
            } else {
                cnt += dfs(A, B, record, next_x, next_y);
            }
            A[next_x][next_y] = tmp;
        }
    }
    
    record[sx][sy] = cnt;
    return cnt;
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
    
    
    while(q--) {
        // code
        cin >> dx >> dy;
        vector<vector<int>> record(m, vector<int>(n, 0));
        int res = 0;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                res += dfs(A, B, record, i, j);
                res %= MOD;
            }
        }
        cout << res << endl;
        
    }
}