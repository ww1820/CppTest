# include <bits/stdc++.h>

using namespace std;
/*
5 2
5 3
1 4 5 2 3
1 6 10 3 4

3 2
6 13
2 11 5
3 25 14
*/
int M, N;

vector<int> pipe;
vector<int> package;
vector<int> times;

int res = INT_MAX;

void dfs(int idx, vector<int> &alltime, int maxn)
{
    if(idx == package.size()) {
        // res = min(res, *max_element(alltime.begin(), alltime.end()));
        res = min(res, maxn);
        return;
    }

    // if(*max_element(alltime.begin(), alltime.end()) > res) {
    if(maxn > res) {
        return;
    }

    for (int i = 0; i < N; ++i) {
        if(package[idx] <= pipe[i]) {
            alltime[i] += times[idx];
            int tmp = maxn;
            maxn = max(maxn, alltime[i]);
            dfs(idx + 1, alltime, maxn);
            maxn = tmp;
            alltime[i] -= times[idx];
        }
    }
}

int main() {
    // freopen("../test.in", "r", stdin);
    
    cin >> M >> N;
    pipe.resize(N);
    package.resize(M);
    times.resize(M);

    for (int i = 0; i < N; ++i) 
    {
        cin >> pipe[i];
    }

    // sort(pipe.begin(), pipe.end(), greater<int>());
    vector<pair<int, int>> tmp(M);
    for (int i = 0; i < M; ++i)
    {
        cin >> tmp[i].first;
        // cin >> package[i];
    }
    // sort(package.begin(), package.end(), greater<int>());
    
    for (int i = 0; i < M; ++i)
    {
        cin >> tmp[i].second;
        // cin >> times[i];

    }
    sort(tmp.begin(), tmp.end(), [](pair<int, int> &a, pair<int, int> &b)
         { return a.second > b.second; });

    for (int i = 0; i < M; ++i)
    {
        package[i] = tmp[i].first;
        times[i] = tmp[i].second;
    }
    vector<int> alltime(N, 0);
    int maxn = INT_MIN;
    dfs(0, alltime, maxn);
    printf("%d\n", res);
}