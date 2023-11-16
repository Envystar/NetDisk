# 顺序表

## 排序算法

**动画演示：**[排序（冒泡排序，选择排序，插入排序，归并排序，快速排序，计数排序，基数排序） - VisuAlgo](https://visualgo.net/zh/sorting)

| 排序方式           | 平均时间复杂度 | 最好情况       | 最坏情况       | 空间复杂度 | 排序方式   | 稳定性 |
| :----------------- | -------------- | -------------- | -------------- | ---------- | ---------- | ------ |
| **冒泡排序** | $O(n^2)$     | $O(n)$       | $O(n^2)$     | $O(1)$   | In -Place  | 稳定   |
| **选择排序** | $O(n^2)$     | $O(n^2)$     | $O(n^2)$     | $O(1)$   | In -Place  | 不稳定 |
| **插入排序** | $O(n^2)$     | $O(n)$       | $O(n^2)$     | $O(1)$   | In -Place  | 稳定   |
| **希尔排序** | $O(nlogn)$   | $O(nlog^2n)$ | $O(nlog^2n)$ | $O(1)$   | In -Place  | 不稳定 |
| **归并排序** | $O(nlogn)$   | $O(nlogn)$   | $O(nlogn)$   | $O(n)$   | Out -Place | 稳定   |
| **快速排序** | $O(nlogn)$   | $O(nlogn)$   | O(n^2)         | $O(1)$   | In -Place  | 不稳定 |
| **堆排序**   | $O(nlogn)$   | $O(nlogn)$   | $O(nlogn)$   | $O(1)$   | In -Place  | 不稳定 |
| **计数排序** | $O(n+k)$     | $O(n+k)$     | $O(n+k)$     | $O(k)$   | Out -Place | 稳定   |
| **桶排序**   | $O(n+k)$     | $O(n+k)$     | O(n^2)         | $O(n+k)$ | Out -Place | 稳定   |
| **基数排序** | $O(n×k)$    | $O(n×k)$    | $O(n×k)$    | $O(n+k)$ | Out -Place | 稳定   |

### 冒泡排序

**算法特点：相邻元素两两比较，每趟将最值沉底即可确定一个数在结果的位置，确定元素位置的顺序是从后往前。**

```c++
//核心代码
void bubbleSort(int a[], int n)//参数1：数组a， 参数2：数组a中元素个数
{
    for(int i = 0; i < n - 1; ++i)//n-1指冒n-1次泡，最后一个自能确定
    {
        for(int j = 0; j < n - i - 1; ++j) //遍历n-i-1个数，因为后面的n-i个元素已经排序
        {
            if(a[j] > a[j+1]) 
            {
                std::swap(a[j], a[j + 1]);
            }
        }
    }
}
```

**复杂度分析：** 平均时间复杂度为$O(n^2)$, 最好情况$O(n)$,最坏情况$O(n^2)$,空间复杂度为$O(1)$,稳定

### 选择排序

**算法特点：首先在未排序序列中找到最小（大）元素，存放到排序序列的起始位置，然后，再从剩余未排序元素中继续寻找最小（大）元素，然后放到已排序序列的末尾。以此类推，直到所有元素均排序完毕。**

**与冒泡排序不同的是，选择排序是先找再换，冒泡排序是边找边换**

```C++
//核心代码
void selectSort(int a[], int n)//参数1：数组a， 参数2：数组a中元素个数
{
    for(int i = 0; i < n; ++i)
    {
        int min = i;//记录当前最小值的索引
        for(int j = i; j < n; ++j)//遍历i到n-1
        {
            if(a[j] < a[min])   min = j;//发现更小的结果，则更新索引
        }
        std::swap(a[i], a[min]);//交换值，更新数组
    }
}
```

**复杂度分析：** 平均时间复杂度为$O(n^2)$, 最好情况$O(n^2)$,最坏情况$O(n^2)$,空间复杂度为$O(1)$,不稳定

### 插入排序

**算法分析：将序列分为有序序列和无序序列，依次从无序序列中取出元素值插入到有序序列的合适位置。初始时有序序列中只有第一个数，其余n-1个数组成无序序列，则n个数需进n-1次插入。寻找在有序序列中插入位置可以从有序序列的最后一个数往前找，在未找到插入点之前可以同时向后移动元素，为插入元素准备空间。**

```C++
//核心代码
void insertSort(int a[], int n)//参数1：数组a， 参数2：数组a中元素个数
{
    for(int i = 1; i < n; ++i)//从下标为1为索引，遍历
    {
        for(int j = i; a[j - 1] > a[j] && j > 0; --j)//找到较小数，则与前数交换，直到前数较小或到下标为0处
        {
            std::swap(a[j - 1], a[j]);
        }
    }
}
```

**复杂度分析：** 平均时间复杂度为$O(n^2)$, 最好情况$O(n)$,最坏情况$O(n^2)$,空间复杂度为$O(1)$,稳定

### **希尔排序**

**基本思想：先将整个待排序的记录序列分割成为若干子序列分别进行直接插入排序，待整个序列中的记录"基本有序"时，再对全体记录进行依次直接插入排序。**

```c++
//核心代码 
void shellSort(int a[], int n)
{
    for(int i = n / 2; i > 0; i /= 2)//定义增量为n/2, 每次增量变为原来的1/2
    {
        for(int j = i; j < n; ++j)//插入排序，从第二个元素开始,第一个索引为0
        {
           for(int k = j; a[k] < a[k - i] && k >= i; k -= i)
           {
                std::swap(a[k], a[k - i]);
           }
        }
    }
}
```

**复杂度分析：** 平均时间复杂度为$O(nlogn)$, 最好情况$O(nlog^2n)$,最坏情况$O(nlog^2n)$,空间复杂度为$O(1)$,不·稳定

### 归并排序

**归并排序（MERGE-SORT）是利用归并和递归的思想实现的排序方法，该算法采用经典的分治（divide-and-conquer）策略**

```C++
//核心代码
//归并
void merge(int a[], int tempArr[], int left, int mid, int right)
{
    int lpos = left, rpos = mid + 1, index = left;;//标记左右半区第一个未排序的元素 以及临时数组索引
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

```

## 二分

## 离散化

## 前缀和

# 字符串

## KMP快速查找算法

# 栈

# 队列

# 树

# 图

# 数论

## 素数判定

### 定义法

利用素数的定义进行判定

#### 定义判定

遍历2到n-1；判断是否能被整除

```c++
bool isPrime(int n)
{
	for(int i = 2; i < n; ++i)
    {
		if(n % i == 0)
            return false;
    }
    return true;
}
```

#### 定义判定改法

遍历到sqrt()就可以，由于sqrt()计算较慢，可转化为i * i <=  n; 但可能导致越界，进入死循环，改为 i <= n / i;

```c++
bool isPrime(int n)
{
	for(int i = 2; i <= n / i; ++i)
    {
		if(n % i == 0)
            return false;
    }
    return true;
}
```

### 素数筛

bitset `<nums>` name;类似于bool数组，默认值为0，详见[std::bitset - cppreference.com](https://zh.cppreference.com/w/cpp/utility/bitset)

#### 朴素筛法

```c++
const int maxn = 1e6 + 10;
bitset<maxn> prime;//0表示素数，1表示合数
bool isPrime(int n)
{
	for(int i = 2; i < n; ++i)
    {
		if(n % i == 0)
            return false;
    }
    return true;
}

int main()
{
    for (int i = 2; i <= N / i; ++i)
    {
        if (isprime(i))//如果是素数
        {
            for (int j = 2 * i; j <= N; j+=i)//从i的倍数开始筛，每次增加一倍
            {
                prime[j] = 1;//标记为合数
            }
        }
    }
}
```

#### 埃氏筛法

不用再判断是否为素数，前面的素数已经判定过，并记录在bitset中

缺点：一个合数可能同时被两个素数筛

```c++
const int maxn = 1e6 + 10;
bitset<maxn> prime;//0表示素数，1表示合数
for (int i = 2; i <= N / i; ++i)
{
	if (!prime[i])//如果是素数
	{
		for (int j = i * i; j <= N; j+=i)//从i的平方开始筛，每次增加一倍
		{
			prime[j] = 1;//标记为合数
		}
	}
}
```

#### 欧拉筛法

解决一个素数被两个素数筛掉，效率低的问题

```c++
const int maxn = 1e6 + 10;
bitset<maxn> prime;//0表示素数，1表示合数
int primes[maxn], pp = 0;//建立一个素数表，和一个遍历指针

int N = 1e6;
for (int i = 2; i <= N; ++i)//遍历所有值
{
	if (!prime[i])//如果是素数
	{
		primes[++pp] = i;//记录在素数表里
	}

	for (int j = 1; primes[j] * i <= N; ++j)
	{
		prime[primes[j] * i] = 1;//找出素数的倍数，标记为合数
		if (i % primes[j] == 0)//如果能被整除，跳出循环
		{
			break;
		}
	}
}
//pp即为素数的个数
```
