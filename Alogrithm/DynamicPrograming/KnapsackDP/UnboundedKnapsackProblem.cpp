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
    int begin = clock();
    for(int i = 1; i <= n; ++i)
    {
        //从后往前，此时索引前方的数组仍为上个状态的，保证数据有效
        for(int j = m; j >= 0; --j)
        {
            if(j >= v[i])//可选的话
                dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
        }
    }

    cout << dp[m];
    int end = clock();
    cout << "\n用时: " << end - begin << "ms";
    return 0;
}