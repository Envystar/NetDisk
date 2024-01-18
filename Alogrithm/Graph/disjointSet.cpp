#include <bits/stdc++.h>
#define VERTICES 6//顶点数 

//并查集

//初始化数组
void initialise(int parent[]){
    for(int i = 0; i < VERTICES; ++i){
        parent[i] = -1;
    }
}

//寻找根节点
int findRoot(int x, int parent[]){
    while(parent[x] >= 0)
    {
        x = parent[x];
    }
    return x;
}

//合并集合
int unionVertices(int x, int y, int parent[])
{
    int xRoot = findRoot(x, parent);
    int yRoot = findRoot(y, parent);
    if(xRoot != yRoot){
        if(parent[xRoot] <= parent[yRoot]){
            if(parent[xRoot] == parent[yRoot])
            {
                --parent[xRoot];
            }
            parent[yRoot] = xRoot;
        }
        if(parent[xRoot] > parent[yRoot]){
            parent[xRoot] = yRoot;
        }
        
        return 1;
    }
    else{
        return 0;
    }
}

int main()
{
    int parent[VERTICES] = {0};
    int edges[6][2] = {
        {0, 1}, {5, 4}, {1, 3},
        {1, 2}, {3, 4}, {5, 2},
    };
    initialise(parent);
    for(int i = 0; i < 6; ++i){
        int x = edges[i][0];
        int y = edges[i][1];
        if(!unionVertices(x, y, parent)){
            std::cout << "Cycle dectected!\n";
            return 0;
        }
        for(int j = 0; j < VERTICES; ++j){
            std::cout << parent[j] << ' ';
        }
        std::cout << '\n';
    }
    std::cout << "No cycles found.\n";
    return 0;
} 