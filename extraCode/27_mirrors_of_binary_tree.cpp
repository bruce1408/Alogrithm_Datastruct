#include<iostream>
#include<vector>
using namespace std;

/*
        3                   3
	  /   \               /   \
	 9     20            20    9
   /  \                       /  \
  15  7                      7    15


*/



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

//method1 直接利用递归来做，新树的左节点是原树的右节点，新树的右节点是原树的左节点。一直递归即可
TreeNode* mirrorBinarytree1(TreeNode*head)
{
	if(head)
	{
		TreeNode*cur = new TreeNode(head->val);
		cur->left = mirrorBinarytree1(head->right);
		cur->right = mirrorBinarytree1(head->left);
		return cur;
	}
	else
		return nullptr;
}


//method2 book implement
void mirrorBinarytree2(TreeNode*head)
{
	if(head==nullptr) return ;
	if(head->left==nullptr && head->right==nullptr) return ; // only on treenode;

	TreeNode*temp = head->left;    //node exchange
	head->left = head->right;
	head->right = temp;
	if(head->left) mirrorBinarytree2(head->left);// continue traversal
	if(head->right) mirrorBinarytree2(head->right);

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
	h1->left = h3;
	h1->right = h4;



	preTraverse(head);
	cout<<endl;
	// method1 test
	TreeNode*temp;
	temp = mirrorBinarytree1(head);
	preTraverse(temp);


	//method2 test
	// mirrorBinarytree2(head);
	// preTraverse(head);
	return 0;
}


/*扩展题：判断两棵树是否是镜像的二叉树*/
bool isMirror(TreeNode*head1,TreeNode*head2)
{
	if(head1==nullptr&&head2==nullptr) return true;
	if((!head1&&head2) || (head1&&!head2) ||head1->val!=head2->val) return false;
	return isMirror(head1->left,head2->right)&&isMirror(head1->right,head2->left);
}
