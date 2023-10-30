#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

bool canConstruct(std::string ransomNote, std::string magazine) {
    unordered_map<char, int> r;
    unordered_map<char, int> m;
    for(int i = 0; i < ransomNote.length(); i++)
    {
        if(r.find(ransomNote[i]) == r.end())     r.insert(make_pair(ransomNote[i], 1));
        else     r[ransomNote[i]]++;
    }

    for(int i = 0; i < magazine.length(); i++)
    {
        if(m.find(magazine[i]) == m.end())      m.insert(make_pair(magazine[i], 1));
        else    m[magazine[i]]++;
    }

    for(auto it = r.begin(); it != r.end(); it++)
    {
        if(m.find(it->first) == m.end() || m[it->first] < it->second)
        {
            return false;
        }
    }
    return true;
}

int main()
{ 
    std::cout << canConstruct("a", "b");
	system("pause");
	return 0;	
}