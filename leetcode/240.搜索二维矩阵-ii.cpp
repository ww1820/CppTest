
/*
 * @lc app=leetcode.cn id=240 lang=cpp
 *
 * [240] 搜索二维矩阵 II
 */

// @lc code=start

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        return binarySearch(matrix, target, 0, 0, matrix.size() - 1, matrix[0].size() - 1);
    }

private:
    bool binarySearch(vector<vector<int>>& matrix, int target, int startx, int starty, int endx, int endy) {
        if(startx > endx || starty > endy)
            return false;
        print2DVec(matrix, startx, starty, endx, endy);
        int midx = startx + ((endx - startx) >> 1);
        int midy = starty + ((endy - starty) >> 1);
        if(matrix[midx][midy] == target)
            return true;

        if(matrix[midx][midy] < target) {
            return binarySearch(matrix, target, midx + 1, starty, endx, endy) || binarySearch(matrix, target, startx, midy+ 1, midx, endy); // 注意此时的搜索范围不只是mid的右下角
        } else {
            return  binarySearch(matrix, target, startx, starty, midx - 1, endy) || binarySearch(matrix, target, midx, starty, endx, midy-1);
        }
        
    }

    void print2DVec(vector<vector<int>>& matrix, int startx, int starty, int endx, int endy){
        for (int i = startx; i <= endx; ++i) {
            for (int j = starty; j <= endy; ++j) {
                printf("%d\t", matrix[i][j]);
            }
            printf("\n");
        }
        printf("\n");

    }
};
// @lc code=end


