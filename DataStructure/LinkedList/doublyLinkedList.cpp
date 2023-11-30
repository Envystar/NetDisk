#include <iostream>

class ListNode
{
public:
	ListNode(int v, ListNode* l = nullptr, ListNode* r = nullptr) : val(v), left(l), right(r){};//有参构造
	ListNode(){};//默认构造
	int val;
	ListNode* left;
	ListNode* right;
};

class DoubleLinkedList
{
public:
	DoubleLinkedList()
	{
		this->m_LeftHead = new ListNode;
		this->m_RightHead = new ListNode;
		this->m_LeftHead->left = this->m_RightHead;
		this->m_LeftHead->right = this->m_RightHead;
		this->m_RightHead->left = this->m_LeftHead;
		this->m_RightHead->right = this->m_LeftHead;
		this->m_NodeNum = -1;
	}

	//重载运算符[]
	int& operator[](int index)
	{
		ListNode* temp = this->m_LeftHead; 
		for(int i = 0; i <= index; ++i)
		{
			temp = temp->right;
		}
		return temp->val;
	}

	//添加到链表前端
	void pushLinkedListFront(int val)
	{
		ListNode* newLeftHead = new ListNode(val, this->m_LeftHead, this->m_LeftHead->right);
		this->m_LeftHead->right->left = newLeftHead;
		this->m_LeftHead->right = newLeftHead;
		this->m_NodeNum++;
	}

	//添加到链表右端
	void pushLinkedListBack(int val)
	{
		ListNode* newRightHead = new ListNode(val, this->m_RightHead->left, this->m_RightHead);
		this->m_RightHead->left->right = newRightHead;
		this->m_RightHead->left = newRightHead;
		this->m_NodeNum++;
	}

	//正向遍历输出
	void printFromFront()
	{
		ListNode* temp = this->m_LeftHead->right; 
		for(int i = 0; i <= this->m_NodeNum; ++i)
		{
			std::cout<< temp->val << " ";
			temp = temp->right;
		}
		std::cout << std::endl;
	}

	//反向遍历输出
	void printFromBack()
	{
		ListNode* temp = this->m_RightHead->left; 
		for(int i = 0; i <= this->m_NodeNum; ++i)
		{
			std::cout<< temp->val << " ";
			temp = temp->left;
		}
		std::cout << std::endl;
	}

private:
	ListNode* m_LeftHead;
	ListNode* m_RightHead;
	int m_NodeNum;
};



int main()
{ 
    DoubleLinkedList linkedlist;
	linkedlist.pushLinkedListFront(100);
	linkedlist[0] = 50;
	linkedlist.pushLinkedListFront(400);
	linkedlist.printFromFront();
	linkedlist.printFromBack();
	linkedlist.pushLinkedListFront(200);
	linkedlist.pushLinkedListBack(300);
	linkedlist.printFromFront();
	linkedlist.printFromBack();
	
	system("pause");
	return 0;	
}