#include <iostream>
#include <vector>
using namespace std;
/**
 * 110 和 104 很类似，不过这个是判断平衡二叉树，还有判断最小二叉树的题目。
 * 判断是否是平衡二叉树。从树的深度来入手判断这个题目；
 * 平衡二叉树树高的概念就是：一棵树，root节点所在的子树高度等于左子树高度和右子树高度的最大值+1
 * root_height = max(height(root->left), height(root->right)) + 1 ;
 * 判断平衡二叉树是：左子树高度与右子树高度之差的绝对值不超过1
 * */
struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * 方法 1，depthTree  函数是判断树的深度的函数
 */
int getHeight(TreeNode *root)
{
	if (!root)
		return 0;
	return max(getHeight(root->left) + 1, getHeight(root->right) + 1);
}

bool isBalanced(TreeNode *root)
{
	if (!root)
		return true;
	if (abs(getHeight(root->left) - getHeight(root->right)) > 1)
		return false;
	return isBalanced(root->left) && isBalanced(root->right); // 左子树和右子树必须同时满足才可以！
}

int main()
{

	TreeNode *head1 = new TreeNode(22);
	TreeNode *head = new TreeNode(3);
	TreeNode *h1 = new TreeNode(9);
	TreeNode *h2 = new TreeNode(20);
	TreeNode *h3 = new TreeNode(15);
	TreeNode *h4 = new TreeNode(7);
	head->left = h1;
	head->right = h2;
	h2->left = h3;
	h2->right = h4;

	// cout<<depthTree(head1)<<endl;
	cout << isBalanced(head1) << endl;
	return 0;
}
