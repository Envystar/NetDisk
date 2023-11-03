#include <iostream>

template<class T>
class Queue
{
public:
    Queue(): m_Front(new ListNode(T(), nullptr, this->m_Back)), m_Back(new ListNode(T(), this->m_Front, nullptr)), m_Size(0){};

    //访问第一个元素
    T front()
    {
        return this->m_Front->next->val;
    }

    //访问最后一个元素
    T back()
    {
        return this->m_Back->prev->val;
    }

    //返回容纳的元素数
    int size()
    {
        return this->m_Size;
    }

    //删除首个元素
    void pop()
    {
        if(this->m_Front->next == this->m_Back) return;
        ListNode* temp = this->m_Front->next;
        this->m_Front->next->next->prev = this->m_Front;
        this->m_Front->next = this->m_Front->next->next;
        delete temp;
        --this->m_Size;
    }

    //判断队列是否为空
    bool empty()
    {
        return this->m_Size == 0;
    }

    //向队列尾部插入元素
    void push(const T val)
    {
        ListNode* newNode = new ListNode(val, this->m_Back->prev, this->m_Back);
        this->m_Back->prev->next = newNode;
        this->m_Back->prev = newNode;
        ++this->m_Size;
    }

private:
    class ListNode
    {
    public:
        ListNode(T v, ListNode* p = nullptr, ListNode* n = nullptr) : val(v), prev(p), next(n){};//有参构造
        ListNode(){};//默认构造
        int val;
        ListNode* prev;
        ListNode* next;
    };
    ListNode* m_Front;
    ListNode* m_Back;
    int m_Size;
};

int main()
{
    Queue<int> q;
    q.push(10);
    q.push(20);
    q.pop();
    q.push(30);
    std::cout << q.front() << q.back();
    q.pop();
    std::cout << q.empty();
    system("pause");
    return 0;
}