/*
样例1：
4 4
1 1 1 1
1 6 2 1
1 1 0 1
1 3 1 1

8 4
1 6 2 1
1 1 0 1
1 1 0 1
1 1 0 1
1 1 0 1
1 1 0 1
1 1 0 1
1 1 3 1
*/

#include<bits/stdc++.h>
#include "/data/workspace/cpp_test/tool.h"
using namespace std;

vector<vector<int>> direction{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int res = INT_MAX;

/*
0 路 1 墙 2 起点 3 终点 4 陷阱 6 炸弹 5 已访问
*/
void dfs(vector<vector<int>> & maze, int time, int m, int n, int x, int y) {
	if(x < 0 || x >= m || y < 0 || y >= n || maze[x][y] == 1 || maze[x][y] == 5) {
		return;
	}

    ++time;  // 走一步
    int tmp = maze[x][y];

    if(tmp == 3) {
        print2DVec(maze);
		res = min(res, time);
		return;
	}
	maze[x][y] = 5;
    int tmpArray[4];

    if(tmp == 4) { // 陷阱
        time += 2;
    } else if(tmp == 6) { // 炸弹
        for (int i = 0; i < 4; ++i) {
            int tmp_x = x + direction[i][0];
            int tmp_y = y + direction[i][1];
            if(tmp_x >= 0 && tmp_x < m && tmp_y >= 0 && tmp_y < n) {
                tmpArray[i] = maze[tmp_x][tmp_y];
                if(tmpArray[i] == 1) {
                    maze[tmp_x][tmp_y] = 0;
                }
            }
        }
    }

    for (int i = 0; i < 4; ++i) {
		int next_x = x + direction[i][0];
		int next_y = y + direction[i][1];
		
		dfs(maze, time, m, n, next_x, next_y);
	}

	maze[x][y] = tmp;
    // 如果是炸弹 还原
    if(tmp == 6) {
        for (int i = 0; i < 4; ++i) {
            int tmp_x = x + direction[i][0];
            int tmp_y = y + direction[i][1];
            if(tmp_x >= 0 && tmp_x < m && tmp_y >= 0 && tmp_y < n) {
                maze[tmp_x][tmp_y] = tmpArray[i];
            }
        }
    }
}

int func(vector<vector<int>> & maze, int time){
	int m = maze.size();
	int n = maze[0].size();
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if(maze[i][j] == 2){
				dfs(maze, time, m, n, i, j);
			}
		}
	}
	return res;
}

int main() {
    int n, m;
    infile >> n >> m;
    vector<vector<int>> maze(n, vector<int>(m));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            infile >> maze[i][j];
        }
    }
    int time = -1;
    time = func(maze, time);
    cout << time;
    return 0;
}