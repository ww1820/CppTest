#include<bits/stdc++.h>

using namespace std;

int main() {

    int a = 0x1234;
    char c = (char)(a);
    if(c == 0x12)
        printf("big endian\n");
    else if(c == 0x34)
        printf("little endian\n");
    return 0;
}