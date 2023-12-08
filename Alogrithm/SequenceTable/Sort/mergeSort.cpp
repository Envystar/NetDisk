#include <iostream>

//归并排序
void merge(int a[], int tempArr[], int left, int mid, int right)
{
    int lpos = left, rpos = mid + 1, index = left;//标记左右半区第一个未排序的元素 以及临时数组索引
    while(lpos <= mid && rpos <= right)//左右两区都有元素
    {
        if(a[lpos] <= a[rpos])
            tempArr[index++] = a[lpos++];//放入临时区
        else
            tempArr[index++] = a[rpos++];//放入临时区
    }
    //合并左半区剩余元素
    while (lpos <= mid)
        tempArr[index++] = a[lpos++];
    //合并右半区剩余元素
    while (rpos <= right)
        tempArr[index++] = a[rpos++];
    for(int i = left; i <= right; ++i)//拷贝新数据到数组中
        a[i] = tempArr[i];
}

//划分
void mSort(int a[], int tempArr[], int left, int right)
{
    if(left < right)
    {
        int mid = (left + right) / 2;//找中间点
        mSort(a, tempArr, left, mid);//划分左半区
        mSort(a, tempArr, mid + 1, right);//划分右半区
        merge(a, tempArr, left, mid, right);
    }
}

//归并排序入口
void mergeSort(int a[], int n)
{
    int *tempArr = new int[n];//创建副本
    mSort(a, tempArr, 0, n - 1);//调用merge函数，划分
    delete[] tempArr;//释放堆区内存
}

int main()
{
    int a[10] = {10, 6, 7, 8, 5, 1, 3, 2, 4, 9};
    int n = sizeof(a)/ sizeof(int);
    mergeSort(a, n);
    for(int i = 0; i < n; ++i)  std::cout << a[i] << " ";
    system("pause");
    return 0;
}