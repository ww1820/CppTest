#include<bits/stdc++.h>

using namespace std;

int main() {
    vector<vector<char>> paper = {
        {'1', 'x', '1'},
        {'x', 'o', 'x'},
        {'1', 'x', '1'}
    };

    int M = 3;
    int N = 5;

    double tmp = (((M / N) - 1) >> 1) + 0.5;
    int n = tmp;

    vector<vector<char>> wall((2 * n + 1) * N,vector<char>((2 * n + 1) * N));

    int x = 0;
    int y = 0;


    printf("\n");
    return 0;
}