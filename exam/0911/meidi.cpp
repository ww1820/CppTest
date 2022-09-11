#include<bits/stdc++.h>

using namespace std;

int main() {
    int y = 3, x = 3, z = 1;
    printf("%d, %d\n", (++x, y++), z + 2);
    return 0;
}