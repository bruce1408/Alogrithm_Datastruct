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

void insert(node *root, int x)
{
    if (root == NULL)
    {
        root = new node(x);
        return;
    }
}
int main()
{
}