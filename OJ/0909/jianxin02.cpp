#include<bits/stdc++.h>

using namespace std;

fstream infile("/data/workspace/cpp_test/test.txt", ios::in);

void Stringsplit(const string& str, const char split, vector<string>& res)
{
	if (str == "")		return;
	//在字符串末尾也加入分隔符，方便截取最后一段
	string strs = str + split;
	size_t pos = strs.find(split);

	// 若找不到内容则字符串搜索函数返回 npos
	while (pos != strs.npos)
	{
		string temp = strs.substr(0, pos);
		res.push_back(temp);
		//去掉已分割的字符串,在剩下的字符串中进行分割
		strs = strs.substr(pos + 1, strs.size());
		pos = strs.find(split);
	}
}


int main() {
    string str;
    infile >> str;
    vector<string> num;
    Stringsplit(str, ',', num);

    int m = stoi(num[0]);
    int t1 = stoi(num[1]);
    int m1 = stoi(num[2]);
    int t2 = stoi(num[3]);
    int m2 = stoi(num[4]);
    int t = stoi(num[5]);


    int n1 = t / (2 * t1);
    int last1 = t - n1 * (2 * t1);
    if(last1 > t1)
        last1 = t1;
    int in = m1 * (n1 * t1 + last1);

    int n2 = t / (2 * t2);
    int last2 = t - n2 * (2 * t2);
    if(last2 > t2)
        last2 = t2;
    int out = m2 * (n2 * t2 + last2);

    int res = in - out;

    if(res < 0) {
        cout << 0;
    } else if(res > m) {
        cout << m;
    } else {
        cout << res;
    }
    return 0;
}