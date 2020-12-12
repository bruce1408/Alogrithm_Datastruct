#include <iostream>
#include <vector>
using namespace std;

/**
 * 二叉查找树如果使用有序序列
 * 1，2，3，4，5 进行构建二叉查找树，那么可能出现的树是一颗链式的长度。所以为了防止
 * 1
 *  \ 
 *   2 
 *    \
 *     3
 *      \
 *       4
 *        \
 *         5
 * 这种情况，使用平衡二叉树来构建
*/
// struct node
// {
//     int data;
//     node *left;
//     node *right;
//     node(int x) : data(x), left(NULL), right(NULL) {}
// };

// void preorder(node *root)
// {
//     if (root == nullptr)
//         return;
//     preorder(root->left);
//     cout << root->data << " ";
//     preorder(root->right);
// }

// void insert(node *&root, int x)
// {
//     if (root == nullptr)
//     {
//         root = new node(x);
//         return;
//     }
//     if (root->data > x)
//     {
//         insert(root->left, x);
//     }
//     else
//     {
//         insert(root->right, x); // 这里其实包含了等于的情况，如果等于的话就在右子树上继续构建
//     }
// }

// int main()
// {
//     node *root = NULL; // 定义头结点
//     vector<int> res = {1, 2, 3, 4, 5};
//     for (int i = 0; i < res.size(); i++)
//     {
//         insert(root, res[i]);
//     }
//     preorder(root);
// }

struct node
{
    int val, height;
    node *left;
    node *right;
    node(int x) : val(x), height(0), left(NULL), right(NULL) {}
};

/**
 * 生成一个新节点，v是节点的权值
 * height是高度，起始高度设置为1
*/
node *newNode(int v)
{
    node *root = new node(x);
    root->height = 1;
    root->left = root->right = nullptr;
    return root;
}

/**
 * 得到节点的height高度
 * */
int getHeight(node *root)
{
    if (root == nullptr)
        return 0;
    return root->height;
}

/**
 * 计算root节点的平衡因子，
 * 左子树的高度减去右子树的高度，值为-1, 0, 1三种情况
*/
int getBalance(node *root)
{
    return getHeight(root->left) - getHeight(root->right); // 返回左子树高度减去右子树高度
}

/**
 * 更新root节点的高度height
*/
void updateHeight(node *root)
{
    root->height = max(getHeight(root->left->height), getHeight(root->right->height)) + 1;
}

/**
 * 平衡二叉树的基本操作
 * 查找、插入
*/
void search(node *root, int x)
{
    if (root == nullptr)
    {
        cout << "failed " << endl;
        return;
    }
    if (x == root->data)
    {
        cout << "finded" << endl;
    }
    else if (root->data > x)
    {
        search(root->right, x);
    }
    else
        search(root->left, x);
}

/**
 * 节点左旋；
 *      a
 *    /  \ 
 *   a1   b
 *       / \
 *     b1   b2
 * 1.让b的左子树成为a的右子树
 * 2.让a成为b的左子树
 * 3.将根节点设置为b
*/
void L(node *&root)
{
    node *temp = root->right; //
    root->right = temp->left;
    temp->left = root;
    updateHeight(root);
    updateHeight(temp);
    root = temp;
}
