#include <bits/stdc++.h>

int main() {
    int n, q;
    std::cin >> n >> q;
    std::vector<std::vector<int>> st(n, std::vector<int>(log2(n) + 1));//st表
    for(int i = 0; i < n; ++i) {
        std::cin >> st[i][0];//输入以i开始，2^0个数字
    }
    for(int i = 0; i < log2(n); ++i) {
        for(int j = 0; j + (1 << i) < n; ++j) {
            st[j][i + 1] = std::max(st[j][i], st[j + (1 << i)][i]);
        }
    }
    for(int i = 0; i < q; ++i) {
        int l, r;
        std::cin >> l >> r;
        --l, --r;
        int t = log2(r - l + 1);
        std::cout << std::max(st[l][t], st[r + 1 - (1 << t)][t]) << '\n';
    }
    return 0;
}