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

void preorder(node *root)
{
    if (root == nullptr)
        return;
    preorder(root->left);
    cout << root->data << " ";
    preorder(root->right);
}

void insert(node *&root, int x)
{
    if (root == nullptr)
    {
        root = new node(x);
        return;
    }
    if (root->data > x)
    {
        insert(root->left, x);
    }
    else
    {
        insert(root->right, x); // 这里其实包含了等于的情况，如果等于的话就在右子树上继续构建
    }
}

int main()
{
    node *root = NULL; // 定义头结点
    vector<int> res = {1, 2, 3, 4, 5};
    for (int i = 0; i < res.size(); i++)
    {
        insert(root, res[i]);
    }
    preorder(root);
}