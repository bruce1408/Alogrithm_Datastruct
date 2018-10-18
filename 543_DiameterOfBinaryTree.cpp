/*543 求二叉树的深度。*/
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
//解决方案1：递归方式来解决！
// class Solution 
// {
	// public:
	// int diameterOfBinaryTree(TreeNode* root) 
	// {
		// if(root == nullptr) return 0;
		// int res = depth(root->left) + depth(root->right);
		// return max(res, max(diameterOfBinaryTree(root->left), 
		// diameterOfBinaryTree(root->right)));
	// }

	// int depth(TreeNode* root)
	// {
		// if(root == nullptr) return 0;
		// return 1 + max(depth(root->left), depth(root->right));
	// }
// };

/*解决方案2：深度优先遍历来解决。*/
// class Solution {
	// public:
    // int maxdiadepth = 0;
    
    // int dfs(TreeNode* root){        
        // if(root == NULL) return 0;
        
        // int leftdepth = dfs(root->left);
        // int rightdepth = dfs(root->right);
        
        // if(leftdepth + rightdepth > maxdiadepth) maxdiadepth = leftdepth + rightdepth;
        // return max(leftdepth +1, rightdepth + 1);     
    // }
    
    // int diameterOfBinaryTree(TreeNode* root) {        
        // dfs(root);
        
        // return maxdiadepth;
    // }
// };

/*解决方案3：和方案2是一样的，但是3的部分的手法和2不一样，稍微理解起来简单点*/
class Solution1
{
	public:
	int diameterOfBinaryTree(TreeNode *T)
	{
		maxDeep(T);
		return maxnum;
	}
	
	int maxDeep(TreeNode *T)
	{
		if(T==NULL) return 0;
		int lenum = maxDeep(T->left);
		int rinum = maxDeep(T->right);
		
		maxnum = max(maxnum, lenum + rinum);
		return max(lenum, rinum)+1;
	}
	
	private:
	int maxnum = 0;
};



/*解决方案4：判断树的深度的算法！*/
class Solution2
{
	public:
	int Depth(TreeNode* root)
	{
		if(root==NULL)
		{
			return 0;
		}
		else
		{
			int hl = Depth(root->left);
			int hr = Depth(root->right);
			return max(hl,hr)+1;
		}
	}
};



int main()
{
	TreeNode root(1);
    TreeNode node1(2);
    TreeNode node2(3);
    TreeNode node3(4);
    TreeNode node4(5);
    // TreeNode node5(5);
    root.left = &node1;
    root.right = &node2;
    node1.left = &node3;
    node1.right = &node4;
	// node3.right = &node5;
	// Solution s;
	Solution1 s1;
	// int x = s.diameterOfBinaryTree(&root);
	int x1 = s1.diameterOfBinaryTree(&root);
	Solution2 s2;
	int x2 = s2.Depth(&root);
	cout<<"树的深度是："<<x2<<endl;
	cout<<"前序遍历的结果是："<<endl;
	preTraverse(&root);
	
	
    return 0;
	
}
