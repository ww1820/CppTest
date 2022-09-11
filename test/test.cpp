#include<bits/stdc++.h>

using namespace std;

int main() {
    int x = 1;
    int y = 2;
    printf("x = %d, y = %d\n", x, y);
    // x = x ^ y;
    // y = x ^ y;
    // x = x ^ y;
    x ^= y ^= x ^= y;
    printf("x = %d, y = %d\n", x, y);
    return 0;
}