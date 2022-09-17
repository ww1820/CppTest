# include <bits/stdc++.h>

using namespace std;

/*
第一行有三个正整数n,p,q(1<=n<=100000,1<=p,q<=n)，代表刷漆的次数，以及两个参数 p 和 q。

第二到四行给出了一个大小为3*n的矩阵，第 i 列的三个数从上到下记为l,r,t(1<=l,r<=1000000000,1<=t<=2)，代表第i次刷漆将编号在 l 到 r 之间的栅栏刷了一遍 t号油漆。

输出一个正整数，代表有多少栅栏可以长时间不掉色。


5 2 2
1 1 2 3 2
3 5 4 5 4
1 2 1 1 2

3
*/

vector<long long> F;
vector<long long> S;
int main()
{
    // freopen("../test.in", "r", stdin);
    // code
    int n, p, q;
    cin >> n >> p >> q;

    vector<long long> l(n);
    vector<long long> r(n);
    vector<long long> t(n);
    long long maxn = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> l[i];
    }

    for (int i = 0; i < n; ++i)
    {
        cin >> r[i];
        maxn = max(r[i], maxn);
    }

    for (int i = 0; i < n; ++i)
    {
        cin >> t[i];
    }

    F.resize(maxn+2);
    S.resize(maxn+2);

    for (int i = 0; i < n; ++i) {
        if(t[i] == 1) {
            ++F[l[i]];
            --F[r[i]+1];
        } else {
            ++S[l[i]];
            --S[r[i]+1];
        }
    }

    int res = 0;

    for (int i = 2; i < maxn+2; ++i)
    {
        F[i] += F[i - 1];
        S[i] += S[i - 1];
        if(F[i] >= p && S[i] >= q) {
            ++res;
        }
    }

    cout << res;

    return 0;
}