#include <iostream>
#include <vector>
using namespace std;
/**
 * 给定一个数组，然后按照数组顺序进行二叉查找树的构建，构建完毕之后看这个树的先序遍历结果或是镜像树的先序遍历结果
 * 是否等于这个原数组，如果等于的话，那么输出它的后序遍历数组或者是镜像树的后序遍历数组
 * 如果不等于的话，那么就直接输出No结束
 * 
 * 比如数组输入的是 8 6 5 7 10 8 11
 * 那么按照这个顺序构造的二叉查找树的先序遍历结果和他相同，所以输出后序遍历结果就可以
 * 否则输出No
*/
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
void insert(node *&root, int x)
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
void preorder(node *root, vector<int> &res)
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
void preorderMirror(node *root, vector<int> &res)
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
void posterorder(node *root, vector<int> &res)
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
void posterorderMirror(node *root, vector<int> &res)
{
    if (root == nullptr)
        return;
    posterorderMirror(root->right, res);
    posterorderMirror(root->left, res);
    res.push_back(root->data);
}

vector<int> pre, preM, post, postM;

int main()
{
    // int n, data;
    node *root = NULL;
    // cin >> n;
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> data;
    //     origin.push_back(data); // 数据保存到origin数组
    //     insert(root, data);     // 构建一个二叉查找树
    // }
    vector<int> origin = {8, 6, 5, 7, 10, 8, 11};
    int n = 7;
    for (int i = 0; i < n; i++)
    {
        insert(root, origin[i]); // 构建一个二叉查找树
    }

    preorder(root, pre);
    preorderMirror(root, preM);
    posterorder(root, post);
    posterorderMirror(root, postM);

    if (origin == pre)
    {
        cout << "Yes" << endl;
        for (auto i : post)
            cout << i << " ";
    }
    else if (origin == preM)
    {
        cout << "Yes" << endl;
        for (auto i : postM)
            cout << i << " ";
    }
    else
        cout << "No" << endl;
}