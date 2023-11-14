#include <iostream>

void bubbleSort(int a[], int n)
{
    for(int i = 0; i < n - 1; ++i)
    {
        for(int j = 0; j < n - 1 - i; ++j) 
        {
            if(a[j] > a[j+1]) 
            {
                std::swap(a[j], a[j + 1]);
            }
        }
    }
}

int main()
{
    int a[10] = {10, 6, 7, 8, 5, 1, 3, 2, 4, 9};
    int n = sizeof(a)/ sizeof(int);
    bubbleSort(a, n);
    for(int i = 0; i < n; ++i)  std::cout << a[i] << " ";
    system("pause");
    return 0;
}