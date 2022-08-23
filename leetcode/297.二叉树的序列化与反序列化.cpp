/*
 * @lc app=leetcode.cn id=297 lang=cpp
 *
 * [297] 二叉树的序列化与反序列化
 */

// @lc code=start
//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


#include <bits/stdc++.h>

using namespace std;

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        dfs(root);
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<TreeNode *> nodes;
        splitStr(data, nodes);


        return nodes[0];
    }

private:
    string str;

    TreeNode * construct(vector<TreeNode *> &nodes, int& idx) {
        int cur = idx;
        if(nodes[cur] != nullptr) {
            nodes[cur]->left = construct(nodes, ++idx);
            nodes[cur]->right = construct(nodes, ++idx);
        }
        return nodes[cur];
    }

    void dfs(TreeNode* root) {
        if(root == nullptr) {
            str += "nil,";
        }
        else
        {
            str += to_string(root->val) + ",";
            dfs(root->left);
            dfs(root->right);
        }
    }
    void splitStr(string &data, vector<TreeNode *> &nodes)
    {
        int l = 0;
        int r = 0;
        while(l <= r && r < data.length()) {
            if(data[r] != ',') {
                ++r;
            }
            else {
                string s = data.substr(l, r - l);
                TreeNode *node = s == "nil" ? nullptr : new TreeNode(stoi(s));
                nodes.emplace_back(node);
                ++r;
                l = r;
            }
        }
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end

