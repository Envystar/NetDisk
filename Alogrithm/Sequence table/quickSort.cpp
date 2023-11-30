#include <iostream>

//快速排序(参数：数组最小和最大下标，数组本身)
void quickSort(int left, int right, int a[])
{
    if(left >= right) return;
    else
    {
        int low = left, pivot = right;//选定最右侧元素
        int(fast = left; i < pivote; ++fast)
        {
            if(a[fast] < a[pivot])//找到比pivot指向小的元素
            {
                std::swap(a[fast], a[low++]);
            }
        }
        std::swap(a[low], a[pivot]);//对换
        pivot = low;
        quickSort(left, pivot - 1, a);
        quickSort(pivot + 1, right, a);
    }
}

int main()
{
    int a[10] = {10, 6, 7, 8, 5, 1, 3, 2, 4, 9};
    int n = sizeof(a)/ sizeof(int);
    quickSort(0, n - 1, a);
    for(int i = 0; i < n; ++i)  std::cout << a[i] << " ";
    system("pause");
    return 0;
}