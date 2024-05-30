#include <bits/stdc++.h>
using i64 = long long;

//tarjan求割点
int main() {
	std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> v(n + 1);
    std::vector<int> dfn(n + 1), low(n + 1), cutPoint(n + 1);
    for(int i = 0; i < m; ++i) {
        int x, y;
        std::cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    int fn = 0, root = 1;
    std::function<void(int)> tarjan = [&](int id) ->void {
        dfn[id] = low[id] = ++fn;
        int child = 0;
        for(auto nxt : v[id]) {
            if(!dfn[nxt]) {
                child++;
                tarjan(nxt);
                low[id] = std::min(low[id], low[nxt]); 
                if(low[nxt] >= dfn[id] && id != root) {
                    cutPoint[id] = 1;
                }
            } else {
                low[id] = std::min(low[id], dfn[nxt]); 
            }
        }
        if(child >= 2 && id == root)  {
            cutPoint[id] = 1;
        }
    };
    for(int i = 1; i <= n; ++i) {
        if(!dfn[i]) {
            root = i;
            tarjan(i);
        }
    }
    std::cout << std::count(cutPoint.begin(), cutPoint.end(), 1) << '\n';
    for(int i = 1; i <= n; ++i) {
        if(cutPoint[i]) {
            std::cout << i << ' ';
        }
    }
    return 0;
}