#include <iostream>
#include <string>
#include <stack>

//判断否为操作符
bool isOperator(char ch)
{
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

//操作符运算
int performOperation(const char ch, const int a, const int b)
{
    switch(ch)
    {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        default : return 0;
    }
}

//前缀表达式运算
int evaluationPostfixExpression(const std::string str)
{
    std::stack<int> s;
    std::string temp;
    for(int i = str.length() - 1; i >= 0; i--)
    {
        if(str[i] != ' ' && !isOperator(str[i]))
        {
            temp = str[i] + temp;
        }
        else if(str[i] == ' ' && !isOperator(str[i + 1]) )
        {
            s.push(stoi(temp));
            temp = "";
        }
        else if(isOperator(str[i]))
        {
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();
            s.push(performOperation(str[i], a, b));
        }
    }
    return s.top();
}

int main()
{
    std::string s = "/ 100 * 2 + + 10 12 + 1 2";//100 / (2 * ((10 + 12) + (1 + 2)))
    std::cout << evaluationPostfixExpression(s);
    system("pause");
    return 0;
}