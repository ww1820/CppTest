#include<bits/stdc++.h>

using namespace std;

int main() {
    int a = 0;
    int b = 1;
    int c = 2;
    int d = 3;
    int e = 4;
    map<int, int *> M;
    
    M.emplace(0, &a);
    M.emplace(1, &b);
    M.emplace(2, &c);
    M.emplace(3, &d);
    M.emplace(4, &e);

    for(auto each : M) {
        if((each.first & 1) == 0 || ((*each.second & 1) == 0)) {
            M.erase(each.first);
        }
    }
    
    return 0;
}