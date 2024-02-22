#include <bits/stdc++.h>

//01背包问题
const int M = 1005;//N个商品，背包体积为M
int dp[M];//dp[i]表示体积是i的情况下的最大价值

int main()
{
    int n, m;
    std::cin >> n >> m;
    for(int i = 1; i <= n; ++i) {
        int num;
        std::cin >> num;
        std::vector<int> v(num), w(num);
        for(int j = 0; j < num; ++j) {
            std::cin >> v[j] >> w[j];
        }
        for(int j = m; j >= 0; --j) {
            for(int k = 0; k < num; ++k) {
                if(j - v[k] >= 0) {
                    dp[j] = std::max(dp[j], dp[j - v[k]] + w[k]);//不选和选中最大
                }
            }
        }
    }
    std::cout << dp[m];
    return 0;
}