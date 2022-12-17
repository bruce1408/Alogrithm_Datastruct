/*572. Subtree of Another Tree

/* --------------------------大话数据结构上面的树的实现原理复现-----------------*/
/*---------------------- 二叉树的创建以及前序、中序、后序遍历算法！--------------------*/


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

//求树的深度的算法！
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
	TreeNode root(3);
    TreeNode node1(4);
    TreeNode node2(5);
    TreeNode node3(1);
    TreeNode node4(2);
    root.left = &node1;
    root.right = &node2;
    node1.left = &node3;
    node1.right = &node4;
	Solution s;
	int x = s.diameterOfBinaryTree(&root);
	cout<<"树的深度是："<<x<<endl;
	cout<<"前序遍历算法的结果是："<<endl;
	preTraverse(&root);
	
    return 0;
	
}





































