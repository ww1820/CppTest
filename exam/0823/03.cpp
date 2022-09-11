#include <bits/stdc++.h>

using namespace std;

int func1(string &content);
int func2(string &content);
int func3(string &content);
int func4(string &content);
int func5(string &content);

int main() {
    string str;

    // cin >> str;
    // str = "1:redis_01";
    // str = "2:huaweiuser1000000";
    // str = "3:redis_03,redis_04;huaweiuser223244432";
    // str = "4:add_redis_07";
    str = "5:add_redis_04;huaweiuser223244432";

    char cmd = str[0];
    str = str.substr(2);
    switch (cmd)
    {
        case '1':
            cout << func1(str) << endl;
            break;
        case '2':
            cout << func2(str) << endl;
            break;
        case '3':
            cout << func3(str) << endl;
            break;
        case '4':
            cout << func4(str) << endl;
            break;
        case '5':
            cout << func5(str) << endl;
            break;

        default:
            break;
    }


    return 0;
}



int func1(string &content) {
    string num = content.substr(content.length() - 2);
    return (stoi(num) - 1) * 50;
}

int func2(string &content) {
    int num = 0;
    for (char c : content) {
        num += c;
    }
    return num % 999;
}

int func3(string &content) {
    vector<int> state(20, 1);
    auto idx = content.find(';');
    string token = content.substr(idx+1); // token
    string broken = content.substr(0, idx);
    broken += ",";
    int i = 0;

    while (i != broken.length()){
        idx = broken.find(',', i);
        int n = stoi(broken.substr(idx - 2, 2));
        state[n - 1] = 0;
        i = idx + 1;
    }// 宕机的服务器

    int server = func2(token) / 50 + 1;

    while (state[server] == 0) { // 循环查找
        server = (server + 1) % 20;
    }

    return server + 1;
}
int func4(string &content) {
    string num = content.substr(content.length() - 2);
    int n = stoi(num);
    return (n - 1) * 50 + 25 + 500 * ((n - 1 ) & 1);
}

int func5(string &content) {
    vector<int> state(40, 0);

    for (int i = 0; i < state.size(); i = i + 2) {
        state[i] = 1;
    }

    auto idx = content.find(';');
    string token = content.substr(idx+1); // token
    string add = content.substr(0, idx);
    add += ",";
    int i = 0;

    while (i != add.length()){
        idx = add.find(',', i);
        string add_redies = add.substr(i, idx - i);
        int n = func4(add_redies);
        n = n / 25;
        state[n - 1] = 1;
        i = idx + 1;
    }// 添加的服务器

    int server = func2(token) / 25 + 1;

    while (state[server] == 0) { // 循环查找
        server = (server + 1) % 40;
    }

    return server + 1;
}