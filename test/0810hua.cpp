#include<bits/stdc++.h>

using namespace std;

int weight_sum = 0;

void traverse(unordered_map<int, vector<int>>& tree, string& color_str, vector<bool>& used, int root_index, int red_count, int blue_count) {
    int curr_red = color_str[root_index] == 'R' ? 1 : 0;
    int curr_blue = color_str[root_index] == 'B' ? 1 : 0;
    weight_sum += abs((red_count + curr_red) - (blue_count - curr_blue));

    if (tree[root_index].size() == 0) {
        return;
    }
    else if (tree[root_index].size() == 1) {
        int lchild_index = tree[root_index][0];
        if (!used[lchild_index]) {
            traverse(tree, color_str, used, lchild_index, red_count + curr_red, blue_count + curr_blue);
            used[lchild_index] = true;
        }
        
    }
    else {
        int lchild_index = tree[root_index][0];
        int rchild_index = tree[root_index][1];
        if (!used[lchild_index]) {
            traverse(tree, color_str, used, lchild_index, red_count + curr_red, blue_count + curr_blue);
            used[lchild_index] = true;
        }
        if (!used[rchild_index]) {
            traverse(tree, color_str, used, rchild_index, red_count + curr_red, blue_count + curr_blue);
            used[rchild_index] = true;
        }
    }   
}

int main() {
    int n;
    int u, v;
    string color_str;
    cin >> n;
    cin >> color_str;
    color_str = "0" + color_str;
    unordered_map<int, vector<int>> tree;
    vector<bool> used(n+1, false);
    for (int i = 0; i < n-1; i++) {
        cin >> u >> v;
        if (tree.count(u) == 0) {
            tree[u] = { v };
            if (tree.count(v) == 0) {
                tree[v] = { u };
            }
            else {
                tree[v].push_back(u);
            }
        }
        else {
            tree[u].push_back(v);
        }
    }
    traverse(tree, color_str, used, 1, 0, 0);
    cout << weight_sum << endl;
    return 0;
}