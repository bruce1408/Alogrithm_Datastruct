#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct node
{
    int val, height;
    node *left, *right;
    node(int x) : val(x), height(0), left(NULL), right(NULL) {}
};

node *newNode(int x)
{

    node *root = new node(x);
    root->height = 1;
    root->left = root->right = nullptr;
    return node;
}

void getHeight(node *root)
{
    if (root == nullptr)
        return 0;
    return root->height;
}

// 更新树的高度
void updateHeight(node *root)
{
    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
}

// 右旋的情况适用于LL或者LR
void R(node *root)
{
    node *temp = root->left;
    root->left = temp->right;
    temp->right = root;
    updateHeight(root);
    updateHeight(temp);
    root = temp;
}

// 左旋的情况适用于RR或者是RL
void L(node *root)
{
    node *temp = root->right;
    root->right = temp->left;
    temp->left = root;
    updateHeight(root);
    updateHeight(temp);
    root = temp;
}

void insert(node*root, int x)
{
    if(root==nullptr)
    {
        root = newNode(x);
        return ;
    }
    if(root->data >x)
    {
        
    }
    else
    {
        
    }
    
}

int main()
{
    
}