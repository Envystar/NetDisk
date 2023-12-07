#include <bits/stdc++.h>
#define LEN 2048

void strToBigNum(std::string s, int a[])
{
    int len = (int)s.size() - 1;
    for(int i = len; i >= 0; --i)
    {
        a[len - i] = s[i] - '0';
    }
}

void multiply(int a[], int b[], int c[]) {
  for (int i = 0; i < LEN; ++i) 
  {
    for (int j = 0; j <= i; ++j)    c[i] += a[j] * b[i - j];
    c[i + 1] += c[i] / 10;
    c[i] %= 10;
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
    multiply(a, b, c);
    print(c);
    return 0;
}