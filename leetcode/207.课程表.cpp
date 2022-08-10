// @before-stub-for-debug-begin
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] 课程表
 */

// @lc code=start
#include<bits/stdc++.h>

#define UNSEARCH  0
#define SEARCHING 1
#define SEARCHED  2

using namespace std;


class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        edges.resize(numCourses);
        nodes.resize(numCourses);

        for(const auto& elem : prerequisites) {
            edges[elem[1]].emplace_back(elem[0]); // elem[0] 是 elem[1] 的前驱节点
        }

        for (int i = 0; i < numCourses; ++i) {
            if(nodes[i] == UNSEARCH && !dfs(i)) {
                return false;
            }
        }
        return true;
    }

private:
    vector<vector<int>> edges;
    vector<int> nodes;
    // bool res = true;

    bool dfs(int u) {
        nodes[u] = SEARCHING;
        for(int v : edges[u]) { // 遍历 u 的所有邻居
            if(nodes[v] == SEARCHING) {
                return false; // 找到一个环
            } else if(nodes[v] == UNSEARCH){
                if(!dfs(v))
                    return false;
            }
        }
        nodes[u] = SEARCHED; // 节点 u 搜索完成
        return true;
    }
};
// @lc code=end

