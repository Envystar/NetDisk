#include <bits/stdc++.h>

//BFS算法（广度优先搜索）
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

int main()
{
    std::map<char, std::vector<char>> graph = 
    {
        {'A', {'B','C'}},
        {'B', {'A', 'C', 'D'}},
        {'C', {'A', 'B', 'D', 'E'}},
        {'D', {'B', 'C', 'E', 'F'}},
        {'E', {'C', 'D'}},
        {'F', {'D'}}
    };
    BFS(graph, 'E');
    return 0;
}