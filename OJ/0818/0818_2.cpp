#include<bits/stdc++.h>

using namespace std;

int monotoneIncreasingDigits(int n) {
    string strN = to_string(n);
    int i = 1;
    while (i < strN.length() && strN[i - 1] >= strN[i]) {
        i += 1;
    }
    if (i < strN.length()) {
        while (i > 0 && strN[i - 1] < strN[i]) {
            strN[i - 1] += 1;
            i -= 1;
        }
        for (i += 1; i < strN.length(); ++i) {
            strN[i] = '0';
        }
    }
    return stoi(strN);
}

int main() {
    int n;
    while (cin >> n)
    {
        cout << monotoneIncreasingDigits(n) << endl;
    }

    return 0;
}