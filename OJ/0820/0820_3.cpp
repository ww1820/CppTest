#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> direction{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int res = INT_MIN;
int flag = false;

// void print2DVec(vector<vector<int>>& matrix){
// 	for (auto & row : matrix) {
// 		for (auto elem : row) {
// 			printf("%d\t", elem);
// 		}
// 		printf("\n");
// 	}
// 	printf("\n");

// }

void dfs(vector<vector<int>> & cave, int hp, int m, int n, int x, int y) {
	if(x < 0 || x >= m || y < 0 || y >= n || cave[x][y] == -1 || cave[x][y] == -4) {
		return;
	}

	if(cave[x][y] > 0){
		hp -= cave[x][y];
	}
	
	if(cave[x][y] == -3) {
		// print2DVec(cave);
		res = max(res, hp);
		flag = true;
		return;
	}

	int tmp = cave[x][y];
	cave[x][y] = -4;

	for (int i = 0; i < 4; ++i) {
		int next_x = x + direction[i][0];
		int next_y = y + direction[i][1];
		
		dfs(cave, hp, m, n, next_x, next_y);
	}

	cave[x][y] = tmp;
}

int func(vector<vector<int>> & cave, int hp){
	int m = cave.size();
	int n = cave[0].size();
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if(cave[i][j] == -2){
				dfs(cave, hp, m, n, i, j);
			}
		}
	}
	return res;
}

int main() {
	vector<vector<int>> cave{{-2, 0, 0, -1, -3}};
	int hp = 2;

	// vector<vector<int>> cave{
	// 	{0, 2, -3, 0, 0},
	// 	{0, -1, -1, 3, 0},
	// 	{-2, 0, 0, 1, 0}};

	// int hp = 2;

	hp = func(cave, hp);
	if (flag == true)
	{
		cout << hp << endl;
	} else {
		cout << -1 << endl;
	}
	return 0;
}