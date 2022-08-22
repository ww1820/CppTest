#include<bits/stdc++.h>

using namespace std;


int main() {

    char str1[] = "abc";
    char str2[] = "abc";
    const char str3[] = "abc";
    const char str4[] = "abc";
    const char *str5 = "abc";
    const char *str6 = "abc";

    cout << (str1 == str2) << endl;
    cout << (str3 == str4) << endl;
    cout << (str5 == str6) << endl;
    cout << 't' - 'a' << endl;

    return 0;
}
