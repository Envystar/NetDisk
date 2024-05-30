#include <bits/stdc++.h>

//树链剖分求LCA
int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(nullptr);
    int n, m, s;
    std::cin >> n >> m >> s;
    std::vector<std::vector<int>> v(n + 1);
    std::vector<int> fa(n + 1), dep(n + 1), son(n + 1), sz(n + 1), top(n + 1, 0);//父节点，深度，重儿子，子树节点数，所在重链的顶点
    for(int i = 0; i < n - 1; ++i) {
        int x, y;
        std::cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);       
    }
    auto dfs1 = [&](auto self, int root, int father) ->void {//求fa,dep, son, sz数组
        fa[root] = father;
        dep[root] = dep[father] + 1;
        sz[root] = 1;
        for(auto sn : v[root]) {
            if(sn == father) {
                continue;
            }
            self(self, sn, root);
            sz[root] += sz[sn];
            if(sz[son[root]] < sz[sn]) {
                son[root] = sn;
            }
        }
    };
    auto dfs2 = [&](auto self, int root, int t) ->void {
        top[root] = t;
        if(son[root] == 0) {
            return;
        }
        self(self, son[root], t);
        for(auto sn : v[root]) {
            if(sn == fa[root] || sn == son[root]) {
                continue;
            }
            self(self, sn, sn);
        }
    };
    auto lca = [&](int x, int y) ->int { 
        while(top[x] != top[y]) {
            if(dep[top[x]] < dep[top[y]]) {
                std::swap(x, y);
            }
            x = fa[top[x]];
        }
        return (dep[x] < dep[y] ? x : y);
    };
    dfs1(dfs1, s, 0);
    dfs2(dfs2, s, s);
    for(int i = 0; i < m; ++i) {
        int x, y;
        std::cin >> x >> y;
        std::cout << lca(x, y) << '\n';
    }
    return 0;
}