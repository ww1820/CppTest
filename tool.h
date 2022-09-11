# pragma once
# include <vector>
# include <iostream>
# include <fstream>

using namespace std;

void print2DVec(vector<vector<int>>& matrix){
	for (auto & row : matrix) {
		for (auto elem : row) {
			printf("%d\t", elem);
		}
		printf("\n");
	}
	printf("\n");
}

void printVec(vector<int>& row){
	for (auto elem : row) {
		printf("%d\t", elem);
	}
	printf("\n");
}

// 使用字符分割
void Stringsplit(const string& str, const char split, vector<string>& res)
{
	if (str == "")		return;
	//在字符串末尾也加入分隔符，方便截取最后一段
	string strs = str + split;
	size_t pos = strs.find(split);

	// 若找不到内容则字符串搜索函数返回 npos
	while (pos != strs.npos)
	{
		string temp = strs.substr(0, pos);
		res.push_back(temp);
		//去掉已分割的字符串,在剩下的字符串中进行分割
		strs = strs.substr(pos + 1, strs.size());
		pos = strs.find(split);
	}
}

// 使用字符串分割
void Stringsplit(const string& str, const string& splits, vector<string>& res)
{
	if (str == "")		return;
	//在字符串末尾也加入分隔符，方便截取最后一段
	string strs = str + splits;
	size_t pos = strs.find(splits);
	int step = splits.size();

	// 若找不到内容则字符串搜索函数返回 npos
	while (pos != strs.npos)
	{
		string temp = strs.substr(0, pos);
		res.push_back(temp);
		//去掉已分割的字符串,在剩下的字符串中进行分割
		strs = strs.substr(pos + step, strs.size());
		pos = strs.find(splits);
	}
}

// 打印内存
void memory_dump(void *ptr, int len) {
    int i;

    for (i = 0; i < len; i++) {
        if (i % 8 == 0 && i != 0)
            printf(" ");
        if (i % 16 == 0 && i != 0)
            printf("\n");
        printf("%02x ", *((uint8_t *)ptr + i));
    }
    printf("\n");
}

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 根据数组构造二叉树
TreeNode* construct_binary_tree(const vector<int>& vec) {
    vector<TreeNode*> vecTree (vec.size(), NULL);
    TreeNode* root = NULL;
    for (int i = 0; i < vec.size(); i++) {
        TreeNode* node = NULL;
        if (vec[i] != -1) node = new TreeNode(vec[i]);
        vecTree[i] = node;
        if (i == 0) root = node;
    }
    for (int i = 0; i * 2 + 1 < vec.size(); i++) {
        if (vecTree[i] != NULL) {
            vecTree[i]->left = vecTree[i * 2 + 1];
            if(i * 2 + 2 < vec.size())
            vecTree[i]->right = vecTree[i * 2 + 2];
        }
    }
    return root;
}

// 层序打印打印二叉树
void print_binary_tree(TreeNode* root) {
    queue<TreeNode*> que;
    if (root != NULL) que.push(root);
    vector<vector<int>> result;
    while (!que.empty()) {
        int size = que.size();
        vector<int> vec;
        for (int i = 0; i < size; i++) {
            TreeNode* node = que.front();
            que.pop();
            if (node != NULL) {
                vec.push_back(node->val);
                que.push(node->left);
                que.push(node->right);
            }
            // 这里的处理逻辑是为了把null节点打印出来，用-1 表示null
            else vec.push_back(-1);
        }
        result.push_back(vec);
    }
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}

