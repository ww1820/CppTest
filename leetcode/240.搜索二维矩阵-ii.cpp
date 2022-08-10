// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem240.h"

// using namespace std;
// @before-stub-for-debug-end


/*
 * @lc app=leetcode.cn id=240 lang=cpp
 *
 * [240] 搜索二维矩阵 II
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        print2DVec(matrix);
        return binarySearch(matrix, target, 0, 0, matrix.size() - 1, matrix[0].size() - 1);
    }

private:
    bool binarySearch(vector<vector<int>>& matrix, int target, int startx, int starty, int endx, int endy) {
        if(startx > endx || starty > endy)
            return false;
        int midx = startx + (endx - startx) / 2;
        int midy = starty + (endy - starty) / 2;
        if(matrix[midx][midy] == target)
            return true;

        if(matrix[midx][midy] < target) {
            return binarySearch(matrix, target, midx + 1, midy, endx, endy) || binarySearch(matrix, target, midx, midy+ 1, midx, endy);
        } else {
            return binarySearch(matrix, target, startx, starty, midx - 1, endy) || binarySearch(matrix, target, midx, starty, endx, midy-1);
        }
    }

    void print2DVec(vector<vector<int>>& matrix){
        for(auto & row : matrix) {
            for(auto elem : row) {
                printf("%d\t", elem);
            }
            printf("\n");
        }
    }
};
// @lc code=end

