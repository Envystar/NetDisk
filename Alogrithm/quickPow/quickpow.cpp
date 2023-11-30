#include <iostream>

//快速幂，二进制取幂（Binary Exponentiation，也称平方法）
long long qucikPow(long long a, long long b)//a为底数，b为指数(a^b)
{
    long long res = 1;
    while(b > 0)
    {
         if(b & 1)   res *= a;//b为奇数，先乘a
        a *= a;
        b >>= 1;
    }
    return res;
}

int main()
{
    std::cout << qucikPow(2, 4);
    return 0;
}