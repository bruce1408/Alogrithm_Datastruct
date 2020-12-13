#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct node
{
    int val, height;
    node *left, *right;
    node(int x):val(x), height(0),left(NULL), right(NULL) {}
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
    if(root==nullptr) return 0;
    return root->height;
}

void updateHeight(node*root)
{
    
    
}
// 右旋的情况适用于LL或者LR
void R(node*root)
{
    node*temp = root->left;
    root->left = temp->right;
    temp->right = root;
    


}

// 左旋
void L(node*root)
{

}

int main()
{

}