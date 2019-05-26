#include<iostream>
#include<vector>
#include<sstream>
#include<string>
using namespace std;


struct TreeNode
{
	int val;
	TreeNode*left;
	TreeNode*right;
	TreeNode(int x):val(x),left(NULL),right(NULL) {}
};

// 序列化用前序遍历算法
class Codec
{
public:
	string serialize(TreeNode*head)
	{
		ostringstream out;
		serialize(head, out);
		return out.str();
	}
	TreeNode *deserialize(string data)
	{
		istringstream in(data);
		return deserialize(in);
	}

private:
	void serialize(TreeNode*head,ostringstream &out)
	{
		if(head)
		{
			out<<head->val<<" ";
			serialize(head->left,out);
			serialize(head->right,out);
		}
		else cout<<"$";
	}

	TreeNode*deserialize(istringstream &in)
	{
		string val;
		in >> val;
		if(val=="$") return nullptr;
		TreeNode*cur = new TreeNode(stoi(val));
		cur->left = deserialize(in);
		cur->right = deserialize(in);
		return cur;
	}
};


//反序列化一课树
// void deserialize()

int main()
{
  // create a binary tree
  TreeNode *head = new TreeNode(1);
	TreeNode *h1 = new TreeNode(2);
	TreeNode *h2 = new TreeNode(3);
	TreeNode *h3 = new TreeNode(4);
	TreeNode *h5 = new TreeNode(5);
	TreeNode *h6 = new TreeNode(6);
	head->left = h1;
	head->right = h2;
	h1->left = h3;
	h2->left = h5;
	h2->right = h6;

	Codec ss;
	ss.deserialize(ss.serialize(head));

  return 0;
}
