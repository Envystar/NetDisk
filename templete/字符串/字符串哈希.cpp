#include <bits/stdc++.h>
using u64 = unsigned long long;

//字符串hash
//https://www.luogu.com.cn/problem/P3370
class StrHash {
public:
    StrHash() {};
    StrHash(const std::string &s) {
        v.resize(s.length() + 2);
        len = s.length();
        for(int i = 1; i <= len; ++i) {
            v[i][0] = v[i - 1][0] * MOD + s[i - 1];
        }
        for(int i = len; i >= 1; --i) {
            v[i][1] = v[i + 1][1] * MOD + s[i - 1];
        }
    }
    std::array<u64, 2> query(int l, int r) { //[l, r]的哈希，下标从1开始
        u64 t = qpow(MOD, r - l + 1);
        return {v[r][0] - v[l - 1][0] * t, v[l][1] - v[r + 1][1] * t};
    }
    bool palindrome(int l, int r) { //判断是否回文
        auto [x, y] = query(l, r);
        return x == y;
    }
private:
    std::vector<std::array<u64, 2>> v;
    int len;
    const u64 MOD = 233; //313 1949 1951
    u64 qpow(u64 a, u64 b) {
        u64 res = 1;
        while(b > 0) {
            if(b & 1) res *= a;
            b >>= 1;
            a *= a;
        }
        return res;
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::set<std::array<u64, 2>> st;
    for(int i = 0; i < n; ++i) {
        std::string s;
        std::cin >> s;
        StrHash sh(s);
        st.insert(sh.query(1, s.size()));
    }
    std::cout << st.size() << '\n';
    return 0;
}