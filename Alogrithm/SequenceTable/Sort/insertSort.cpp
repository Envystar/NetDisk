#include <iostream>

//插入排序
void insertSort(int a[], int n)
{
    for(int i = 1; i < n; ++i)
    {
        for(int j = i; a[j - 1] > a[j] && j > 0; --j) 
        {
            std::swap(a[j - 1], a[j]);
        }
    }
}

int main()
{
    int a[10] = {10, 6, 7, 8, 5, 1, 3, 2, 4, 9};
    int n = sizeof(a)/ sizeof(int);
    insertSort(a, n);
    for(int i = 0; i < n; ++i)  std::cout << a[i] << " ";
    system("pause");
    return 0;
}