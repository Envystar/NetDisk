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

//添加到链表前端
void pushLinkedListFront(ListNode* &leftHead,int val)
{
	if(leftHead->left != nullptr) return;
	ListNode* newLeftHead = new ListNode(val, nullptr, leftHead);
	leftHead->left = newLeftHead;
	leftHead = newLeftHead;
}

//添加到链表右端
void pushLinkedListBack(ListNode* &rightHead,int val)
{
	if(rightHead->right != nullptr) return;
	ListNode* newRightHead = new ListNode(val, rightHead, nullptr);
	rightHead->right = newRightHead;
	rightHead = newRightHead;
}

//正向遍历输出
void printFromFront(ListNode* leftHead)
{
	if(leftHead->left != nullptr) return;
	while(leftHead != nullptr)
	{
		std::cout<< leftHead->val << " ";
		leftHead = leftHead->right;
	}
	std::cout << std::endl;
}

//反向遍历输出
void printFromBack(ListNode* rightHead)
{
	if(rightHead->right != nullptr) return;
	while(rightHead != nullptr)
	{
		std::cout<< rightHead->val << " ";
		rightHead = rightHead->left;
	}
	std::cout << std::endl;
}

int main()
{ 
    ListNode* leftNode = new ListNode(0);
	printFromBack(leftNode);
	printFromFront(leftNode);
	pushLinkedListFront(leftNode,10);
	printFromFront(leftNode);
	printFromBack()
	system("pause");
	return 0;	
}