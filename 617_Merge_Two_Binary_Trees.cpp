/*	617. Merge Two Binary Trees

Input: 
	Tree 1                     Tree 2                  
          1                         2                             
         / \                       / \                            
        3   2                     1   3                        
       /                           \   \                      
      5                             4   7                  


Output: 
Merged tree:
	     3
	    / \
	   4   5
	  / \   \ 
	 5   4   7

*/

#include<iostream>
#include<vector>
using namespace std;


struct TreeNode 
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution 
{
	public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) 
	{
        
    }
};







































































