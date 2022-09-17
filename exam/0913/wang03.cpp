//std_slow
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
using namespace std;
const int MOD = 998244353;
long long f[2][(1 << 24)];
//long long (*f)[(1 << 28)] = new long long [2][(1 << 28)];
int n;
long long quickmul(int a, int b)
{
	long long ret = 1;
	for(; b; b >>= 1, a = (long long)a * a % MOD)
		if(b & 1)
			ret = ret * a % MOD;
	return ret;
}
int main()
{
	freopen("../test.in", "r", stdin);
	scanf("%d", &n);
	f[1][0] = 0;
	f[1][1] = 1;
	for(int i = 2; i <= n; i++)
	{
		memset(f[i & 1], 0, sizeof(long long) << i);
		for(int S = 1; S < (1 << (i - 1)); S++)
		{
			int l = 0, r = S ^ (S & -S);
			long long now = f[~i & 1][S];
			for(int j = 0; j < i; j++)
			{
				f[i & 1][l | (1 << j) | (r << 1)] += now;
				if(S & (1 << j))
					l ^= (1 << j), r ^= (r & -r);
			}
		}
		for(int S = 1; S < (1 << i); S++)
			f[i & 1][S] %= MOD;
	}
	long long ans = 0;
	for(int S = (1 << n) - 1; S >= 1; S--)
	{
		if(S & 1)
			ans += f[n & 1][S];
		f[n & 1][S >> 1] += f[n & 1][S];
	}
	ans %= MOD;
	long long tmp = 1;
	for(int i = 1; i <= n; i++)
		tmp = tmp * i % MOD;
	ans = ans * quickmul(tmp, MOD - 2) % MOD;
	printf("%d\n", (int)ans);
	return 0;
}