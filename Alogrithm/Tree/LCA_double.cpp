#include <bits/stdc++.h>

//倍增法求LCA
int main() {
	std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m, s;
    std::cin >> n >> m >> s;
    std::vector<std::vector<int>> v(n + 1);
    std::vector<std::vector<int>> fa(n + 1, std::vector<int> (ceil(log2(n)) + 1, 0));
    std::vector<int> dep(n + 1);
    for(int i = 0; i < n - 1; ++i) {
        int x, y;
        std::cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    auto dfs = [&](auto self, int root, int father) ->void {
        fa[root][0] = father;
        dep[root] = dep[father] + 1;
        for(int i = 0; i < ceil(log2(n)); ++i) {
            fa[root][i + 1] =  fa[fa[root][i]][i];
        }
        for(int i = 0; i < v[root].size(); ++i) {
            if(v[root][i] != father) {
                self(self, v[root][i], root);
            }
        }
    };
    auto query = [&](int x, int y) ->int {
        if(dep[x] < dep[y]) {
            std::swap(x, y);
        }
        int dx = dep[x] - dep[y];
        for(int i = 0; dx > 0; ++i) {
            if(dx & 1) {
                x = fa[x][i];
            }
            dx >>= 1;
        }
        if(x == y) {
            return x;
        }
        for(int i = ceil(log2(n)); i >= 0; --i) {
            if(fa[x][i] != fa[y][i]) {
                x = fa[x][i];
                y = fa[y][i];
            }
        }
        return fa[x][0];
    };
    dfs(dfs, s, 0);
    for(int i = 0; i < m; ++i) {
        int x, y;
        std::cin >> x >> y;
        std::cout << query(x, y) << '\n';
    }
    return 0;
}