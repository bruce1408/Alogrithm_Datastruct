/*108. Convert Sorted Array to Binary Search Tree
	把有序数组转换成一个二叉搜索树*/

#include<iostream>
#include<vector>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :val(x),left(NULL),right(NULL) {}
};

class Solution
{
	public:
	TreeNode* sortedArrayToBST(vector<int>& nums)
	{
		return sortBST(nums,0,nums.size()-1);
		
	}

	TreeNode* sortBST(vector<int>& nums,int left,int right)
	{
		if(left > right) return NULL;
		int mid = (left+right)/2;
		TreeNode* head = new TreeNode(nums[mid]);
		head->left = sortBST(nums,left,mid-1);
		head->right = sortBST(nums,mid+1,right);
		return head;
	}
	
};

void print_tree(TreeNode*head)
{
	if(!head)
		return;
	print_tree(head->left);
	cout<<head->val<<" ";
	print_tree(head->right);
	
}


int main()
{
	vector<int> num = {-10,-3,0,5,9};
	Solution ss;
	TreeNode* head;
	head = ss.sortedArrayToBST(num);
	print_tree(head);
	
	
	
	return 0;
}