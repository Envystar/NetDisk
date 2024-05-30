#include <bits/stdc++.h>
using i64 = long long;

//线段树(segmentTree)
//单点修改，区间查询
class SegTree {
public:
    SegTree(const std::vector<i64>& v) : n(v.size()), tree(4 * n), add(4 * n) {
        build(v, 1, 0, n - 1);
    }
    void update(int l, int r, i64 dx) { 
        update(1, 0, n - 1, l, r, dx);
    }
    i64 query(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }
private:
    int n;
    std::vector<i64> tree, add;
#define nl(x) (x<<1)
#define nr(x) (x<<1|1)
    void pushup(int id) {
        tree[id] = tree[nl(id)] + tree[nr(id)];
    }
    void pushdown(int id, int s, int t) {
        if(s != t && add[id] != 0) {
            int mid = (s + t) / 2;
            tree[nl(id)] += 1LL * (mid - s + 1) * add[id];
            tree[nr(id)] += 1LL * (t - mid) * add[id];
            add[nl(id)] += add[id];
            add[nr(id)] += add[id];
            add[id] = 0;
        }
    }
    void build(const std::vector<i64>& v, int id, int s, int t) {
        if(s == t) {
            tree[id] = v[s];
            return;
        }
        int mid = (s + t) / 2;
        build(v, nl(id), s, mid);
        build(v, nr(id), mid + 1, t);
        pushup(id);
    }
    void update(int id, int s, int t, int l, int r, i64 dx) {
        if(l <= s && t <= r) {
            add[id] += dx;
            tree[id] += 1LL * (t - s + 1) * dx;
            return;
        }
        int mid = (s + t) / 2;
        pushdown(id, s, t);
        if(l <= mid) {
            update(nl(id), s, mid, l, r, dx);
        }
        if(mid < r) {
            update(nr(id), mid + 1, t, l, r, dx);
        }
        pushup(id);
    }
    i64 query(int id, int s, int t, int l, int r) {
        if(l <= s && t <= r) {
            return tree[id];
        }
        int mid = (s + t) / 2;
        i64 sum = 0;
        pushdown(id, s, t);
        if(l <= mid) {
            sum += query(nl(id), s, mid, l, r);
        }
        if(mid < r) {
            sum += query(nr(id), mid + 1, t, l, r);
        }
        return sum;
    }
#undef nl
#undef nr
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, q;
    std::cin >> n >> q;
    std::vector<i64> v(n);
    for(int i = 0; i < n; ++i) {
        std::cin >> v[i];
    }
    SegTree tree(v);
    for(int i = 0; i < q; ++i) {
        int t, x, y;
        std::cin >> t >> x >> y;
        x--, y--;
        if(t == 1) {//修改
            int k;
            std::cin >> k;
            tree.update(x, y, k);
        } else if(t == 2) {//查询
            std::cout << tree.query(x, y) << '\n';
        }
    }
    return 0;
}