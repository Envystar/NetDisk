#include <iostream>
#include <queue>

class BSTNode
{
public:
    BSTNode(int v = int(), BSTNode* l = nullptr, BSTNode* r = nullptr) : val(v), left(l), right(r){};
    int val;
    BSTNode* left;
    BSTNode* right;
};

//插入节点
BSTNode* insert(BSTNode* root, int val)
{
    if(root == nullptr)         root = new BSTNode(val);
    else if(val <= root->val)   root->left = insert(root->left, val);
    else if(val > root->val)    root->right = insert(root->right, val);
    return root;
}

//搜索数据
bool search(BSTNode* root, int val)
{
    if(root == nullptr) return false;
    if(root->val == val)    return true;
    else if(root->val <= val)   return search(root->right, val);
    else    return search(root->left, val); 
}

//找最小值
BSTNode* findMin(BSTNode* root)
{
    if(root == NULL) return root;
    while(root->left != nullptr)
    {
        root = root->left;
    }
    return root;
}

//找最大值
BSTNode* findMax(BSTNode* root)
{
    if(root == NULL) return root;
    while(root->right != nullptr)
    {
        root = root->right;
    }
    return root;
}

//获取树的高度
int findHeight(BSTNode* root)
{
    if(root == nullptr) return -1;
    int leftHeight = findHeight(root->left);
    int rightHeight = findHeight(root->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

//广度优先遍历
void printTree(BSTNode* root)
{
    if(root == nullptr) return;
    std::queue<BSTNode*> q;
    q.push(root);
    while(!q.empty())
    {
        if(q.front()->left != nullptr)  q.push(q.front()->left);
        if(q.front()->right != nullptr) q.push(q.front()->right);
        std::cout << q.front()->val << " ";
        q.pop();
    }
}

//深度优先
//树的前序遍历
void printPreorder(BSTNode* root)
{
    if(root == nullptr) return;
    std::cout << root->val << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

//树的中序遍历
void printFixorder(BSTNode* root)
{
    if(root == nullptr) return;
    printFixorder(root->left);
    std::cout << root->val << " ";
    printFixorder(root->right);
}

//树的后序遍历
void printPostorder(BSTNode* root)
{
    if(root == nullptr) return;
    printPostorder(root->left);
    printPostorder(root->right);
    std::cout << root->val << " ";
}

//删除节点
BSTNode* deleteNode(BSTNode* root, int val)
{
    if(root == nullptr) return root;
    if(val < root->val)         deleteNode(root->left, val);
    else if(val > root->val)    deleteNode(root->right, val);
    else if(val == root->val)
    {
        if(root->left == nullptr && root->right == nullptr)//没有子树
        {
            delete root;
            root = nullptr;
        }
        else if(root->left == nullptr)//有右子树
        {
            BSTNode* temp = root->right;
            delete root;
            root = temp;
        }
        else if(root->right == nullptr)//有左子树
        {
            BSTNode* temp = root->left;
            delete root;
            root = temp;
        }
        else//有两个子树
        {
            BSTNode* temp = findMin(root->right);
            root->val = temp->val;
            root->right = deleteNode(root->right, temp->val);
        }
    }
    return root;
}

//树的中序后继节点
int getSuccessor(BSTNode* root, int val)
{
    
    BSTNode* temp = root;
    while(root != nullptr)
    {
        if(root->val < val)         
        {   
            temp = root;    
            root = root->right;
        }
        else if(root->val > val)
        {   
            temp = root;    
            root = root->left;
        }
        else if(root->val == val && root->right != nullptr) return findMin(root->right)->val;
        else if(root->val == val && root->right == nullptr) return temp->val;
    }
    return INT_MAX; 
}

//是否是BST
bool isBST(BSTNode* root)
{
    if(root == nullptr) return true;
    if((root->left == nullptr || root->val >= root->left->val) 
        && (root->right == nullptr || root->right->val > root->val))
        return isBST(root->left) && isBST(root->right); 
    else     return false;
}
int main()
{
    BSTNode* root = nullptr;
    root = insert(root, 10);
    root = insert(root, 100);
    root = insert(root, 3);
    root = insert(root, 2);
    root = insert(root, 5);
    root = deleteNode(root, 3);
    std::cout << getSuccessor(root, 10) << "\n";
    system("pause");
    return 0;
}