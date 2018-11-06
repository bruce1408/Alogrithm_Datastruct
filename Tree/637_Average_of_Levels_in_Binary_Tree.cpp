/*
这道题目的做法是层序遍历，然后计算每一层节点数目的均值。
637. Average of Levels in Binary Tree

Input:
    3
   / \
  9  20
    /  \
   15   7
Output: [3, 14.5, 11]

和此题目类似的还有102 和 107。

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

//层序遍历一棵二叉树
void cengxuPre(TreeNode* root)
{
	int front=0;
	int rear=0;
	TreeNode* q;
	TreeNode* Q[20];
	if(!root)  // 不用else的原因是因为return 执行之后自动退出。
		return;
	Q[rear++] = root;
	while(front!=rear)
	{
		q = Q[front++];
		cout<<q->val<<" ";
		if(q->left) Q[rear++] = q->left;
		if(q->right) Q[rear++] = q->right;
	}
	
}

//方法1：利用广度优先遍历方法：层序遍历
vector<double> BinaryTree(TreeNode* root)
{
	TreeNode* q;
	queue<TreeNode*> Q;
	vector<double>res;
	if(!root)
		return {};    //返回空的容器的写法
	Q.push(root); 
	while(!Q.empty())
	{
		int n=Q.size();   //必须要设置一个n，否则你无法求出层序的个数
		double t = 0;
		for(int i=0;i<n;i++)
		{
			q = Q.front();
			Q.pop();
			t+=q->val;
			if(q->left) Q.push(q->left);
			if(q->right) Q.push(q->right);
		}
		res.push_back(t/n);
	}
	return res;
}



//方法1的改进版本；
vector<double> averageOfLevels(TreeNode* root) 
{
	vector<double> res;
	queue<TreeNode*> q;  //这个队列的内容都是树节点的指针；
	q.push(root);
	while(!q.empty()) 
	{
		long temp=0;
		int s=q.size();
		// cout<<"the size:"<<s<<endl;
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
	cengxuPre(head);
	cout<<"层序遍历方法："<<endl;
	res = BinaryTree(head);
	
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