#include<bits/stdc++.h>

using namespace std;

int main() {
    freopen("test.in", "r", stdin);
    int n;
    cin >> n;
    vector<int> height(n);

    for (int i = 0; i < n; ++i) {
        cin >> height[i];
    }

    stack<int> stk; // 单调栈，递减栈，表示可达到该点的山的个数
    vector<int> L(n);
    vector<int> R(n);

    for (int i = 0; i < n; ++i)
    {
        while (!stk.empty() && stk.top() < height[i])
        {
            stk.pop();
        }
        L[i] = stk.size();
        stk.emplace(height[i]);
    }

    stack<int>().swap(stk);
    for (int i = n - 1; i >= 0; --i)
    {
        while (!stk.empty() && stk.top() < height[i])
        {
            stk.pop();
        }
        R[i] = stk.size();
        stk.emplace(height[i]);
    }

    for (int i = 0; i < n; ++i)
    {
        printf("%d ", (n - 1 - L[i] - R[i]));
    }
    return 0;
}