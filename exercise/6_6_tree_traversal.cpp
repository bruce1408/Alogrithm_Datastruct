/*二叉树的前序遍历方法*/
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

struct TreeNode 
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//方法1：前序遍历递归算法
// void qianxu(TreeNode* root,vector<int> &res)
// {
	// if(!root) return;
	// else
	// {
		// res.push_back(root->val);
		// qianxu(root->left,res);
		// qianxu(root->right,res);
	// }
// }

// vector<int> preorderTraversal(TreeNode* root)
// {
	// vector<int>res;
	// qianxu(root,res);
	// return res;
// }


//方法2.1：非递归算法，利用栈的思想
/*
思路是栈Q初始化：
循环直到栈为空且p为空的时候退出
	当p不为空的时候：
		p入栈
		p当前的值给数组
		p指向左子树
	如果Q是非空则
		栈顶元素弹至p；
		p指向p的you右子树
*/
vector<int> preorderTraversal(TreeNode* root)
{
	stack<TreeNode*>Q;
	TreeNode* p;
	vector<int>res;
	if(!root) return {};
	p = root;
	while(!Q.empty() || p)
	{
		while(p)
		{
			res.push_back(p->val);
			Q.push(p);
			p = p->left;
		}
		if(!Q.empty())
		{
			p = Q.top();
			Q.pop();
			p = p->right;
		}
	}
	return res;
}

//方法2.2 非递归算法，没有while，只用了判断语句。
class Solution 
{
	public:
    vector<int> preorderTraversal(TreeNode* root) 
	{
        vector<int> res;
        stack<TreeNode*> s;
        TreeNode *p = root;
        while (!s.empty() || p) 
		{
            if (p) 
			{
                s.push(p);
                res.push_back(p->val);
                p = p->left;
            } 
			else 
			{
                TreeNode *t = s.top(); s.pop();
                p = t->right;
            }
        }
        return res;
    }
};

/*二叉树的中序遍历*/
// 方法1：使用递归的方式，但是res每次递归的时候要重建，所以索性把
// res变成静态变量。或者是其他方法。比如方法2
class Solution
{
	public:
	vector<int> inorderTraversal(TreeNode* root)
	{
		
		if(!root)
			return {};
		else
		{
			inorderTraversal(root->left);
			res.push_back(root->val);
			inorderTraversal(root->right);
		}
		return res;
	}
	
	private: //加了静态变量，res每次都在
	vector<int>res;
};

//方法2：不用静态变量
class Solution
{
	public:
	void midTraversal(TreeNode *root ,vector<int> &res) //res必须加上引用
	{
		if(!root) return;
		else
		{
			midTraversal(root->left,res);
			res.push_back(root->val);
			midTraversal(root->right,res);
		}	
	}
	
	vector<int> inorderTraversal(TreeNode *root)
	{
		vector<int> res; //这个作用是传res
		midTraversal(root,res);	
		return res;
	}
};

//方法3.1：利用迭代的方法，也用了栈的思想，但是没有具体用stack的标准库
vector<int> inorderTraversal(TreeNode *root)
{
	vector<int> res;
	TreeNode* p;
	vector<TreeNode*> Q(20,0);
	int top = -1;
	if(root!=NULL)
	{
		p = root;
		while(top>-1 || p!=NULL)
		{
			while(p!=NULL)
			{
				Q[++top]=p;
				p=p->left;
			}
			if(top>-1)
			{
				p = Q[top--];
				res.push_back(p->val);
				p=p->right;
			}
		}
	}
	return res;
}

//方法3.2：用栈的方法stack,思路和上面的一摸一样

vector<int> inorderTraversal(TreeNode *root)
{
	vector<int> res;
	stack<TreeNode*>Q;
	TreeNode* p;
	if(!root)
		return {};
	p = root;
	while(!Q.empty() || p)
	{
		while(p)
		{
			Q.push(p);
			p = p->left;
		}
		if(!Q.empty())
		{
			p = Q.top();
			Q.pop();
			res.push_back(p->val);
			p = p->right;	
		}
	}
	return res;
}

/*二叉树的后序遍历*/



/*二叉树的层序遍历*/
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





