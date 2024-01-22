#include <bits/stdc++.h>

//01背包问题
const int M = 1005;//N个商品，背包体积为M
int dp[M];//dp[i]表示体积是i的情况下的最大价值

int main()
{
    int n, m;
    std::cin >> n >> m;
    for(int i = 1; i <= n; ++i) {
        int v, w;//体积和价值
        std::cin >> v >> w;
        for(int j = m; j >= v; --j) {//从后往前，此时索引前方的数组仍为上个状态的，保证数据有效
            dp[j] = std::max(dp[j], dp[j - v] + w);//不选和选中最大
        }
    }
    std::cout << dp[m];
    return 0;
}