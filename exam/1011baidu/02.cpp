# include<bits/stdc++.h>

using namespace std;

int main() {

    freopen("../test.in", "r", stdin);

    int t;

    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        vector<int> vec(n);

        for (int i = 0; i < n; ++i) {
            cin >> vec[i];
        }

        sort(vec.begin(), vec.end());

        int l = 0, r = l + k - 1;
        bool flag = false;
        while (l <= r && r < n)
        {
            // 扩展窗口
            if(r + 1 < n && vec[r] == vec[r+1])
                ++r;
            
            if(r - l == k - 1) {
                flag = true;
                // cout << vec[l] << " " << vec[r] << endl;
                break;
            }
            // 缩小窗口
            if(l + 1 < n && vec[l] == vec[l+1])
                ++l;
            
            ++l;
            r = l + k - 1;
        }
        if(flag) {
            cout << vec[l] << " " << vec[r] << endl;
        } else {
            cout << -1 << endl;
        }
    }
}