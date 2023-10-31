#include <iostream>

class TreeNode()
{
public:
    TreeNode(int v, TreeNode* l = nullptr, TreeNode* r = nullptr) : val(v), left(l), right(r){};
    int val;
    TreeNode* left;
    TreeNode* right;
}


int main()
{
    system("pause");
}