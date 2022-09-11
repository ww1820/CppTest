#include<bits/stdc++.h>
#include "/data/workspace/cpp_test/tool.h"

using namespace std;

/*
3
1 2 3
1 2
1 3
*/

int main() {
    int n, m, k;
    infile >> n >> m >> k;

    int graph[n][n];

    int path[2][m];

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < m; ++j) {
            infile >> path[i][j];
        }
    }

    for (int i = 0; i < m; ++i) {
        int cost;
        infile >> cost;
        graph[path[0][i]][path[1][i]] = cost;
        graph[path[1][i]][path[0][i]] = cost;
    }

    

    return 0;
}