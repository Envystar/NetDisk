#include <bits/stdc++.h>
using i64 = long long;

//tarjan求强连通分量(scc)
//https://www.luogu.com.cn/problem/B3609
int main() {
	std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> v(n + 1), scc;
    std::vector<int> dfn(n + 1), low(n + 1), instk(n + 1);
    for(int i = 0; i < m; ++i) {
        int x, y;
        std::cin >> x >> y;
        v[x].push_back(y);
    }
    int fn = 0;
    std::stack<int> stk;
    auto  tarjan = [&](auto self, int id) ->void  {
        dfn[id] = low[id] = ++fn;
        stk.push(id);
        instk[id] = 1;
        for(auto nxt : v[id]) {
            if(dfn[nxt] == 0) {
                self(self, nxt);
                low[id] = std::min(low[id], low[nxt]);
            } else if(instk[nxt]) { //返祖边且在栈里
                low[id] = std::min(low[id], low[nxt]);
            }
        }
        if(dfn[id] == low[id]) {
            std::cout << id << '\n';
            scc.push_back(std::vector<int>{});
            int num = stk.top();
            do {
                num = stk.top();
                stk.pop();
                instk[num] = 0;
                scc.back().push_back(num);
            } while(num != id);
        }
    };
    for(int i = 1; i <= n; ++i) {
        if(!dfn[i]) {
            tarjan(tarjan, i);
        }
    }
    std::cout << scc.size() << '\n';
    for(auto &vec : scc) {
        sort(vec.begin(), vec.end());
    }
    std::sort(scc.begin(), scc.end());
    for(auto &vec : scc) {
        for(int i = 0; i < vec.size(); ++i) {
            std::cout << vec[i] << " \n"[i == vec.size() - 1];
        }
    }
    return 0;
}