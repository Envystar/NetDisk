#include <iostream>
#include <string>
#include <stack>

//检查括号的匹配性 
bool checkForBalancedParenthese(std::string str)
{
    std::stack<char> s;
    for(int i = 0; i < str.length(); i++)
    {
        if(str[i] == '{' || str[i] == '[' || str[i] == '(')
        {
            s.push(str[i]);
        }
        else if(str[i] == '}' || str[i] == ']' || str[i] == ')')
        {
            if(s.empty())
            {
                return false;
            } 
            else if((str[i] == '}' && s.top() == '{') || (str[i] == ']' && s.top() == '[') || (str[i] == ')' && s.top() == '('))
            {    
                s.pop();
            }
            else
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    std::string s = "[{[(aoafjaejg)]}]";
    std::cout << checkForBalancedParenthese(s);
    system("pause");
    return 0;
}
