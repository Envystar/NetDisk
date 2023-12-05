#include <bits/stdc++.h>
#define LEN 1024

void strToBigNum(std::string s, int a[])
{
    int len = (int)s.size() - 1;
    for(int i = len; i >= 0; --i)
    {
        a[len - i] = s[i] - '0';
    }
}

bool isBigger(std::string s, std::string t)
{
    if(s.size() == t.size())
        return s >= t;
    else 
        return s.size() > t.size();
}

void substract(int a[], int b[], int c[])
{
    for(int i = 0; i < LEN - 1; ++i)
    {
        c[i] += a[i] - b[i];
        c[i + 1] += (c[i] - 9) / 10;//进位
        c[i] = (c[i] + 10) % 10;
    }
}

void print(int a[])
{
    int i = LEN - 1;
    while(a[i] == 0 && i >= 1)    --i;//到1而不是0，是结果为0时仍要输出
    for(; i >= 0; --i)  std::cout << a[i];
}

int main()
{
    std::string s, t;
    std::cin >> s >> t;
    int a[LEN] = {0}, b[LEN] = {0}, c[LEN] = {0};
    strToBigNum(s, a);
    strToBigNum(t, b);
    if(isBigger(s, t))  substract(a, b, c);
    else {substract(b, a, c); std::cout << '-';}
    print(c);
    return 0;
}