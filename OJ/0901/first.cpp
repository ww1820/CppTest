#include <bits/stdc++.h>
using namespace std;

ifstream infile("/data/workspace/cpp_test/test.txt", ios::in);

#define MAXN 1005

bool isnp[MAXN];
vector<int> primes; // 质数表
// set<int> table; // 表
vector<int> table; // 表
vector<int> record(1000001, 0);
void init(int n)
{
    for (int i = 2; i <= n; i++)
    {
        if (!isnp[i])
            primes.push_back(i);
        for (int p : primes)
        {
            if (p * i > n)
                break;
            isnp[p * i] = 1;
            if (i % p == 0)
                break;
        }
    }
}

void initTable(int N)
{
    int num;
    for (int a = 0; a < N; ++a)
    {
        for (int b = 0; b < N; ++b)
        {
            for (int c = 0; c < N; ++c)
            {
                num = primes[a] * primes[a] + primes[b] * primes[b] * primes[b] + primes[c] * primes[c] * primes[c] * primes[c];
                if (num > 1000000)
                    break;
                table.emplace_back(num);
                // table.emplace(num);
            }
        }
    }
}

int main()
{
    init(MAXN);
    int N = primes.size();
    initTable(N);
    int t, n;
    sort(table.begin(), table.end());
    int idx = 0;
    for (int i = 1; i < 1000001; ++i)
    {
        if (table[idx] > i)
        {
            record[i] = record[i - 1];
        }
        else
        {
            idx++;
            record[i] = ++record[i - 1];
        }
        // if(table.find(i) != table.end()) {
        //     record[i] = ++record[i-1];
        // } else {
        //     record[i] = record[i-1];
        // }
    }
    infile >> t;
    while (t--)
    {
        infile >> n;
        cout << record[n] << endl;
    }
}
