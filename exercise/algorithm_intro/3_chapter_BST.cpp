#include <iostream>
#include <vector>
using namespace std;
/**
 * 二叉查找树BST介绍
 * 性质：
 * 左节点小于或者等于根节点
 * 右节点大于根节点
 * 按照二叉树中序遍历的话是一个有序的数组
*/
struct node
{
    int val;
    node *left;
    node *right;
    node(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * 二叉树的查找
*/
void search(node *root, int x)
{
    if (root == nullptr)
        return;
    if (x == root->val)
    {
        cout << "find :" << root->val << endl;
    }
    else if (x < root->val) // 小于根节点，那么在左边插入
    {
        search(root->left, x);
    }
    else // 大于根节点，右边插入
    {
        search(root->right, x);
    }
}

/**
 * 二叉查找树节点的插入
 * */
void insert(node *&root, int x) // 这里函数在二叉树中插入一个数据域为x的节点，root要加上引用
{
    if (root == nullptr) // 如果是空节点，查找失败，当前位置也是插入位置
    {
        root = new node(x);
        return;
    }
    if (x == root->val)
    {
        return; // 说明这个节点已经存在，不需要插入
    }
    else if (x > root->val) // 如果这个数大于根节点，说明应该在右节点插入
    {
        insert(root->right, x);
    }
    else
        insert(root->left, x);
}

/**
 * 二叉查找树的建立
*/
node *create(vector<int> &res)
{
    node *root = nullptr;
    for (int i = 0; i < res.size(); i++)
    {
        insert(root, res[i]);
    }
    return root;
}

/**
 * 二叉查找树后继节点查找，查找的是最右子树节点
 */
node *findMax(node *root)
{
    while (root->right != nullptr)
    {
        root = root->right; // 不断往右，然后找到最后的那个节点
    }
    return root;
}

/**
 * 二叉查找树前驱结点查找，找到的是最左子树节点
*/
node *findMin(node *root)
{
    while (root->left != nullptr)
    {
        root = root->left;
    }
    return root;
}

/**
 * 二叉查找树的中序遍历；
*/
void inorder(node *root)
{
    if (root == nullptr)
        return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

/**
 * 二叉查找树删除值为x的某个节点
*/
void deleteNode(node *&root, int x)
{
    if (root == nullptr) // 如果这节点空直接返回
        return;
    if (root->val == x) // 找到要删除的节点
    {
        if (root->left == NULL && root->rchild == nullptr) // 左右叶子节点都不存在，直接删除
            root = nullptr;
        else if(root->left !=nullptr) // 删除的这个节点的左子树不为空节点
        {
            node *pre = findMax(root->left); // 找到这个节点的前驱节点，就是左子树的最右节点，比这个节点小的最大节点
            root->val = pre->val;
            deleteNode(root->left, pre->val);
        }

    }
}
int main()
{
    vector<int> res = {5, 3, 7, 4, 2, 8, 6};
    inorder(create(res));
    cout << endl;
    cout << findMax(create(res))->val << endl;
    cout << findMin(create(res))->val << endl;
}