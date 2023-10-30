#include <iostream>

class ListNode
{
public:
    ListNode(int v, ListNode* nex = nullptr) : val(v), next(nex){};
    int val;
    ListNode * next;
};

//添加节点
void addNode(ListNode * &head, int val)
{
    ListNode* newHead = new ListNode(val, head);
    head = newHead;
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

//反转链表
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

//反向打印链表（递归）
void printReserveLinkedList(ListNode* head)
{
    if(head == nullptr) return;
    printLinkedList(head->next);
    std::cout << head->val;
}

int main()
{
    ListNode* head = new ListNode(0);
    printLinkedList(head);

    addNode(head, 2);
    printLinkedList(head);

    reverseLinkedList(head);
    printLinkedList(head);

    printReserveLinkedList(head);
    system("pause");
    return 0;
}