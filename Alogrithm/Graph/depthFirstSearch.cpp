#include <bits/stdc++.h>


//DFS算法（深度优先搜索）
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
    return parents;//返回的是树value是key的前一个结点
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
    std::map<char, char> parents = DFS(graph, 'E');
    for(auto it = parents.begin(); it != parents.end(); ++it)
    {
        std::cout << it->first << " " << it->second << std::endl;
    }
    char v = 'B';
    while(v != '0')
    {
        std::cout << v << " ";
        v = parents[v];
    }
    return 0;
}
