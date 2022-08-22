#include<bits/stdc++.h>

using namespace std;

#pragma pack(4)
struct MSG
{
    /* data */
    unsigned short S;
    unsigned short T;
    char f;
    int d;
};

#pragma pack(0)


int main() {
    MSG msg;
    const MSG &rMSG = msg;
    const_cast<MSG*>(&rMSG);
    // reinterpret_cast<MSG*>(&rMSG);
    // static_cast<MSG*>(&rMSG);

    // (MSG*)(&rMSG);
    // rMSG.d = 1;
    msg.d = 1;


    // cout << strlen("aaa");

    return 0;
}