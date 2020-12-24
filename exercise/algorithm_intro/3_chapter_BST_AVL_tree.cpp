#include <iostream>
#include <vector>
using namespace std;

/**
 * 二叉查找树如果使用有序序列那么构建的树就是单链式的，插入查找低效
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
    int data, height;
    node *left;
    node *right;
    node(int x) : data(x), height(0), left(NULL), right(NULL) {}
};

/**
 * 生成一个新节点，v是节点的权值
 * height是高度，设置起始的高度设置为1
*/
node *newNode(int x)
{
    node *root = new node(x);
    root->height = 1;
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
 * 更新root节点的高度height, 当前节点的左子树和右子树的高度的较大的那一个然后+1
*/
void updateHeight(node *root)
{
    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
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
 * 1.让b的左树b1成为a的右子树
 * 2.让a成为b的左子树
 * 3.将根节点设置为b
*/
void L(node *&root)
{
    node *temp = root->right; // root 指向节点a, temp 指向节点b
    root->right = temp->left;
    temp->left = root;
    updateHeight(root); // 更新a节点的高度
    updateHeight(temp); // 更新b节点的高度
    root = temp;
}

/**
 * 节点右旋；
 *       b
 *     /  \ 
 *    a    b1
 *   / \
 * a1   a2
 * 1.让a的右树a2成为b的左子树
 * 2.让b成为a的左子树
 * 3.将根节点设置为a
*/
void R(node *&root)
{
    node *temp = root->left;
    root->left = temp->right;
    temp->right = root;
    updateHeight(root);
    updateHeight(temp);
    root = temp;
}

/**
 * 对比左旋和右旋代码发现，两组代码只不过是把代码中的出现的left变成right，right变成left
 * 所以左旋操作和右旋操作就是对称的，互为逆操作
 * 
 * 在对二叉树进行插入元素的时候，一定会发生平衡因子的变化，此时的平衡因子可能大于1，这样该节点为根节点的子树就是
 * 失衡的，需要调整，那么已经证明：
 * 只要把最靠近插入节点的失衡节点调整到正常，路径上的所有节点都会平衡；
 * 
 * 如果是LL LR 或者是 RR RL 两种情况：
 * LL情况的话，以a作为根节点进行右旋，
 * LR情况的话，以c作为根节点进行左旋，转化为LL，然后在把a作为根节点进行右旋
 * 
 * RR情况的话，以a作为根节点进行左旋
 * RL情况的话，以c作为根节点进行右旋，转化为RR，然后再把a作为根节点进行左旋
 * 
 * bf表示平衡影子
 * 树型         判断条件                              调整方法
 * -----------------------------------------------------------------------------
 * LL   bf(root)=3-1=2, bf(root->left)=2-1=1      对root右旋
 * -----------------------------------------------------------------------------
 * LR   bf(root)=3-1=2, bf(root->left)=1-2=-1     对root->left左旋，然后对root右旋  
 * -----------------------------------------------------------------------------
 * RR   bf(root)=1-3=-1, bf(root->right)=-1       对root左旋
 * -----------------------------------------------------------------------------
 * RL   bf(root)=1-3=-2, bf(root->right)=1        对root->right右旋，然后root左旋
 * -----------------------------------------------------------------------------
 * */

/**
 * 平衡二叉查找树的插入
 * 在插入新节点之后还需要从插入的节点开始从下往上判断节点是否失衡，
 * 因此在insert之后更新当前子树的高度，并在这之后根据树型是LL、LR、RR、RL进行平衡操作
*/

void insert(node *&root, int x)
{
    if (root == nullptr)
    {
        root = newNode(x);
        return;
    }
    if (root->data > x) // 当前节点的值大于插入节点的数字
    {
        insert(root->left, x);
        updateHeight(root);        // 更新树高
        if (getBalance(root) == 2) // 当前节点的平衡因子是2，那么可能是LL或者LR的情况
        {
            if (getBalance(root->left) == 1) // 这个是LL的情况
            {
                R(root);
            }
            else if (getBalance(root->left) == -1) // 这个是LR的情况
            {
                L(root->left);
                R(root);
            }
        }
    }
    else // 当前节点的值小于插入节点的数字
    {
        insert(root->right, x); // 右子树插入
        updateHeight(root);     // 更新树高
        if (getBalance(root) == -2)
        {
            if (getBalance(root->right) == -1) // RR型
            {
                L(root);
            }
            else if (getBalance(root->right) == 1) // RL型
            {
                R(root->right);
                L(root);
            }
        }
    }
}

node *create(vector<int> &res)
{
    node *root = nullptr;
    for (int i = 0; i < res.size(); i++)
    {
        insert(root, res[i]);
    }
    return root;
}

void preorder(node *root)
{
    if (root == nullptr)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int main()
{
    vector<int> res = {1, 2, 3, 4};
    node *root = create(res);
    preorder(root);
}