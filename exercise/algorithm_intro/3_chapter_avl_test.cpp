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

node *insert(node *&root, int x)
{
    if(root==nullptr)
    {
        node * root = newNode(x);
    }
    if(root->val > x)
    {
        insert(root->left, x);
    }
    else
    {
        insert(root->right, x);
    }
    return root;
}

void L(node*root)
{

}

void R(node*root)
{
    
}

int main()
{

}