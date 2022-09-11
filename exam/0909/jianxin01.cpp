#include<bits/stdc++.h>

using namespace std;

fstream infile("/data/workspace/cpp_test/test.txt", ios::in);
// visited判断
int bfs(vector<uint8_t>& roads, int row, int col) {
    queue<pair<int, int>> que;
    que.push({row, col});

    int n = roads.size();
    int m = 8;

    vector<vector<int>> direct = {{1, 0}, {0, 1}, {0, -1}};

    int max_row = 0;
    while (!que.empty())
    {
        pair<int, int> curr = que.front();
        que.pop();
        for (int i = 0; i < direct.size(); ++i) {
            int next_i = curr.first + direct[i][0];
            int next_j = curr.second + direct[i][1];
            if(next_i < 0 || next_i >= n || next_j < 0 || next_j >= m) {
                continue;
            }
            int value = ((roads[next_i] >> (8 - next_j - 1)) & 1);
            if(value == 0) {
                que.push({next_i, next_j});
                max_row = max(max_row, next_i);
            }
        }
    }
    return max_row;
}

int GetFarthestRoad(vector<uint8_t>& vecRoad) {
    int max_row = -1;
    for (int j = 0; j < 8; ++j) {
        int value = ((vecRoad[0] >> (8 - j - 1)) & 1);
        if(value == 0) {
            max_row = max(max_row, bfs(vecRoad, 0, j));
        }
    }
    return max_row+1;
}

int main() {
    vector<uint8_t> vecRoad;
    int tmp;
    while (infile >> tmp)
    {
        vecRoad.push_back((uint8_t)tmp);
    }

    cout << GetFarthestRoad(vecRoad);

    return 0;
}