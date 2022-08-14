#include<bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    int x;
    if (n > 2 * k){
        x = k;
    }
    else // x = 0
    {
        x = 0;
       
    }

    for (int i = 1; i <= n - x - k - 1; ++i) {
        cout << i << " ";
    }

    for (int i = 0; i <= k - x ; ++i){
        cout << n - 2 * x - i << " ";
    }

    for (int i = 0; i < x; ++i) {
        cout << n - x + 1 + i << " " << n - 2 * x + 1 + i << " ";
    }
}