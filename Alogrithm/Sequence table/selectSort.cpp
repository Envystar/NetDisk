#include <iostream>

//选择排序
void selectSort(int a[], int n)
{
    for(int i = 0; i < n; ++i)
    {
        int min = i;
        for(int j = i; j < n; ++j) 
        {
            if(a[j] < a[min])   min = j;
        }
        std::swap(a[i], a[min]);
    }
}

int main()
{
    int a[10] = {10, 6, 7, 8, 5, 1, 3, 2, 4, 9};
    int n = sizeof(a)/ sizeof(int);
    selectSort(a, n);
    for(int i = 0; i < n; ++i)  std::cout << a[i] << " ";
    system("pause");
    return 0;
}