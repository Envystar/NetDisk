#include <bits/stdc++.h>
const int N = 100;
//字典树

int ch[N][26], cnt[N], index;

//插入
void insert(std::string s) {
    int p = 0;
    for(int i = 0; i < s.length(); ++i) {
        int hush = s[i] - 'a'; 
        if(!ch[p][hush]){
            ch[p][hush] = ++index;
        }
        p = ch[p][hush];
    }
    ++cnt[p];
}

//查询
int query(std::string s) {
    int p = 0;
    for(int i = 0; i < s.length(); ++i) {
        int hush = s[i] - 'a'; 
        if(!ch[p][hush]){
            return 0;
        }
        p = ch[p][hush];
    }
    return cnt[p];
}
int main() {
    std::vector<std::string> v = {"apple", "car", "cat", "cap", "car", "banana", "a", "ab", "aab", "ab"};
    for(int i = 0; i < v.size(); ++i) {
        insert(v[i]);
    }
    for(int i = 0; i < v.size(); ++i) {
        std::cout << v[i] << '\t' << query(v[i]) << '\n';
    }
    return 0;
}