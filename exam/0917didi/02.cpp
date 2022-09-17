# include <bits/stdc++.h>

using namespace std;

/*
?12?0?9??
212101902
*/

vector<int> idx;
bool dfs(string &str, int index, int sum)
{
    
    if (index == idx.size())
    {
        if (sum % 3 == 0) {
            return true;
        } else {
            return false;
        }
    }
    int i = idx[index];

    for (int k = 0; k <= 9; ++k) {
        if(i == 0 && k == 0) continue;
        if(i - 1 >= 0 && str[i-1] - '0' == k) continue;
        if(i + 1 < str.length() && str[i+1] - '0' == k) continue;
        str[i] = '0' + k;
        if(dfs(str, index + 1, sum + k)) {
            return true;
        }
        str[i] = '?';
    }

    return false;
}

int main() {
    // freopen("../test.in", "r", stdin);
    // code
    string str;
    cin >> str;
    int n = str.length();
    int sum = 0;
    for (int i = 0; i < n; ++i)
    {
        if(str[i] == '?') {
            idx.emplace_back(i);
        } else {
            sum += str[i] - '0';
        }
    }

    dfs(str, 0, sum);
    cout << str << endl;

    return 0;
}