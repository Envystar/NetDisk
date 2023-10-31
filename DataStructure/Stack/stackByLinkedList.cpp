#include <iostream>

template<class T>
class Stack
{
public:
    
    //默认构造函数
    Stack():m_Head(NULL){};

    //返回栈顶
    T top()
    {
        return this->m_Head->val;
    }

    //入栈
    void push(T v)
    {
        if(this->m_Head == NULL) return;
        ListNode* newHead = new ListNode(v, m_Head);
        this->m_Head = newHead;
    }
    
    //出栈
    void pop()
    {
        if(this->m_Head == NULL) return;
        ListNode* temp = this->m_Head;
        this->m_Head = this->m_Head->next;
        delete temp;
    }

    bool empty()
    {
        return this->m_Head == NULL;
    }
//private:
    //链表节点
    class ListNode
    {
    public:
        ListNode(T v, ListNode* nex = NULL): val(v), next(nex){}
        ListNode(){};
        T val;
        ListNode* next;
    };
    ListNode* m_Head;
};


int main()
{
    Stack<int> s;
    s.pop();
    std::cout << s.empty();
    s.push(10);
    std::cout << s.empty();
    s.pop();
    s.pop();
    s.pop();
    system("pause");
    return 0;
}