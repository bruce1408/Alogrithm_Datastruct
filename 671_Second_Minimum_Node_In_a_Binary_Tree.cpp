/*671 这个二叉树根节点必须小于等于左子树，不同于一般的二叉树，所以求解第二个最小的数的节点思路不一样。*/

/*Input: 
    2
   / \
  2   5
     / \
    5   7

Output: 5

*/


#include<iostream>
#include<vector>
using namespace std;
struct TreeNode 
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x):val(x), left(NULL), right(NULL) {}
};

/*找二叉树中最小的数字*/
// int minnum(TreeNode*root,int &num)
// {
	// if(!root)
		// return -1;
	// // min = root->val;
	// minnum(root->left,num);
	// minnum(root->right,num);
	// if(num>root->val)
		// num = root->val;
	// return num;
// }


// int findMinimumValue(TreeNode* root)
// {
	// int num = root->val;
	// minnum(root,num);
	// return num;	
// }



/*这是第二小的数字*/

class Solution 
{
public:
    int findSecondMinimumValue(TreeNode* root) 
	{
        return helper(root, root->val);
    }
	
    int helper(TreeNode* node, int first) 
	{
        if (!node) return -1;
        if (node->val != first) return node->val;
        int left = helper(node->left, first), right = helper(node->right, first);
        return (left == -1 || right == -1) ? max(left, right) : min(left, right);
    }
};

//前序遍历，然后放到容器里
class Solution_with_vector
{
	public:
	vector<int> helper(TreeNode* root,vector<int> &res)
	{
		if(!root)
			return {};
		res.push_back(root->val);
		helper(root->left,res);
		helper(root->right,res);
		return res;
	}


	vector<int> preTrave(TreeNode* root)
	{
		vector<int> res;
		helper(root,res);
		return res;

		
	}
};

int main()
{
	TreeNode *head = new TreeNode(1);
	TreeNode *h1 = new TreeNode(2);
	TreeNode *h2 = new TreeNode(3);
	// TreeNode *h3 = new TreeNode(15);
	// TreeNode *h4 = new TreeNode(7);
	head->left = h1;
	head->right = h2;
	Solution ss;
	
	// cout<<ss.findSecondMinimumValue(head);
	vector<int> res;
	cout<<preTrave(head)[1];
	
	return 0;
}



























