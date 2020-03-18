
/* --------------------------大话数据结构上面的树的实现原理复现-----------------*/
/*---------------------- 二叉树的创建以及前序、中序、后序遍历算法！--------------------*/
// #include<iostream>
// using namespace std;

// //定义节点
// typedef struct node
// {
    // struct node *lchild;
    // struct node *rchild;
    // char data;
// }BiTreeNode, *BiTree;
// //*BiTree的意思是给 struct node*起了个别名，
// //叫BiTree，故BiTree为指向节点的指针。


// //按照前序顺序建立二叉树
// void createBiTree(BiTree &T) 
// //&的意思是传进来节点指针的引用，括号内等价于 BiTreeNode* &T,
// //目的是让传递进来的指针发生改变
// {
	// char c;
	// cin >> c;
    // if('#' == c)             
		// //当遇到#时，令树的根节点为NULL，从而结束该分支的递归
        // T = NULL;
    // else
    // {
        // T = new BiTreeNode;// 新建一个节点，
        // T->data=c;
        // createBiTree(T->lchild);
        // createBiTree(T->rchild);
    // }
// }

// //前序遍历二叉树并打印
// void preTraverse(BiTree T)
// {
	// if(T)
    // {
        // cout<<T->data<<" ";
        // preTraverse(T->lchild);
        // preTraverse(T->rchild);
    // }
// }
// //中序遍历二叉树并打印
// void midTraverse(BiTree T)
// {
    // if(T)
    // {
        // midTraverse(T->lchild);
        // cout<<T->data<<" ";
        // midTraverse(T->rchild);
    // }
// }
// //后续遍历二叉树并打印
// void postTraverse(BiTree T)
// {
    // if(T)
    // {
        // postTraverse(T->lchild);
        // postTraverse(T->rchild);
        // cout<<T->data<<" ";
    // }
// }

//层序遍历一棵二叉树
//637 题目就是这么做的
void cengxuPre(TreeNode* root)
{
	int front=0;
	int rear=0;
	TreeNode* q;
	TreeNode* Q[20];
	if(!root)
		return;
	else
	{
		Q[rear++] = root;
		while(front!=rear)
		{
			q = Q[front++];
			cout<<q->val<<" ";
			if(q->left) Q[rear++] = q->left;
			if(q->right) Q[rear++] = q->right;
		}
	}
}


// int main()
// {
	// cout<<"请输入二叉树的节点，空的节点输入符号 # ："<<endl;
    // BiTree T;               //声明一个指向二叉树根节点的指针               
    // createBiTree(T);
    // cout<<"二叉树创建完成！"<<endl;
	// cout<<"\n";
    // cout<<"前序遍历二叉树："<<endl;
    // preTraverse(T);
    // cout<<endl;
    // cout<<"中序遍历二叉树："<<endl;
    // midTraverse(T);
    // cout<<endl;
    // cout<<"后序遍历二叉树："<<endl;
    // postTraverse(T);
    // return 0;
// }




// #include <iostream>
// using namespace std;

// #define TYPE char

// //树的节点
// struct TreeNode{
    // TYPE element;//该节点的元素
    // TreeNode *firstChild;//指向该节点的第一个孩子
    // TreeNode *nextSibling;//指向该节点的兄弟节点

// };

// class Tree{
    // public:
        // Tree(TreeNode * r = NULL):root(r){}
        // Tree(int node_num);
        // ~Tree();

        // void addNode(int i, int j); 
        // void preOrder();//前序遍历
        // void print();//打印
    // private:
        // void print(TreeNode* node, int num);
        // void addBrotherNode(TreeNode* bro, TreeNode* node);
        // void preOrder(TreeNode* parent);//前序遍历
		
    // private:
        // TreeNode * root;//该树的根
// };

// //打印树的形状
// void Tree::print()
// {
    // print(root, 0);
// }

// void printSpace(int num)
// {
    // int i = 0;
    // for(i = 0; i < num-3; i++)
        // cout << " ";

    // for(; i < num-2; ++i)
        // cout << "|";
    // for(; i < num; ++i)
        // cout << "_";
// }


// void Tree::print(TreeNode* node, int num)
// {
    // if(node != NULL){
        // printSpace(num); 
        // cout << node->element << endl;  
        // print(node->firstChild, num+4);
        // print(node->nextSibling, num);
    // }
// }

// //前序遍历
// void Tree::preOrder()
// {
    // cout << "前序遍历: ";
    // preOrder(root);
    // cout << endl;
// }

// void Tree::preOrder(TreeNode* parent)
// {
    // if(parent != NULL){
        // cout << parent->element << " ";
        // preOrder(parent->firstChild);
        // preOrder(parent->nextSibling);
    // }
// }

// //分配并初始化所有的树结点
// Tree::Tree(int node_num)
// {
    // root = new TreeNode[node_num];

    // char ch = 'A';

    // for(int i = 0; i < node_num; ++i){
        // root[i].element = ch + i;
        // root[i].firstChild = NULL;
        // root[i].nextSibling = NULL;
    // }

// }

// //释放所有节点的内存空间
// Tree::~Tree()
// {
    // if(root != NULL)
        // delete [] root;
// }

// //addNode将父子结点组对
// //如果父节点的firstChild==NULL, 则firstChild = node;
// //如果父节点的firstChild != NULL, 则
// void Tree::addNode(int i, int j)
// {
    // TreeNode* parent = &root[i];
    // TreeNode* node = &root[j];

    // if(parent->firstChild == NULL)
        // parent->firstChild = node;
    // else
        // addBrotherNode(parent->firstChild, node);
// }

// //将节点插入到兄弟节点
// void Tree::addBrotherNode(TreeNode* bro, TreeNode* node)
// {
    // if(bro->nextSibling == NULL)
        // bro->nextSibling = node;
    // else
        // addBrotherNode(bro->nextSibling, node);
// }

// //主函数
// int main()
// {
    // Tree tree(16);//分配十六个节点

    // tree.addNode(0, 1);
    // tree.addNode(0, 2);
    // tree.addNode(0, 3);
    // tree.addNode(0, 4);
    // tree.addNode(0, 5);
    // tree.addNode(0, 6);
    // tree.addNode(3, 7);
    // tree.addNode(4, 8);
    // tree.addNode(4, 9);
    // tree.addNode(5, 10);
    // tree.addNode(5, 11);
    // tree.addNode(5, 12);
    // tree.addNode(6, 13);
    // tree.addNode(9, 14);
    // tree.addNode(9, 15);

    // cout << "Tree1: " << endl;
    // tree.preOrder();
    // tree.print();    

    // Tree tree2(9);
    // tree2.addNode(0, 1);
    // tree2.addNode(0, 2);
    // tree2.addNode(1, 3);
    // tree2.addNode(1, 4);
    // tree2.addNode(2, 5);
    // tree2.addNode(3, 6);
    // tree2.addNode(5, 7);
    // tree2.addNode(5, 8);

    // cout << "Tree2: " << endl;
    // tree2.preOrder();
    // tree2.print();

    // return 0;
// }




#include<iostream>
using namespace std;

struct TreeNode 
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};




//前序遍历二叉树并打印
void preTraverse(TreeNode *T)
{
	if(T)
    {
        cout<<T->val<<" ";
        preTraverse(T->left);
        preTraverse(T->right);
    }
}

class Solution 
{
	public:
	int diameterOfBinaryTree(TreeNode* root) 
	{
		if(root == nullptr) return 0;
		int res = depth(root->left) + depth(root->right);
		return max(res, max(diameterOfBinaryTree(root->left), 
		diameterOfBinaryTree(root->right)));
	}

	int depth(TreeNode* root)
	{
		if(root == nullptr) return 0;
		return 1 + max(depth(root->left), depth(root->right));
	}
};


int main()
{
	TreeNode root(1);
    TreeNode node1(2);
    TreeNode node2(3);
    TreeNode node3(4);
    TreeNode node4(5);
    root.left = &node1;
    root.right = &node2;
    node1.left = &node3;
    node1.right = &node4;
	Solution s;
	int x = s.diameterOfBinaryTree(&root);
	cout<<x<<endl;
	preTraverse(&root);
	
	
    
    return 0;
	
}





































