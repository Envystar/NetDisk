#include <bits/stdc++.h>

//tarjan求LCA
int main() {
    int n, m, s;
    std::cin >> n >> m >> s;
    std::vector<std::vector<int>> v(n + 1); 
    std::vector<std::vector<std::pair<int, int>>> query(n + 1);
    std::vector<int> fa(n + 1), vis(n + 1), ans(m);
    for(int i = 0; i < n - 1; ++i) {
        int x, y;
        std::cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for(int i = 0; i < m; ++i) {
        int x, y;
        std::cin >> x >> y;
        query[x].push_back({y, i});
        query[y].push_back({x, i});
    }
    auto lca = [&](auto self, int root) ->int {
        if(fa[root] == 0) {
            return root;
        }
        fa[root] = self(self, fa[root]);
        return fa[root];
    };
    auto tarjan = [&](auto self, int root) ->void {
        vis[root] = 1;
        for(auto son : v[root]) {
            if(!vis[son]) {
                self(self, son);
                fa[son] = root;
            }
        }

        for(auto [x, i] : query[root]) {
            if(vis[x]) {
                ans[i] = lca(lca, x);
            }
        }
    };
    tarjan(tarjan, s);
    for(int i = 0; i < m; ++i) {
        std::cout << ans[i] << '\n';
    }
    return 0;
}