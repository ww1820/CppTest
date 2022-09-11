#include<bits/stdc++.h>

using namespace std;

int main() {
    vector<string> vec;

    string str;

    ifstream infile("/data/workspace/cpp_test/test.txt", ios::in); 

    while (infile >> str)
    {
        vec.emplace_back(str);
    }

    int n = stoi(vec.back());

    vec.pop_back();

    vector<string> res;

    return 0;
}