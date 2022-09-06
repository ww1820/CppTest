#include <bits/stdc++.h>

using namespace std;

static void func(int *arg) {
    static int i = 2;
    switch (*arg)
    {
    case 1:
        *arg += ++i;
    case 2:
        *arg += i << 1;
    default:
        *arg -= 011;
    }
}

int main()
{
    int cnt = (2, 1);
    func(&cnt);
    func(&cnt);
    cout << 011 << endl;
    cout << cnt;
}