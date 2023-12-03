#include <bits/stdc++.h>

//dijkstra最短路算法
struct myCompare//利用仿函数重载,用于比较pair，距离越小优先级越高
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

int main()
{
    std::map<char, std::vector<std::pair<char, int>>> graph = 
    {
        {'A', {{'B', 5}, {'C', 1}}},
        {'B', {{'A', 5}, {'C', 2}, {'D', 1}}},
        {'C', {{'A', 1}, {'B', 2}, {'D', 4}, {'E', 8}}},
        {'D', {{'B', 1}, {'C', 4}, {'E', 3}, {'F', 6}}},
        {'E', {{'C', 8}, {'D', 3}}},
        {'F', {{'D', 6}}}
    };

    std::cout << dijkstra(graph, 'F', 'A');
    return 0;
}