//二叉排序树、二叉查找树
//构建一课二叉排序树的目的不是在于排序，而是提高查找和插入删除的速度。二叉排序树的非线性结构利于这种操作。
/*二叉排序树的删除操作，因为二叉排序树的特殊性，中序遍历的结果是升序的数组，所以删除节点的时候，一般找前驱或者是后继节点来
	替代这个节点，选择的方式是要么看左子树，然后一直遍历到右子树不存在为止，要么是选择右子树，然后一直遍历到左子树不存在为止，再把剩余的
	右子树或者是左子树连接上去。
二叉排序树的删除操作很麻烦！*/


#include<iostream>
#include<vector>
#include<string>
using namespace std;


struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x):val(x),left(NULL),right(NULL){}
};


void inorder(TreeNode *head)
{
	if(!head)
		return ;
	inorder(head->left);
	cout<<head->val<<" ";
	inorder(head->right);

}

//二叉排序树的查找操作
bool search_binary(TreeNode *head,int key)
{
	if(!head) return false;
	else if(key==head->val) return true;
	else if(key<head->val) return search_binary(head->left,key);
	else return search_binary(head->right,key);
	
}


//二叉树的插入操作
void insert_binary(TreeNode*&head,TreeNode*p)//*&head 引用head指针。
{
	if(!head) head = p;
	else if((head->val)>(p->val))
		insert_binary(head->left,p);
	else
		insert_binary(head->right,p);
}



//二叉排序树的删除操作
bool delete_node(TreeNode*&head)
{
	TreeNode*cur;
	TreeNode*pre;
	if(head->left==NULL)//没有左子树的情况
	{
		cur=head;
		head = head->right;
		delete cur;
		
	}
	else if(head->right==NULL)//没有右子树的情况
	{
		cur = head;
		head=head->left;
		delete cur;
		
	}
	else //左右子树都存在
	{
		cur = head;
		pre = head->right;//找删除节点的直接前驱或者是后继节点，这里选择后继节点。
		while(pre->left)
		{
			cur = pre;
			pre = pre->left;
		}
		head->val = pre->val;
		if(cur!=head)
			cur->left = pre->right;
		else
			cur->right = pre->left;
			
	}
	return true;
}



bool delete_binary(TreeNode*&head,int key)
{
	if(!head)
		return false;
	else
	{
		if(head->val==key)
			return delete_node(head);
		else if(head->val > key)
		{
			return delete_binary(head->left,key);
		}
		else 
			return delete_binary(head->right,key);
	}
	
}


/*上面讨论了二叉排序树的插入，删除，和查找操作，下面主要讨论二叉排序树构成平衡二叉树*/
//二叉树如何构成平衡二叉树


int main()
{
	//构造二叉排序树如下
	vector<int>t = {62,88,58,47,35,73,51,99,37,93};
	TreeNode *head = new TreeNode(62);
	TreeNode *a = new TreeNode(88);
	TreeNode *b = new TreeNode(58);
	TreeNode *c = new TreeNode(47);
	TreeNode *d = new TreeNode(35);
	TreeNode *e = new TreeNode(73);
	TreeNode *f = new TreeNode(51);
	TreeNode *g = new TreeNode(99);
	TreeNode *h = new TreeNode(37);
	TreeNode *i = new TreeNode(93);

	
	head->left = b;
	head->right = a;
	b->left = c;
	c->left = d;
	c->right = f;
	a->left = e;
	a->right = g;
	g->left =  i;
	d->right = h;
	//中序遍历，是有序的数列
	inorder(head);
	cout<<endl;
	//删除，插入，查找。
	// TreeNode*p;
	// cout<<search_binary(head,35);
	//插入操作
	// TreeNode*q = new TreeNode(55);
	// insert_binary(head,q);
	// inorder(head);
	//删除操作
	cout<<delete_binary(head,73)<<endl;
	inorder(head);
	
	
	
	
	return 0;
}