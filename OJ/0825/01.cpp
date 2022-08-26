#include<bits/stdc++.h>
#include <sys/types.h>
#include <unistd.h>

using namespace std;

void func1() {
    fork() || fork();
    printf("hello\n");
    sleep(1);
    exit(0);
}

void func2() {
    for (int x = 0; x < 3; ++x) {
        fork();
        printf("hello\n");
    }
    sleep(1);
    exit(0);
}

int main() {
    // func1();
    printf("\n");
    func2();
    return 0;
}