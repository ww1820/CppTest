#include<bits/stdc++.h>

using namespace std;

regex pattern("(\\d{4})-(0\\d{1}|1[0-2])-(0\\d{1}|[12]\\d{1}|3[01])T(0\\d{1}|1\\d{1}|2[0-3]):[0-5]\\d{1}:([0-5]\\d{1})");

// regex pattern("\\d+");	/*匹配一个到无穷个数字*/

int main() {
	
	string s = "1/2018-12-24T08:00:00/test/Test1";
	smatch result;
	string::const_iterator iter_begin = s.cbegin();
	string::const_iterator iter_end = s.cend();
	while (regex_search(iter_begin, iter_end, result, pattern))
	{
		cout << "查找成功：" << result[0] << endl;
		cout << "查找结果子串的在源串中的迭代器位置" << *result[0].first << endl;
		cout << "查找结果子串的在源串后面的位置" << *result[0].second << endl;
		iter_begin = result[0].second;	//更新迭代器位置
	}
    return 0;
}