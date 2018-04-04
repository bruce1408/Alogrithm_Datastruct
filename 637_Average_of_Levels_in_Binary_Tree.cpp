/*
637. Average of Levels in Binary Tree

Input:
    3
   / \
  9  20
    /  \
   15   7
Output: [3, 14.5, 11]

*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct TreeNode 
{
	double val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


// class Solution
// {
	// public:
	// vector<double> averageOfLevels(TreeNode* root)
	// {
		// static int i;
		// vector<double> res;
		// if(root && i==0)
		// {
			// res.push_back(root->val);
			// i++;
		// }
		// if(root->left && root->right)
			// res.push_back((root->left->val + root->right->val)/2);
		// return res;
	// }	
// };



// class Solution 
// {
	// public:
    // vector<double> averageOfLevels(TreeNode* root) 
	// {
        // if (!root) return {};
        // vector<double> res;
        // queue<TreeNode*> q{{root}};
        // while (!q.empty()) 
		// {
            // int n = q.size();
            // double sum = 0;
            // for (int i = 0; i < n; ++i) 
			// {
                // TreeNode *t = q.front(); q.pop();
                // sum += t->val;
                // if (t->left) q.push(t->left);
                // if (t->right) q.push(t->right);
            // }
            // res.push_back(sum / n);
        // }
        // return res;
    // }
// };



vector<double> averageOfLevels(TreeNode* root) 
{
	vector<double> res;
	queue<TreeNode*> q;
	q.push(root);
	
	while(!q.empty()) 
	{
		long temp=0;
		int s=q.size();
		cout<<"the size:"<<s<<endl;
		for(int i=0;i<s;i++) 
		{
			TreeNode* t=q.front();
			q.pop();
			if(t->left) q.push(t->left);
			if(t->right) q.push(t->right);
			temp+=t->val;
		}
		res.push_back((double)temp/s);
	}
	return res;
}



int main()
{
	TreeNode *head = new TreeNode(1);
	TreeNode* h1 = new TreeNode(2);
	TreeNode* h2 = new TreeNode(3);
	TreeNode* h3 = new TreeNode(4);
	TreeNode* h4 = new TreeNode(5);
	head->left = h1;
	head->right = h2;
	h1->left = h3;
	h1->right = h4;
	vector<double> res;
	
	// Solution ss;
	res = averageOfLevels(head);
	for(auto i:res)
	{
		cout<<i<<" ";
	}
	
	//善后处理，释放内存，令其指向空
	delete head;
	delete h1;
	delete h2;
	delete h3;
	delete h4;
	head = nullptr;
	h1 = nullptr;
	h2 = nullptr;
	h3 = nullptr;
	h4 = nullptr;
	
	return 0;
}