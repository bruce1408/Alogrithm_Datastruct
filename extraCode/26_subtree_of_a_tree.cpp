#include<iostream>
#include<vector>
#include<sstream>
#include<stack>
using namespace std;

struct TreeNode 
{
	int val;
	TreeNode *left; //左子节点
	TreeNode *right; // 右子节点
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * 题目：树的子结构，输入两棵二叉树 A 和 B，然后判断B是不是A的子结构；
 * 方法
 * 思路：572. Subtree of Another Tree
 * 这个题目是判断是否是子树。但是从剑指offer上看，exampl 2其实也是它的子树
 * Given tree s:
 * 
 *   3
    / \
   4   5
  / \
 1   2
 
Given tree t:
   4 
  / \
 1   2
 
Return true, because t has the same structure and node values with a subtree of s.

Example 2:
Given tree s:
     3
    / \
   4   5
  / \
 1   2
    /
   0
   
Given tree t:
   4
  / \
 1   2
 方法 递归
 思路：
 利用递归的思路，首先判段是不是子树头结点是否是空，或者是子树和树1是否相同，如果不同，返回false，
 否则，返回子函数的isPart进行比较左子节点和右子节点是否相同，
*/

// 第一版代码，写的太啰嗦了
bool Dosetree(TreeNode*t1, TreeNode*t2)
{
	if(t2==nullptr) return true;
	if(t1==nullptr) return false;
	if(t1->val != t2->val) return false;
	return Dosetree(t1->left, t2->left) && Dosetree(t1->right, t2->right);
}

bool hasSubtree(TreeNode*t1, TreeNode*t2)
{
	bool result = false;
	if(t1 && t2)
	{
		if(t1->val==t2->val)
		{
			result = Dosetree(t1, t2);
		}
		if(!result)
		{
			result = hasSubtree(t1->left,t2);
		}
		if(!result)
		{
			result = hasSubtree(t1->right,t2);
		}
	}
	return result;
}

// 重新做20190610, 双层递归，最好的解法之一；
bool isPart(TreeNode* tr1, TreeNode* tr2)
{
	if(tr2 != nullptr) return true;
	if(tr1==nullptr || tr1 != tr2) return false;
	return (isPart(tr1->left, tr2->left) && isPart(tr1->right, tr2->right));
}

bool subTree(TreeNode *tr1, TreeNode *tr2) // 主方法
{
	if(tr1==nullptr) return false;
	if(isPart(tr1, tr2)) return true;
	else return (subTree(tr1->left, tr2) || subTree(tr1->right, tr2));
}

// TODO方法2 序列化和反序列化
class Solution{
	bool isSubtree(TreeNode* s, TreeNode* t) {
		ostringstream os1, os2;
		serialize(s, os1);
		serialize(t, os2);
		return os1.str().find(os2.str()) != string::npos;
	}

	void serialize(TreeNode* node, ostringstream& os) {
		if (!node) os << ",#";
		else {
			os << "," << node->val;
			serialize(node->left, os);
			serialize(node->right, os);
		}
	}
};

int main()
{
	TreeNode *head1 = new TreeNode(3);
	TreeNode *h1 = new TreeNode(9);
	TreeNode *h2 = new TreeNode(20);
	TreeNode *h3 = new TreeNode(15);
	TreeNode *h4 = new TreeNode(7);
	head1->left = h1;
	head1->right = h2;
	h1->left = h3;
	h1->right = h4;
	
	TreeNode *head2 = new TreeNode(9);
	TreeNode *h21 = new TreeNode(15);
	TreeNode *h22 = new TreeNode(7);
	head2->left = h21;
	head2->right = h22;

	// cout<<hasSubtree(head1,head2)<<endl;
	cout<<subTree(head1, head2)<<endl;
	return 0;
}



















