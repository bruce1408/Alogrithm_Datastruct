/*654. Maximum Binary Tree
	Input: [3,2,1,6,0,5]
Output: return the tree root node representing the following tree:

      6
    /   \
   3     5
    \    / 
     2  0   
       \
        1
	*/
	
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





TreeNode* constructMaximumBinaryTree(vector<int>& nums)
{
	if(nums.empty()) return NULL;
	
	int max_index = 0;
	int max_num = INT_MIN;
	for(int i=0;i<nums.size();i++)
	{
		if(nums[i]>max_num)
		{
			max_num = nums[i];
			max_index = i;
		}
	}
	
	TreeNode * head = new TreeNode(max_num);
	Vector<int> leftarr = vector<int>(nums.begin(),nums.begin()+max_index);
	Vector<int> rightarr = vector<int>(nums.begin()+max_index+1,nums.end());
	head ->left = constructMaximumBinaryTree(leftarr);
	head ->right = constructMaximumBinaryTree(rightarr);
	
	return head;
	
}	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	