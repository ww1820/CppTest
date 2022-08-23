#include<bits/stdc++.h>

using namespace std;


// int f(int n, int m) {
//         if (n == 1) {
//             return 0;
//         }
//         int x = f(n - 1, m);
//         cout << x << endl;
//         int idx = (m + x) % n;
//         return idx;
// }

// int main() {
//     int n;

//     cout << f(4, 3) << endl;
// }

#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n, num;
    cin >> n;
    vector<int> nums(n);
    vector<int> ans(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    int index = 0;
    for (int i = 0; i < n; i++) {
        int j = 0; if (i == 0)   j++;
        for (; j < 3; j++) {
            index = (index + 1) % n;
            while (ans[index] > 0)
                index = (index + 1) % n;
        }
        //cout << "index = " << index << " " << nums[i] << endl;
        ans[index] = nums[i];
    }
    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";
    cout << endl;
}

/*
4
1 2 3 4

4 2 1 3

5
1 2 3 4 5

2 4 1 5 3
*/