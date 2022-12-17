/*
主要介绍的是stack和queue的用法：
stack有很多函数：
s.push(item);       //将item压入栈顶  
s.pop();            //删除栈顶的元素，但不会返回  
s.top();            //返回栈顶的元素，但不会删除  
s.size();           //返回栈中元素的个数  
s.empty();

queue的函数：
q.push(item)           //将item压入队列尾部  
q.pop()                //删除队首元素，但不返回  
q.front()              //返回队首元素，但不删除  
q.back()               //返回队尾元素，但不删除  
q.size()               //返回队列中元素的个数  
q.empty()              //检查队列是否为空，如果为空返回true，否则返回false  
*/
// #include<iostream>
// #include<queue>
// #include<stack>
// using namespace std;
// int main()
// {
// stack<int> s;
// int num = 0;
// cout<<"-------------test for satck-----------"<<endl;
// cout<<"input a num:"<<endl;
// while(cin>>num)
// {
// s.push(num);

// }

// cout<<"the size of stack is:"<<s.size()<<endl;
// while(!s.empty())
// {
// cout<<s.top()<<" ";
// s.pop();
// }
// cout<<"the now size of stack is:"<<s.size()<<endl;
// return 0;
// }

#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * 使用中缀表达式转换为后缀表达式
*/
int prio(char op)
{ //给运算符优先级排序
	int priority;
	if (op == '*' || op == '/')
		priority = 2;
	if (op == '+' || op == '-')
		priority = 1;
	if (op == '(')
		priority = 0;
	return priority;
}

bool Trans(string &str, string &str1)
{
	stack<char> s; //定义一个char类型的栈s
	int i;
	for (i = 0; i < str.size(); i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{ //如果是数字，直接入栈
			str1 += str[i];
		}
		else
		{				   //否则不是数字
			if (s.empty()) //栈空则入站
				s.push(str[i]);
			else if (str[i] == '(') //左括号入栈
				s.push(str[i]);
			else if (str[i] == ')')
			{ //如果是右括号，只要栈顶不是左括号，就弹出并输出
				while (s.top() != '(')
				{
					str1 += s.top();
					s.pop();
				}
				s.pop(); //弹出左括号，但不输出
			}
			else
			{
				while (prio(str[i]) <= prio(s.top()))
				{ //栈顶优先级大于等于当前运算符，则输出
					str1 += s.top();
					s.pop();
					if (s.empty()) //栈为空，停止
						break;
				}
				s.push(str[i]); //把当前运算符入栈
			}
		}
	}
	while (!s.empty())
	{ //最后，如果栈不空，则弹出所有元素并输出
		str1 += s.top();
		s.pop();
	}
	return true;
}

int main()
{
	string a = "1+2*3+(5-4)*4", b;
	Trans(a, b);
	cout << b << endl;
}
