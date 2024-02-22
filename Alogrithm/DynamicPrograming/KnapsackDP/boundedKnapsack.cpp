#include <bits/stdc++.h>

//多重背包问题
const int M = 4e4 + 5;//背包容量
int dp[M];

int main() {
    int n, m;
    std::cin >> n >> m;
    /*//朴素做法
    for(int i = 1; i <= n; ++i) {
        int v, w, s;
        std::cin >> v >> w >> s;
        for(int j = m; j >= v; --j) {
            for(int k = 1; k <= s && j >= k * v; ++k) {//挑选出从选1个到选k个数中最大的
                dp[j] = std::max(dp[j], dp[j - k * v] + k * w);
            }
        } 
    }*/
    /*//二进制拆分优化
    for(int i = 1; i <= n; ++i) {
        int v, w, s;
        std::cin >> v >> w >> s;
        for(int j = 1; s != 0; j <<= 1) {
            if(j > s) {
                j = s;
            }
            for(int k = m; k >= j * v; --k) {
                dp[k] = std::max(dp[k], dp[k - j * v] + j * w);
            }
            s -= j;
        }
    }*/
    for(int i = 1; i <= n; ++i) {
        int dpp[M], q[M], v, w, s;
        std::cin >> v >> w >> s;
        std::copy(dp, dp + m + 1, dpp);
        for(int j = 0; j < v; ++j) {
            int h = 0, t = -1;
            for(int k = j; k <= m; k += v) {
                if(q[h] < k - s * v) {
                    ++h;
                }
                while(h <= t && dpp[k] >= dpp[q[t]] + (k - q[t]) / v * w) {
                    --t;
                };
                q[++t] = k;
                dp[k] = dpp[q[h]] + (k - q[h]) / v * w;
            }
        } 
    }
    std::cout << dp[m];
    return 0;
}