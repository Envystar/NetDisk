#include <bits/stdc++.h>

class FHQTreap {
    std::mt19937 rng(time(0));
    class Node {
    public:
        int l, r;
        int val, rnd;
        int size;
    };
    std::vector<Node> tr;
    int root = 0;
    int tmp1, tmp2, tmp3;
    void pushup(int id) {
        tr[id].size = tr[tr[id].l].size + tr[tr[id].r].size + 1;
    }
    void split(int id, int v, int &x, int& y) {
        if(id == 0) {
            x = y = 0;
            return;
        }
        if(tr[id].val <= v) {
            x = id;
            split(tr[id].r, v, tr[id].r, y);
        } else {
            y = id;
            split(tr[id].l, v, x, tr[id].l);
        }
        pushup(id);
    }
    int merge(int x, int y) {
        if(x == 0 || y == 0) {
            return x + y;
        }
        if(tr[x].rnd < tr[y].rnd) {
            tr[x].r = merge(tr[x].r, y);
            pushup(x);
            return x;
        } else {
            tr[y].l = merge(x, tr[y].l);
            pushup(y);
            return y;
        }
    }
    void insert(int v) {//权值
        int x, y;
        split(root, v, x, y);
        tr.push_back(Node({0, 0, v, rng(), 1}));
        int z = tr.size();
        root = merge(merge(x, z), y);
    }
    void erase(int v) {
        int x, y, z;
        split(root, v, x, z);
        split(x, v, x, y);
        root = merge(x, z);
    }
    int rank(int v) {
        int x, y;
        split(root, v - 1, x, y);
        int res = tr[x].size + 1;
        merge(x, y);
        return res;
    }
};

int main() {
    for(int i = 0; i <= 10; ++i)
        std::cout << rng() << '\n';
    return 0;
}