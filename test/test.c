#include<stdio.h>

void func(char a){};
void func(long a){};


int main() {
    int a = 100;
    func(a);
    return 0;
}