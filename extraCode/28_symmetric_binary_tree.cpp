#include<iostream>
#include<vector>
using namespace std;


//common code
struct TreeNode 
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// pre Traversal  前序遍历
void preTraverse(TreeNode *T)
{
	if(T)
    {
        cout<<T->val<<" ";
        preTraverse(T->left);
        preTraverse(T->right);
    }
}



//判断两棵树是否是相同的
bool symmetricBinarytree(TreeNode*head1,TreeNode*head2)
{
	if(head1==nullptr && head2==nullptr) return true;
	if((head1 && head2==nullptr)||(head1==nullptr && head2)) return false;
		
	if(head1->val==head2->val)
	{
		return symmetricBinarytree(head1->left,head2->left)&&symmetricBinarytree(head1->right,head2->right);
	}
	else return false;
	
}


//判断一棵树是否是对称数
class Solution
{
	public:
	bool isMirror(TreeNode*head1,TreeNode*head2)
	{
		if(head1==nullptr&&head2==nullptr) return true;
		if(!head1&&head2 || head1&&!head2||head1->val!=head2->val) return false;
		return isMirror(head1->left,head2->right)&&isMirror(head1->right,head2->left);
	}

	bool isSymmetricTree(TreeNode*head)
	{
		if(!head) return true;
		return isMirror(head->left,head->right);
	}
	
};




int main()
{
	//树1
	TreeNode *head1 = new TreeNode(3);
	TreeNode *h11 = new TreeNode(9);
	TreeNode *h21 = new TreeNode(20);
	TreeNode *h31 = new TreeNode(15);
	TreeNode *h41 = new TreeNode(7);
	head1->left = h11;
	head1->right = h21;
	h11->left = h31;
	h11->right = h41;
	
	//树2
	TreeNode *head2 = new TreeNode(3);
	TreeNode *h12 = new TreeNode(9);
	TreeNode *h22 = new TreeNode(20);
	TreeNode *h32 = new TreeNode(15);
	TreeNode *h42 = new TreeNode(7);
	head2->left = h12;
	head2->right = h22;
	h12->left = h32;
	h12->right = h42;
	
	
	Solution ss;
	if(ss.isSymmetricTree(head1))
		cout<<"是一棵对称树"<<endl;
	else 
		cout<<"不是对称树"<<endl;
	
	
	return 0;
}



















