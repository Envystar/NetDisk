#include <bits/stdc++.h>

std::vector<int> manacher(std::string s) {
    std::string t = "#";//处理字符串
    for(int i = 0; i < 2 * s.length(); i+= 2) {
        t += s[i / 2];
        t += '#';
    }
    std::vector<int> v(t.length());//记录回文半径
    for(int i = 0, l = 0, r = 0; i < t.length(); ++i) {
        if(i <= r) {
            v[i] = std::min(v[l + r - i], r - i + 1);
        }
        while(i - v[i] >= 0 && i + v[i] < t.length() && t[i - v[i]] == t[i + v[i]]) {
            ++v[i];
        }
        if(i + v[i] - 1 > r) {
            l = i - v[i] + 1;
            r = i + v[i] - 1;
        }
    }
    return v;
}

//abba

int main() {
    std::string s;
    std::cin >> s;
    std::vector<int> v = manacher(s);
    return 0;
}