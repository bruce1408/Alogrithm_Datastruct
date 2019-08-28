#include<vector>
#include<iostream>
using namespace std;


//后序遍历，根节点是最后一个节点，左子树均小于根，右子树均大于根。找到那个大于根节点的位置，然后判断
//是否是右子树都大于；然后再递归判断左子树是不是二叉搜索树，右子树是不是二叉搜索树，返回两者的与值
bool isBinarytree_postTravsal(int *res,int length)
{
	int n = length;
	if(res==nullptr||n==0) return false;
	
	int root = res[n-1];
	int preindex=0;
	for(;preindex<n-1;preindex++)
	{
		if(res[preindex]>root)
			break;
	}
	
	int postindex = preindex;
	for(;postindex<n-1;postindex++)
	{
		if(res[postindex]<root)
			return false;
	}
	
	bool left = true;
	if(preindex>0)
		left = isBinarytree_postTravsal(res,preindex);
	
	
	bool right = true;
	if(preindex<length-1)
		right = isBinarytree_postTravsal(res+preindex,length-preindex-1);
	
	return left&&right;
	
	
}


int main()
{
	int res[6] = {5,7,6,9,11,10};
	// int res[4] = {6,4,6,5};
	cout<<isBinarytree_postTravsal(res,6);
	
	return 0;
}