/*  这道题目和637非常类似，思路几乎一样的。102都是很类似
对一棵二叉树进行层序遍历，最关键的是输出的顺序是倒过来的。

Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7

output：return its bottom-up level order traversal as: [[15,7],[9,20],[3]]

*/


#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;

struct TreeNode 
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


//思路是把层序遍历的数值放到队列里面，然后对每一个队列的数值用栈来存放，
//这样最后一个，其实就是题目要求输出的第一个，然后再把栈顶元素放到容器即可
//步骤就是先层序放到队列，然后队列放到栈，最后栈移到容器，也可以不用移动，
//容器反转也可以，用一个反转的函数reverse，但是最好用自己的算法解决。
vector<vector<int>> cengxu(TreeNode *root)
{
	stack<vector<int>>m;
	vector<vector<int>> res;
	queue<TreeNode *> Q;
	TreeNode* q;
	if(!root)
		return {};
	Q.push(root);
	while(!Q.empty())
	{
		vector<int> temp;
		int n = Q.size();
		for(int i=0;i<n;i++)
		{			
			q = Q.front();
			Q.pop();
			temp.push_back(q->val);
			if(q->left) Q.push(q->left);
			if(q->right) Q.push(q->right);
		}
		m.push(temp);
	}
	int n = m.size();
	//从栈里面拿出来给容器，反转
	//也可以用algorithm头文件的reverse函数，或者是insert函数
	//reverse(res.begin(),res.end());
	//res.insert(res.begin(), oneLevel);
	for(int i=0;i<n;i++)
	{
		res.push_back(m.top());
		m.pop();
	}
	return res;
}



vector<vector<int>> levelOrderBottom(TreeNode* root) 
{
		
}


int main()
{
	TreeNode *head = new TreeNode(3);
	TreeNode *h1 = new TreeNode(9);
	TreeNode *h2 = new TreeNode(20);
	TreeNode *h3 = new TreeNode(15);
	TreeNode *h4 = new TreeNode(7);
	head->left = h1;
	head->right = h2;
	h2->left = h3;
	h2->right = h4;
	vector<vector<int>> rest;
	rest = cengxu(head);
	int n = rest.size();
	cout<<n<<endl;
	
	
	
	
	
	return 0;
}
















