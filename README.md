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

**复杂度分析：** 平均时间复杂度为 $O(n^2)$ , 最好情况 $O(n)$ ,最坏情况 $O(n^2)$ ,空间复杂度为 $O(1)$ ,稳定

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

**复杂度分析：** 平均时间复杂度为 $O(n^2)$ , 最好情况 $O(n^2)$ ,最坏情况 $O(n^2)$ ,空间复杂度为 $O(1)$ ,不稳定

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

**复杂度分析：** 平均时间复杂度为 $O(n^2)$ , 最好情况 $O(n)$ ,最坏情况 $O(n^2)$ ,空间复杂度为 $O(1)$ ,稳定

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

**复杂度分析：** 平均时间复杂度为 $O(nlogn)$ , 最好情况 $O(nlog^2n)$ ,最坏情况 $O(nlog^2n)$ ,空间复杂度为 $O(1)$ ,不稳定

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

### 快速排序

**快排思路：选定pivot通过划分数组使pivot左侧所有元素都小于等于它，右侧所有元素都大于它。然后对pivot的左侧和右侧分别递归进行划分调整，直至当前区间不用再调整(left >= right)**

**一般步骤：**

1. **选择基准元素，一般选择首尾元素（示例代码选择尾元素）**
2. **将较小（大）元素放基准元素前边，其余放后边**
3. **具体实现，取快慢双指针，快指针一直移动到尾元素，若遇到指向的元素比基准元素小（大）的元素，则交换快慢指针对应元素，慢指针向前移动一位，快指针仍然移动**
4. **循环结束后，交换基准元素和慢指针对应元素和指针**

```C++
//核心代码
//快速排序(参数：数组最小和最大下标，数组本身)
void quickSort(int left, int right, int a[])
{
    if(left < right)
    {
        int low = left, pivot = right;//选定最右侧元素
        for(int fast = left; fast < pivot; ++fast)
        {
            if(a[fast] < a[pivot])//找到比pivot指向小的元素
                std::swap(a[fast], a[low++]);
        }
        std::swap(a[low], a[pivot]);//对换
        quickSort(left, low - 1, a);
        quickSort(low + 1, right, a);
    }
}
```

## 二分

## 离散化

**用途：用于当不考虑数据本身的绝对大小，而更关注于相对大小的时候。**

**思想：将广而稀的数据转换为紧而密的数据。本质是一种哈希算法**

**例子：不关注学生成绩，关注学生排名**

| 原数据               | **1000** | **500** | **9999** | **200** | **356** | **200** |
| -------------------- | :------------- | ------------- | -------------- | ------------- | ------------- | ------------- |
| **离散处理后** | **3**    | **2**   | **4**    | **0**   | **1**   | **0**   |

**一般流程：**

1. **创建原数组的副本。**
2. **将副本中的值从小到大排序。**
3. **将排序好的副本去重。**
4. **查找原数组的每一个元素在副本中的位置，位置即为排名，将其作为离散化后的值。**

```c++
//核心代码（采用vector容器）
std::vector<int> arr = {1000, 500, 9999, 200, 356, 200};
std::vector<int> tmp(arr);  // 创建副本
std::sort(tmp.begin(), tmp.end()); //对副本排序
tmp.erase(std::unique(tmp.begin(), tmp.end()), tmp.end());//去重
for (int i = 0; i < arr.size(); ++i)
    arr[i] = std::lower_bound(tmp.begin(), tmp.end(), arr[i]) - tmp.begin();
```

## 前缀和与差分·

### 一维形式

### 二维形式

### 三维形式

# 字符串

## KMP算法

**通过防止重复匹配，来解决暴力匹配, 时间复杂度最坏可达 $O(n^2)$ 的问题，使时间复杂度降到 $O(n)$ **

1. **求next数组（或称prefixTable前缀表），即子串对应的最长公共前后缀数组**

   ```c++
   //求next数组
   void prefixFunction(std::string s, int next[]) 
   {
     int n = (int)s.length();
     next[0] = 0;
     for (int i = 1; i < n; i++) 
     {
       int j = next[i - 1];    //获取前一个子串的最长公共前后缀
       //如果新增字符不能满足(一直寻找知道找到或者到j为0)
       while (j > 0 && s[i] != s[j])   j = next[j - 1];    //利用KMP和DP的思想
       if (s[i] == s[j])  j++;  //找到了就++赋值，没找到就直接为j(0)
       next[i] = j;
     }
   }
   ```

2. **进行字符串匹配**

   ```C++
   //字符串匹配
   std::vector<int> kmpSearch(const std::string str, const std::string substr, const int next[])
   {
       std::vector<int> res;
       for(int i = 0, j = 0; i < (int)str.size() - (int)substr.size() + 1; ++i)
       {
           if(j == (int)substr.size() - 1 && str[i] == substr[j]) //完全匹配
           {
               res.push_back(i - j);//记录匹配到子串起始位置
               j = next[j - 1];    
               continue;
           }
           if(str[i] == substr[j]) ++j;//匹配到一个字符就++
           else //没有匹配到就回到next[j - 1]位置
           {
               if(j != 0)  j = next[j - 1]; 
           }
       }
       return res; 
   }
   ```

# 栈

# 队列

# 树

## 线段树

**线段树可以在 $O(log n)$ 的时间复杂度内实现单点修改、区间修改、区间查询（区间求和，求区间最大值，求区间最小值)等操作。**

**线段树可以用树状数组来表示**

```C++
//构建线段树
void buildTree(int a[], int tree[], int node, int start, int end)//start和end表示区间[start, end]
{
    if(start == end)//当start等于end时  
    {
        tree[node] = a[start];//更新根节点
        return;//返回
    }
    else
    {
        int mid = (start + end)/2;//取中
        int leftNode = node * 2 + 1;//定位左节点
        int rightNode = node * 2 + 2;//定位右节点
        buildTree(a, tree, leftNode, start, mid);//计算左节点对应的线段和
        buildTree(a, tree, rightNode, mid + 1, end);//计算右节点对应的线段和
        tree[node] = tree[leftNode] + tree[rightNode];//更新根节点
    }
}
```

```C++
//修改线段树(index表示原数组要改值索引，val表示要改的值，即对a[index] = val;后的修改)
void updateTree(int a[], int tree[], int node, int start, int end, int index, int val)
{
    if(start == end)
    {
        tree[node] = val;//更新节点值
        return;
    }
    else
    {
        int mid = (start + end)/2;//取中
        int leftNode = node * 2 + 1;//定位左节点
        int rightNode = node * 2 + 2;//定位右节点
        if(index <= mid)
        {
            updateTree(a, tree, leftNode, start, mid, index, val);//向左查询
        }
        else
        {
             updateTree(a, tree, rightNode, mid + 1, end, index, val);//向右查询
        }
        tree[node] = tree[leftNode] + tree[rightNode];//更新节点
      
    }
}
```

```C
//查询线段树，即求区间和
int queryTree(int a[], int tree[], int node, int start, int end, int L, int R)//求[L, R]的区间和
{
    if(L <= start && R <= end)
    {
        return tree[node];
    }
    else if(R < start || L > end)
    {
        return 0;
    }
    else
    {
        int mid = (start + end) / 2;//取中间值
        int leftNode = node * 2 + 1;//定位左节点
        int rightNode = node * 2 + 2;//定位右节点
        int queryLeftTree = queryTree(a, tree, leftNode, start, mid, L, R);
        int queryRightTree = queryTree(a, tree, rightNode, mid + 1, end, L, R);
        return queryLeftTree + queryRightTree;
    }
}
```

# 图

## BFS广度优先搜索

**BFS的全称是Breadth-First Search，一般用queue实现**

```C++
//BFS算法（广度优先搜索）
std::map<char, std::vector<char>> graph = 
{
    {'A', {'B','C'}},
    {'B', {'A', 'C', 'D'}},
    {'C', {'A', 'B', 'D', 'E'}},
    {'D', {'B', 'C', 'E', 'F'}},
    {'E', {'C', 'D'}},
    {'F', {'D'}}
};

//对图graph进行搜索
//核心代码
void BFS(std::map<char, std::vector<char>> graph, char begin)
{
    std::queue<char> q;
    q.push(begin); // 将起始节点放入队列
    std::set<char> seen;//对已查找过的进行标记
    seen.insert(begin); // 将起始节点放入集合
    while(q.size() > 0)
    {
        char vertex = q.front();//取队首元素
        q.pop();//出队
        for(int i = 0; i < (int)graph[vertex].size(); ++i)
        {
            if(seen.find(graph[vertex][i]) == seen.end())//如果没有标记
            {
                q.push(graph[vertex][i]);//入队
                seen.insert(graph[vertex][i]);//进行标记
            }   
        }
        std::cout << vertex << " ";
    }
}
```

## DFS深度优先搜索

**BFS的全称是Depth-First Search，一般用stack实现**

```C++
//DFS算法（深度优先搜索）
std::map<char, std::vector<char>> graph = 
{
    {'A', {'B','C'}},
    {'B', {'A', 'C', 'D'}},
    {'C', {'A', 'B', 'D', 'E'}},
    {'D', {'B', 'C', 'E', 'F'}},
    {'E', {'C', 'D'}},
    {'F', {'D'}}
};
//对图graph进行搜索
//核心代码
std::map<char, char> DFS(std::map<char, std::vector<char>> graph, char begin)
{
    std::stack<char> s;
    s.push(begin); // 将起始节点放入栈
    std::set<char> seen;
    seen.insert(begin); // 将起始节点放入集合
    std::map<char, char> parents = {{begin, '0'}};
    while(s.size() > 0)
    {
        char vertex = s.top();
        s.pop();
        for(int i = 0; i < (int)graph[vertex].size(); ++i)
        {
            if(seen.find(graph[vertex][i]) == seen.end())
            {
                s.push(graph[vertex][i]);
                parents[graph[vertex][i]] = vertex;
                seen.insert(graph[vertex][i]);
            }
        }
        std::cout << vertex << " ";
    }
    return parents;//返回的是映射树(value是key的前一个结点)
}//映射树用于找狭义上的最短路（各个节点连线的距离相等）
```

## dijkstra最短路算法

**用途：解决带非负权图单源最短路问题**

**利用priority_queue优先队列来实现**

```c++
//dijkstra最短路算法
std::map<char, std::vector<std::pair<char, int>>> graph = 
{
    {'A', {{'B', 5}, {'C', 1}}},
    {'B', {{'A', 5}, {'C', 2}, {'D', 1}}},
    {'C', {{'A', 1}, {'B', 2}, {'D', 4}, {'E', 8}}},
    {'D', {{'B', 1}, {'C', 4}, {'E', 3}, {'F', 6}}},
    {'E', {{'C', 8}, {'D', 3}}},
    {'F', {{'D', 6}}}
};
//对图graph的两节点查找
//利用仿函数重载,用于比较pair，距离越小优先级越高
struct myCompare
{
    bool operator()(const std::pair<char, int>& a, const std::pair<char, int>& b) 
    {
        return a.second > b.second;
    }
};

int dijkstra(std::map<char, std::vector<std::pair<char, int>>> graph, char begin, char end)
{
    std::priority_queue<std::pair<char, int>, std::vector<std::pair<char, int>>, myCompare> pq;//创建优先队列
    pq.push(std::make_pair(begin, 0));//将首节点入队
    std::set<char> seen;//创建集合表示已经检查过的节点
    while(pq.size() > 0)
    {
        std::pair<char, int> vertex = pq.top();//取队首元素
        seen.insert(vertex.first);//进行标记
        pq.pop();//移除队列
        for(int i = 0; i < (int)graph[vertex.first].size(); ++i)
        {
            if(seen.find(graph[vertex.first][i].first) == seen.end())//没有被标记
                pq.push(std::make_pair(graph[vertex.first][i].first, graph[vertex.first][i].second + vertex.second));//入队
        }
        if(vertex.first == end) return vertex.second;
    }
    return INT_MAX;//没有找到
}
```

# 数论

## 素数判定

### 定义法

**利用素数的定义进行判定**

#### 定义判定

**遍历2到n-1；判断是否能被整除, 时间复杂度 $O(n^2)$ **

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

**遍历到sqrt()就可以，由于sqrt()计算较慢，可转化为i * i <=  n; 但可能导致越界，进入死循环，改为 `i <= n / i;`, 时间复杂度为$O(nlogn)$ **

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

**`bitset <nums> name;`类似于bool数组，默认值为0，详见[std::bitset - cppreference.com](https://zh.cppreference.com/w/cpp/utility/bitset)**

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

**不用再判断是否为素数，前面的素数已经判定过，并记录在bitset中,  时间复杂度 $O(nloglogn)$ **

**缺点：一个合数可能同时被两个素数筛**

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

**解决一个素数被两个素数筛掉，效率低的问题, 时间复杂度为 $O(n)$ **

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

## 快速幂

**快速幂，二进制取幂（Binary Exponentiation，也称平方法），是一个在 $O(logn)$ 的时间内计算 $a^n$ 的小技巧，而暴力的计算需要 $O(n)$ 的时间。**

### 数的快速幂

```C++
//核心代码
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
```

### 矩阵快速幂

**将快速幂的方法用于矩阵上，用于解决矩阵的一些问题，例如求斐波那契数列某项值**

```C++
//核心代码
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
```
