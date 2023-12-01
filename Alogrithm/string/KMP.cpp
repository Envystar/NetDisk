#include <bits/stdc++.h>

//KMP字符串快速匹配算法

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

int main()
{
    std::string str = "babababa";
    std::string substr = "ab";
    int n = substr.size();
    int next[n];
    prefixFunction(substr, next);
    //for(int i = 0; i < n; ++i)  std::cout << next[i] << " ";
    std::vector<int> result = kmpSearch(str, substr, next);
    for(int i = 0; i < (int)result.size(); ++i) std::cout << result[i] << " "; 
    return 0;
}