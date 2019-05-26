#include<iostream>
#include<vector>
using namespace std;

/**
 * 题目：按照中序的顺序找出节点的一下个节点
 * 方法1 分几种情况讨论
 * 思路：
 * 第一，如果是该节点有右子树，那么该节点的下一个节点就是这个右子树的做节点；
 * 第二，如果该节点没有右子树，且它是父节点的左节点，那么下一个节点就是父节点；
 * 第三，如果该节点没有右子树，且它是父节点的右节点，情况是最复杂的，找到它的父节点，然后该节点是不是它父节点的左节点，如果是，那么它
 * 的父节点就是下一个节点，找到了；否则，继续向上遍历；
*/

struct TreeNode 
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    struct TreeNode *parent; // 增加一个指向父节点的指针
    TreeNode(int x) :val(x), left(NULL), right(NULL), parent(NULL) {}
};

// 官方代码
TreeNode* GetNext(TreeNode* pNode)
{
	if(pNode == nullptr) return nullptr;

	TreeNode* pNext = nullptr;
	if(pNode->right != nullptr)
	{
		TreeNode* pRight = pNode->right;
		while(pRight->left != nullptr)
			pRight = pRight->left;
		pNext = pRight;
	}
	else if(pNode->parent != nullptr)
	{
		TreeNode* pCurrent = pNode;
		TreeNode* pParent = pNode->parent;
		while(pParent != nullptr && pCurrent == pParent->right)
		{
			pCurrent = pParent;
			pParent = pParent->parent;
		}

		pNext = pParent;
	}
	return pNext;
}

void print_tree(TreeNode*head)
{
	if(!head)
		return ;
	print_tree(head->left);
	cout<<head->val<<" ";
	print_tree(head->right);
}

TreeNode* nextNode(TreeNode*head)
{
	if(head==NULL)
		return nullptr;
	TreeNode*next_node=NULL;
	//分三种情况，第一中情况，有右子树的情况，然后一直遍历左子树即可，最后一个最子树就是下一个节点。
	if(head->right!=NULL)
	{
		TreeNode*pright = head->right;
		while(pright->left!=nullptr)
		{
			pright = pright->left;
		}
		next_node = pright;
	}
	//第二种情况，没有右子树，但是该节点的是其父节点的左子节点，那么下一个节点就是它的父节点
	else if(head->parent!=nullptr)
	{
		TreeNode*cur = head;
		TreeNode*parent = head->parent;
		while(parent->left!=cur && parent!=nullptr)
		{
			cur = parent;
			parent = cur->parent;
		}
		next_node = parent;
	}
	return next_node;
}

// 第二遍做
TreeNode* getNext(TreeNode * pNode)
{
	TreeNode * rtemp = nullptr;
	if(pNode == nullptr) return nullptr;
	TreeNode * cur = pNode;
	// 第一种情况 是否有右子树
	if(cur->right!=nullptr)
	{
		TreeNode *temp = cur->right;
		while(temp->left!=nullptr)
		{
			temp = temp->left;
		}
		rtemp = temp;
	}

	// 第二种情况，没有右子树，且它是父节点的左节点，包含了第二种情况
	else if(cur->right == nullptr && cur->parent != nullptr)
	{
		TreeNode* temp = cur->parent;
		while(temp!=nullptr && cur == temp->right)
		{
			cur = temp;
			temp = temp->parent;
		}
		rtemp = temp;
	}
	return rtemp;
}

int main()
{
	TreeNode* n1 = new TreeNode(1);
	TreeNode* n2 = new TreeNode(2);
	TreeNode* n3 = new TreeNode(3);
	TreeNode* n4 = new TreeNode(4);
	TreeNode* n5 = new TreeNode(5);
	TreeNode* n6 = new TreeNode(6);
	TreeNode* n7 = new TreeNode(7);
	TreeNode* n8 = new TreeNode(8);
	TreeNode* n9 = new TreeNode(9);
	n1->left = n2;
	n1->right = n3;
	n2->left = n4;
	n2->right = n5;
	n3->left = n6;
	n3->right = n7;
	n5->left = n8;
	n5->right = n9;

	n2->parent = n1;
	n3->parent = n1;
	n4->parent = n2;
	n5->parent = n2;
	n6->parent = n3;
	n7->parent = n3;
	n8->parent = n5;
	n9->parent = n5;
	print_tree(n1);
	cout<<endl;
	cout<<GetNext(n9)->val<<endl;
	cout<<getNext(n9)->val<<endl;
}



