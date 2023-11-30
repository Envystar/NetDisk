#include <iostream> 

//希尔排序
void shellSort(int a[], int n)
{
    for(int i = n / 2; i > 0; i /= 2)//定义增量为n/2, 每次增量变为原来的1/2
    {
        for(int j = i; j < n; ++j)//插入排序，从第二个元素开始,第一个索引为0
        {
           for(int k = j; a[k] < a[k - i] && k >= i; k -= i)
           {
                std::swap(a[k], a[k - i]);
                for(int i = 0; i < n; ++i)  std::cout << a[i] << " ";
                std::cout << "\n";
           }
        }
    }
}

int main()
{
    int a[10] = {10, 6, 7, 8, 5, 1, 3, 2, 4, 9};
    int n = sizeof(a)/ sizeof(int);
    shellSort(a, n);
    for(int i = 0; i < n; ++i)  std::cout << a[i] << " ";
    system("pause");
    return 0;
}