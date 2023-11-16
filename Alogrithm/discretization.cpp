#include <iostream>
#include <vector>
#include <algorithm>

//离散化

int main()
{
    // int a[6] = {1000, 500, 9999, 200, 356, 200};
    // for(int i = 0; i < 6; ++i)  std::cout << a[i] << "\t";  std::cout << "\n";
    // std::vector<int> arr(a, a + 6);  //使用std::vector拷贝数组
    // std::sort(arr.begin(), arr.end()); //对拷贝数组排序
    // std::vector<int>::iterator last = std::unique(arr.begin(), arr.end());//unique去重返回新的尾迭代器
    // arr.erase(last, arr.end());//删除后面元素，即更新尾迭代器
    // for(int i = 0; i < 6; ++i)  //替换原有数组值  迭代器相减返回的是两个迭代器之间的间隔
    //     a[i] = std::lower_bound(arr.begin(), arr.end(), a[i]) - arr.begin() + 1;
    // for(int i = 0; i < 6; ++i)  std::cout << a[i] << "\t";  std::cout << "\n";
    
    std::vector<int> arr = {1000, 500, 9999, 200, 356, 200};
    std::vector<int> tmp(arr);  // 创建副本
    std::sort(tmp.begin(), tmp.end()); //对副本排序
    tmp.erase(std::unique(tmp.begin(), tmp.end()), tmp.end());//去重
    for (int i = 0; i < arr.size(); ++i) //替换原有数组值
        arr[i] = std::lower_bound(tmp.begin(), tmp.end(), arr[i]) - tmp.begin();
    for(int i = 0; i < 6; ++i)  std::cout << arr[i] << "\t";  std::cout << "\n";

    system("pause");
    return 0;
}