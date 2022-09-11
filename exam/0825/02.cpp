#include<bits/stdc++.h>

using namespace std;

class Cmp {
public:
    bool operator()(const pair<int,int> &a, const pair<int,int> &b) {
        return a.first > b.first;
    }
};


int func(vector<vector<int>>& intervals) {
    if(intervals.size() == 1)
        return 1;
    
    sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int>& b){
        return a[0] < b[0];
    }); // 按照结束时间升序排序

    int res = 0;

    // unordered_map<int, int> mp;
    priority_queue<pair<int,int>, vector<pair<int,int>>, Cmp> pri_que;
    int rooms = 0;
    int used = 0;
    for (int i = 0; i < intervals.size(); ++i)
    {
        int used = 0;
        if (pri_que.empty() || pri_que.top().first > intervals[i][0])
        {
            // 没有正在进行的会议或者最早结束的会议还没结束，即没有空房间
            ++rooms; // 增加房间
            used = 0;
        }
        else
        {
            // 有空房间
            used = pri_que.top().second;
            pri_que.pop();
        }
        used += intervals[i][1] - intervals[i][0];
        res = max(res, used);
        pri_que.emplace(intervals[i][1], used); //将当前会议结束时间插入小顶堆
    }
    return res;
}

int main() {
    // vector<vector<int>> intervals = {{15, 17}, {8, 11}, {10, 16}, {11, 12}, {13, 15}, {9, 12}};
    vector<vector<int>> intervals = {{15, 17}, {8, 11}, {10, 16}, {11, 12}, {13, 15}, {9, 12}};
    cout << func(intervals) << endl;
    return 0;
}