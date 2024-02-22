#include <bits/stdc++.h>

//二维费用背包问题
const int V = 1005, M = 1005;//背包体积为V，最大承重为M

int dp[V][M];//dp[i][j]表示体积是i，重量是j的情况下的最大价值

int main()
{
    int n, vv, mm;
    std::cin >> n >> vv >> mm;
    for(int i = 1; i <= n; ++i) {
        int v, m, w;//体积，重量和价值
        std::cin >> v >> m >> w;
        for(int j = vv; j >= v; --j) {
            for(int k = mm; k >= m; --k) {
                dp[j][k] = std::max(dp[j][k], dp[j - v][k - m] + w);
            }
        }
    }
    std::cout << dp[vv][mm];
    return 0;
}