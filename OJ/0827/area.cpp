#include<bits/stdc++.h>

using namespace std;

bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
    if (rec1[0] == rec1[2] || rec1[1] == rec1[3] || rec2[0] == rec2[2] || rec2[1] == rec2[3]) {
        return false;
    }
    return !(rec1[2] <= rec2[0] ||   // left
                rec1[3] <= rec2[1] ||   // bottom
                rec1[0] >= rec2[2] ||   // right
                rec1[1] >= rec2[3]);    // top
}

int computeArea(vector<int>& rec1, vector<int>& rec2) {
    int ax1 = rec1[0];
    int ay1 = rec1[1];
    int ax2 = rec1[2];
    int ay2 = rec1[3];
    int bx1 = rec2[0];
    int by1 = rec2[1];
    int bx2 = rec2[2];
    int by2 = rec2[3];
    int area1 = (ax2 - ax1) * (ay2 - ay1), area2 = (bx2 - bx1) * (by2 - by1);
    int overlapWidth = min(ax2, bx2) - max(ax1, bx1), overlapHeight = min(ay2, by2) - max(ay1, by1);
    int overlapArea = max(overlapWidth, 0) * max(overlapHeight, 0);
    return area1 + area2 - overlapArea;
}

int main() {
    // int N = 4;
    // vector<vector<int>> points = {
    //     {0, 0, 2, 2},
    //     {1, 1, 4, 3},
    //     {2, 4, 4, 7},
    //     {2, 5, 3, 6}};
    
    int N = 3;
    vector<vector<int>> points = {
        {0,0,1,1},
        {1,1,2,2},
        {1,0,2,1}};
    vector<int> flag(N, 0);

    int Area = 0;
    for (int i = 0; i < N; ++i) {
        if(flag[i]) continue;
        for (int j = i + 1; j < N; ++j) {
            if(!flag[j] && isRectangleOverlap(points[i],points[j])) {
                flag[j] = 1;
                int tmp = computeArea(points[i], points[j]);
                Area += tmp;
                break;
            }
        }
    }
    printf("%d", Area);
    return 0;
}
