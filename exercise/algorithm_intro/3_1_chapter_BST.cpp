#include <iostream>
#include <vector>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
    node(int x) : data(x), left(NULL), right(NULL) {}
};

/**
 * 二叉查找树插入操作
 * 这里不同的是，如果插入相同的数字，那么依然可以存在，而不是直接返回
*/
void insert(node *root, int x)
{
    if (root == NULL)
    {
        root = new node(x);
        return;
    }
    if (root->data > x)
    {
        insert(root->left, x);
    }
    else
        insert(root->right, x);
}

/**
 * 先序遍历结果保存到res数组中
*/
void preorder(node *root, vector<int> res)
{
    if (root == nullptr)
        return;
    res.push_back(root->data);
    preorder(root->left, res);
    preorder(root->right, res);
}

/**
 * 镜像树先序遍历，结果保存在res
 * 和上面正常二叉树先序遍历不同的是，这只要交换左右子树的位置
 * 即可
*/
void preorderMirror(node *root, vector<int> res)
{
    if (root == nullptr)
        return;
    res.push_back(root->data);
    preorderMirror(root->right, res);
    preorderMirror(root->left, res);
}

/**
 * 后序遍历结果保存到res中即可
*/
void posterorder(node *root, vector<int> res)
{
    if (root == nullptr)
        return;
    posterorder(root->left, res);
    posterorder(root->right, res);
    res.push_back(root->data);
}

/**
 * 镜像树的后序遍历，思路和先序一样
*/
void posterorderMirror(node *root, vector<int> res)
{
    if (root == nullptr)
        return;
    posterorderMirror(root->right, res);
    posterorderMirror(root->left, res);
    res.push_back(root->data);
}

/**
 * 
*/
int main()
{
}