#include <bits/stdc++.h>
using namespace std;

//完全背包问题
const int N = 1000, M = 1000;//N个商品，背包体积为M
int dp[M];//dp[i]表示体积是i的情况下的最大价值
int v[N], w[N];//体积，价值


int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)  cin >> v[i] >> w[i];
    for(int i = 1; i <= n; ++i)
    {
        for(int j = v[i]; j <= m; --j)
            dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
    }
    cout << dp[m];
    return 0;
}