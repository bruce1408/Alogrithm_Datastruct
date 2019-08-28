#include<iostream>
#include<vector>
#include<stack>
using namespace std;

/*利用一个辅助栈，辅助栈的栈顶和出栈顺序一直作比较，如果是相同，出栈，否则入栈。
举例：
入栈1,2,3,4,5
出栈4,5,3,2,1
首先1入辅助栈，此时栈顶1≠4，继续入栈2
此时栈顶2≠4，继续入栈3
此时栈顶3≠4，继续入栈4
此时栈顶4＝4，temp出栈4，弹出序列向后前进一位，值为5，,辅助栈里面是1,2,3
此时栈顶3≠5，继续入栈5
此时栈顶5=5，出栈5,弹出序列向后一位，此时为3，,辅助栈里面是1,2,3
依次执行，最后辅助栈为空。如果不为空说明弹出序列不是该栈的弹出顺序。
*/
bool ispopOrder(int *pin,int *pout,int length)
{
	stack<int>temp;
	int outIndex = 0;
	for(int i=0;i<length;i++)
	{
		temp.push(pin[i]);
		while(!temp.empty() && temp.top()==pout[outIndex])
		{
			temp.pop();
			outIndex++;
		}
	}
	return temp.empty();
}

int main()
{
	//也可以自己修改函数，输入只来判断。
	int pin[5] = {1,2,3,4,5};
	int pout[5] = {4,5,3,2,1};
	cout<<ispopOrder(pin,pout,5);
}
















