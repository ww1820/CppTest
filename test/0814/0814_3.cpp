
#include<bits/stdc++.h>

using namespace std;

const int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int W = 20, H = 20;
int nFood = 1;
int nFire = 3;
vector<vector<int>> board(W, vector<int>(H, 1));


int main() {
    vector<vector<int>> Food = {{6, 15, 3}};
    vector<vector<vector<int>>> Fire(101);

    Fire[1].push_back({0, 19}); // 该时刻点燃的草
    Fire[1].push_back({10, 9});

    Fire[5].push_back({4, 13});

    int MaxC = 5; // 最后一块草的点燃时间

    for (int t = 1; t < MaxC; ++t) {
        while (Fire[t].size() != 0)
        {
            /* code */
        }
        
    }
}

// class Solution {
// public:
//     int maximumMinutes(vector<vector<int>> &grid) {
//         int m = grid.size(), n = grid[0].size();
//         auto bfs = [&](vector<pair<int, int>> &q) -> tuple<int, int, int> {
//             int time[m][n]; memset(time, -1, sizeof(time));
//             for (int t = 0; !q.empty(); ++t) {
//                 vector<pair<int, int>> nq;
//                 for (auto &[i, j] : q) {
//                     time[i][j] = t;
//                     for (auto[dx, dy] : dirs) {
//                         int x = i + dx, y = j + dy;
//                         if (0 <= x && x < m && 0 <= y && y < n && grid[x][y] == 0 && time[x][y] < 0)
//                             nq.emplace_back(x, y);
//                     }
//                 }
//                 q = move(nq);
//             }
//             return {time[m - 1][n - 1], time[m - 1][n - 2], time[m - 2][n - 1]};
//         };

//         vector<pair<int, int>> q = {{0, 0}};
//         auto [man_to_house_time, m1, m2] = bfs(q);
//         if (man_to_house_time < 0) return -1; // 人无法到终点

//         vector<pair<int, int>> fires;
//         for (int i = 0; i < m; ++i)
//             for (int j = 0; j < n; ++j)
//                 if (grid[i][j] == 1) fires.emplace_back(i, j);
//         auto [fire_to_house_time, f1, f2] = bfs(fires);
//         if (fire_to_house_time < 0) return 1e9; // 火无法到终点

//         int ans = fire_to_house_time - man_to_house_time;
//         if (ans < 0) return -1; // 火比人先到终点
//         if (m1 < 0 || m2 < 0 || f1 - m1 == ans && f2 - m2 == ans)
//             return ans - 1; // 火只会跟在人的后面，在到达终点前，人和火不能重合
//         return ans;// 人和火可以同时到终点
//     }
// };