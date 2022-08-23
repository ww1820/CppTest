#include<bits/stdc++.h>

using namespace std;

int main() {
    int n, m, k;
    string cmd;

    cin >> n >> m >> k >> cmd;
    int cleaned = 0;
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    int x = 0;
    int y = 0;
    int i = 0;
    while (i < cmd.length())
    {
        visited[x][y] = true;
        ++ cleaned;
        if (cmd[i] == 'W') {
            --y;
        }
    }
    
}