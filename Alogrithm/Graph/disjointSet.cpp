#include <bits/stdc++.h>

int main()
{
   int n, m;
    std::cin >> n >> m;
    std::vector<int> v(n, -1);
    auto find = [&](auto self, int x) ->int {//寻找根节点
        if(v[x] == -1) {
            return x;
        }
        v[x] = self(self, v[x]);
        return v[x];
    };
    auto uniset = [&](int x, int y) -> void {//合并集合
        int px = find(find, x);
        int py = find(find, y);
        if(px != py) {
            v[px] = py;
        }
    };
    auto query = [&](int x, int y) ->bool {//查询是否在同一集合
        int px = find(find, x);
        int py = find(find, y);
        if(px == py) {
            return true;
        } else {
            return false;
        }
    };

    for(int i = 0; i < m; ++i) {
        int z, x, y;
        std::cin >> z >> x >> y;
        x--, y--;
        if(z == 1) {
            uniset(x, y);
        } else if(z == 2) {
            std::cout << (query(x, y) ? 'Y' : 'N') << '\n';
        }
    }
    return 0;
} 