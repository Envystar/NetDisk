#include <iostream>

class ListNode
{
public:
    ListNode(int v, ListNode* nex = nullptr) : val(v), next(nex){};//有参构造
    ListNode(){};//默认构造
    int val;
    ListNode *next;
};

//添加节点
void addNode(ListNode * &head, int val)
{
    ListNode* newHead = new ListNode(val, head);
    head = newHead;
}

//在任意位置添加节点
void addNode(ListNode *&head, int pos, int val)
{
    if(pos == 0)
    {
        addNode(head, val);
        return;
    }
    else
    {
        int temp = 1;
        ListNode* index = head;
        while(index != nullptr && temp < pos)//遍历到所在位置的前一个位置
        {
            ++temp;
            index = index->next;
        }

        if(index == nullptr)    return;//指定节点错误，直接返回
        else
        {
            ListNode* newNode = new ListNode(val, index->next);//创建新节点
            index->next = newNode;//指向新节点
        }

    }  
}

//打印链表
void printLinkedList(ListNode* head)
{
    while(head != nullptr)
    {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

//反转链表（迭代）
void reverseLinkedList(ListNode* &head)
{
    ListNode* temp = nullptr;
    while(head!= nullptr)
    {
        ListNode* temp1 = head->next;
        head->next = temp;
        temp = head;
        head = temp1;
    }
    head = temp;
}

//反转链表（递归）
ListNode* reverseList(ListNode* &head)
{
    if(head->next == nullptr) return head;
    ListNode* newHead = reverseList(head->next);
    head->next->next = head;
    head->next = nullptr;
    return newHead;
}

//反向打印链表（递归）
void printReserveLinkedList(ListNode* head)
{
    if(head->next == nullptr) std::cout << head->val;
    printLinkedList(head->next);
    std::cout << head->val;
}

int main()
{
    ListNode* head = new ListNode(0);
    addNode(head, 2);
    addNode(head, 3);
    addNode(head, 3, 5);
    printLinkedList(head);
    system("pause");
    return 0;
}