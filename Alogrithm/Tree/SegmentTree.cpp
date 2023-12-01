#include <bits/stdc++.h>
#define MAX_LEN 1000//定义树的大小
//线段树（树状数组）

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

//修改线段树
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

//查询线段树，即求区间和
int queryTree(int a[], int tree[], int node, int start, int end, int L, int R)//求[L, R]的区间和
{
    if(L == start && R == end)
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
        int queryLeftTree = queryTree(a, tree, leftNode, start, mid, L, mid);
        int queryRightTree = queryTree(a, tree, rightNode, mid + 1, end, mid + 1, R);
        return queryLeftTree + queryRightTree;
    }
}

int main()
{
    int a[] = {1, 3, 5, 7, 9, 11};
    int n = sizeof(a)/sizeof(int);
    int tree[MAX_LEN] = {0};
    
    buildTree(a, tree, 0, 0, n - 1);
    for(int i = 0; i < 15; ++i)     std::cout << tree[i] << " ";

    std::cout << '\n';
    std::cout << queryTree(a, tree, 0, 0, n - 1, 1, 5);
    std::cout << '\n';
    
    updateTree(a, tree, 0, 0, n - 1, 4, 6);
    for(int i = 0; i < 15; ++i)     std::cout << tree[i] << " ";
    
    return 0;
}