/*113 112  129 都是很像的类型题目

Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return
[[5,4,11,2],[5,8,4,5]]

*/


#include<iostream>
#include<stack>
#include<vector>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x):val(x),left(NULL),right(NULL) {}
};


class Solution
{
	public:
	vector<vector<int>> pathSum(TreeNode* root, int sum)
	{
		vector<int>temp;
		vector<vector<int>>res;
		digui(root,sum,temp,res);
		return res;
	}
	
	void digui(TreeNode* root,int sum,vector<int> &temp,vector<vector<int>>&res)
	{
		if(!root) return ;
		temp.push_back(root->val);
		if(root->val==sum &&! root->left &&! root->right)
		{
			res.push_back(temp);
		}
		digui(root->left,sum-root->val,temp,res);
		digui(root->right,sum-root->val,temp,res);
		temp.pop_back();   // 移除上一个不属于的节点。
	}
	
};



int main()
{
	
	TreeNode* head = new TreeNode(2);
	TreeNode* h1 = new TreeNode(1);
	TreeNode* h2 = new TreeNode(3);
	head->left = h1;
	head->right = h2;
	Solution ss;
	ss.pathSum(head,4);
	
	return 0;
}

