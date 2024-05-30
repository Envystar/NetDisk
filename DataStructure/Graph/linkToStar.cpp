#include <bits/stdc++.h>

//链式前向星存图

struct edge{
    int u, v, w;
};

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<edge> g;
    std::vector<int> head(n, -1);
    auto add = [&](int u, int v, int w) ->void {
        g.push_back({head[u], v, w});
        head[u] = g.size() - 1;
    };
    auto check = [&](int u) ->void {//查找从u点能到达的所有点
        for(int i = head[u]; ~i; i = g[i].u) {
            std::cout << g[i].v << ' ' << g[i].w << '\n';
        }
    };
    for(int i = 0; i < m; ++i) {
        int u, v, w;
        std::cin >> u >> v >> w;
        u--, v--;
        add(u, v, w);
    }
    check(0);
    std::cout << '\n';
    return 0;
}