#include<bits/stdc++.h>
#include "/data/workspace/cpp_test/tool.h"
using namespace std;

/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 *	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param preOrder int整型vector 
     * @param inOrder int整型vector 
     * @return TreeNode类vector
     */
    unordered_map<int, vector<int>> dict;
    vector<TreeNode*> recur(vector<int>& preOrder, vector<int>& inOrder, int root, int left, int right) {
        if(left > right) {
            return {nullptr};
        }
        int rootVal = preOrder[root];
        vector<int> rootIdxes = dict[rootVal]; // 所有可能的划分
        vector<TreeNode*> res;
        for(int i = 0; i < rootIdxes.size(); ++i) {
            int idx = rootIdxes[i]; // 中序遍历下标
            if(idx < left || idx > right) {
                continue;
            }
            /*
            左子树长度：idx - left, 右子树长度: right - idx
            */
            vector<TreeNode*> leftNode(recur(preOrder, inOrder, root + 1, left , idx - 1));
            vector<TreeNode*> rightNode(recur(preOrder, inOrder, root + idx - left + 1, idx + 1 , right));
            for(int l = 0; l < leftNode.size(); ++l) {
                for(int r = 0; r < rightNode.size(); ++r) {
                    res.emplace_back(new TreeNode(rootVal));
                    res.back()->left = leftNode[l];
                    res.back()->right = rightNode[r];
                }
            }
        }
        return res;
    }
    
    vector<TreeNode*> getBinaryTrees(vector<int>& preOrder, vector<int>& inOrder) {
        // write code here
        for(int i = 0; i < inOrder.size(); ++i) {
            dict[inOrder[i]].emplace_back(i);
        }
        return recur(preOrder, inOrder, 0 , 0, inOrder.size()-1);
    }
};

int main() {
    vector<int> preOrder = {1, 1, 2};
    vector<int> inOrder = {1, 2, 1};

    Solution solution;
    vector<TreeNode *> res= solution.getBinaryTrees(preOrder, inOrder);

    for(auto tree : res) {
        print_binary_tree(tree);
        printf("\n");
    }
}