# include<bits/stdc++.h>

using namespace std;
/*
a < b < c
b <= 2a
c <= 2b

3
2 7 2
1 5 3
4 6 3
*/

ifstream infile("/data/workspace/cpp_test/test.txt", ios::in);


vector<vector<int>> vec(3);
int res = 0;

void traceback(vector<int> &selected, int n, int depth){
    if(selected.size() == n) {
        ++res;
        return;
    } else if(depth == 3){
        return;
    }
    for(int i = 0; i < n; ++i) {
        if(selected.size() == 0 || (selected.back() < vec[depth][i] && 2 * selected.back() >= vec[depth][i])) {
            selected.push_back(vec[depth][i]);
            traceback(selected, n, depth + 1);
            selected.pop_back();
        } 
        else if(selected.size() != 0 && 2 * selected.back() < vec[depth][i]) {
            break; // 剪枝
        }
    }
}

int main() {
    int n;
    infile >> n;
    vec[0].resize(n);
    vec[1].resize(n);
    vec[2].resize(n);
    
    for(int i = 0; i < n; ++i) {
        infile >> vec[0][i];
    }
    for (int i = 0; i < n; ++i)
    {
        infile >> vec[1][i];
    }
    
    for(int i = 0; i < n; ++i) {
        infile >> vec[2][i];
    }

    sort(vec[0].begin(), vec[0].end());
    sort(vec[1].begin(), vec[1].end());
    sort(vec[2].begin(), vec[2].end());

    vector<int> selected;
    traceback(selected, n, 0);
    
    cout << res;
}