#include <iostream>
#include <cstring> // 添加头文件以使用 memset 函数

const int s = 2; // 将矩阵大小定义为常量

class matrix
{
public:
    long long m[s][s];
    matrix() { std::memset(m, 0, sizeof(m));} 
};

matrix operator*(const matrix &x, const matrix &y)
{
    matrix res;
    for (int i = 0; i < s; ++i)
    {
        for (int j = 0; j < s; ++j)
        {
            for (int k = 0; k < s; ++k)
            {
                res.m[i][j] += x.m[i][k] * y.m[k][j];
            }
        }
    }
    return res;
}

matrix matrixQuickPow(matrix base, int b)
{
    matrix res;
    for(int i = 0; i < s; ++i)   res.m[i][i] = 1;
    while(b > 0)
    {
        if(b & 1)   res = res * base;
        base = base * base;
        b >>= 1;
    }
    return res;
}

int main()
{
    matrix a;
    a.m[0][0] = 2;
    a.m[0][1] = 0;
    a.m[1][0] = 0;
    a.m[1][1] = 2;
    a = matrixQuickPow(a, 3);
    for(int i = 0; i < 2; ++i)
    {
        for(int j = 0; j < 2; ++j)
        {
            std::cout << a.m[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}