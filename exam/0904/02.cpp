#include<bits/stdc++.h>
#include "/data/workspace/cpp_test/tool.h"

using namespace std;

/*
5 2
3 10 5 4 2
*/

int main() {
    int n, k;
    infile >> n >> k;

    deque<long> peaches;

    long sum = 0;

    for (int i = 0; i < n; ++i) {
        long a;
        infile >> a;
        sum += a;
        peaches.emplace_back(a);
    }

    sort(peaches.begin(), peaches.end());

    double avg = (sum + 0.0) / n;

    while(peaches.back() > k * avg) {
        // 拿出一个桃子
        long max_p = peaches.back();
        long min_p = peaches.front();

        if(avg - min_p > max_p - avg) {
            // min_p 更远
            peaches.pop_front();
            sum -= min_p;
            avg = (sum + 0.0) / --n;
        }
        else
        {
            peaches.pop_back();
            sum -= max_p;
            avg = (sum + 0.0) / --n;
        }
    }

    cout << peaches.size();
    return 0;
}