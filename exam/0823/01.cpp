#include <bits/stdc++.h>

using namespace std;

void func(char str[128]) {
    char cha[] = "https";
    char *p = cha;
    cout << sizeof(cha) << " " << sizeof(str) << " " << sizeof(p) << endl;
}

int main() {
    char a[128];
    func(a);
    return 0;
}
