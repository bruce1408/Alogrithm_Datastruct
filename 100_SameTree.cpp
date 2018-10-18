/*     100. Same Tree       */



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



void preThrough(TreeNode * head)
{
	if(head)
	{
		cout<<head->val<<"->";
		preThrough(head->left);
		preThrough(head->right);
	}
	
}


//方法1；有技巧的
bool isSameTree(TreeNode* p, TreeNode* q)
{
	if(!p && !q) return true;
	if(!p || !q) return false;
	return p->val==q->val && isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
	
}



//方法2：很接地气，非常好。牢记
bool isSameTree(TreeNode* p, TreeNode* q)
{
	if(p && q)
		return p->val==q->val && isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
	return p==q;
}



int main()
{
	
	TreeNode *p = new TreeNode(1);
	TreeNode* h1 = new TreeNode(2);
	TreeNode* h2 = new TreeNode(1);
	p->left = h1;
	p->right = h2;
	
	
	TreeNode* q = new TreeNode(1);
	TreeNode* h4 = new TreeNode(2);
	TreeNode* h5 = new TreeNode(1);
	
	q->left = h4;
	q->right = h5;
	preThrough(p);
	cout<<"end"<<endl;
	preThrough(q);
	cout<<"end"<<endl;
	cout<<isSameTree(p,q);
	// cout<<"end"<<endl;
	
	
	//善后处理，释放内存，令其指向空
	delete p;
	delete q;
	delete h1;
	delete h2;
	delete h4;
	delete h5;
	p = nullptr;
	q = nullptr;
	h1 = nullptr;
	h2 = nullptr;
	h4 = nullptr;
	h5 = nullptr;
	
	return 0;

}
