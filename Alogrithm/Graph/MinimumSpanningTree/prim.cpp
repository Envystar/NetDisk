#include <bits/stdc++.h>

//prim算法最小生成树(稀疏图)
int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<std::pair<int, int>>> v(n);
    std::vector<int> vis(n);
    for(int i = 0; i < m; ++i) {
        int x, y, w;
        std::cin >> x >> y >> w;
        x--, y--;
        v[x].push_back({y, w});
        v[y].push_back({x, w});
    }

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
    int ans = 0;
    pq.push({0, 0});
    while(!pq.empty()) {
        auto [w, id] = pq.top();
        pq.pop();
        if(!vis[id]) {
            vis[id] = 1;
            ans += w;   
            for(auto [nxt, w] : v[id]) {
                if(!vis[nxt]) {
                    pq.push({w, nxt});
                }
            }
        } 
    }
    if(!*std::min_element(vis.begin(), vis.end())) {
        std::cout << -1 << '\n';
    } else {
        std::cout << ans << '\n';
    }
    return 0;
}