#include <bits/stdc++.h>
using namespace std;

char color[3] = {'R', 'G', 'B'};

int main() {
    freopen("test.in", "r", stdin);
    int n, q;
    cin >> n >> q;

    vector<int> vec(n, 0);
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        --l;
        --r;
        vec[l] += 1;
        vec[r + 1] -= 1;
    }

    for (int i = 0; i < n; ++i) {
        if(i > 0) {
            vec[i] += vec[i - 1];
        }

        if(vec[i] == 0) {
            printf("O");
        } else {
            printf("%c", color[(vec[i]-1)%3]);
        }
    }

    return 0;
}