#include <bits/stdc++.h>

//完全背包问题
const int M = 1005;//N个商品，背包体积为M
int dp[M];//dp[i]表示体积是i的情况下的最大价值

int main() {
    int n, m;
    std::cin >> n >> m;
    for(int i = 1; i <= n; ++i) {
        int v, w;//体积，价值
        std::cin >> v >> w;
        for(int j = v; j <= m; ++j) {
            dp[j] = std::max(dp[j], dp[j - v] + w);
        }
    }
    std::cout << dp[m];
    return 0;
}

