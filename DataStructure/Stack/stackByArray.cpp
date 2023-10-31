#include <iostream>

template<class T>
class Stack
{
public:
    Stack(): m_Array(new T[10]), m_Top(-1), m_Size(10) {};

    //返回栈顶
    T top()
    {
        return m_Array[m_Top];
    }

    //入栈
    void push(T val)
    {
        if(this->m_Top != this->m_Size - 1)
        {
            this->m_Array[++this->m_Top] = val;
        }
        else if(this->m_Top == this->m_Size - 1)
        {
            T* temp = new T[2 * m_Size];
            for(int i = 0; i < this->m_Size; i++)
            {
                temp[i] = this->m_Array[i];
            }
            temp[++this->m_Top] = val;
            delete[] this->m_Array;
            this->m_Array = temp;
        }
    }

    //出栈
    void pop()
    {
        if(this->m_Top == -1) return;
        else --this->m_Top;
    }

    //判断栈是否为空
    bool empty()
    {
        return this->m_Top == -1;
    }

private:
    int m_Top;
    int m_Size;
    T* m_Array;
};

int main()
{
    
    Stack<int> s;
    s.push(123);
    std::cout << s.top() << std::endl;
    system("pause");
    return 0;
}