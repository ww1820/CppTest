#include<bits/stdc++.h>

using namespace std;
vector<vector<int>> graph;
unordered_map<int,char> alpha;
vector<int> ans;
unordered_set<char> dfs(int v, unordered_set<char> st) {
    
    for (int i = 0; i < graph[v].size(); ++i)
    {
        unordered_set<char> newst;
        newst = dfs(graph[v][i],newst);
        st.insert(newst.begin(), newst.end());
    }
    st.insert(alpha[v]);
    ans[v] = st.size();
    return st;
}

int main() {
    int n;
    cin >> n;

    graph.resize(n);
    ans.resize(n);
    for (int i = 1; i < n; ++i)
    {
        int parent;
        cin >> parent;
        graph[parent - 1].emplace_back(i);
    }

    string s;
    cin >> s;
    for(int i = 0; i < n; ++i) {
        alpha.emplace(i,s[i]);
    }
    unordered_set<char> st;
    dfs(0, st);
    for (int i = 0; i < n; ++i)
    {
        cout << ans[i] << " ";
    }

    return 0;
}