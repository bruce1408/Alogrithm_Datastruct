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


#include<iostream>
#include<queue>
#include<stack>
#include<vector>
#include <algorithm>

using namespace std;

int main()
{
	// queue<int> q;
	// int num = 0;
	// cout<<"-------------test for queue-----------"<<endl;
	// cout<<"input a num:"<<endl;
	// while(cin>>num)
	// {
		// q.push(num);
	
	// }
	
	// cout<<"the size of queue is:"<<q.size()<<endl;
	// cout<<"the front of queue is:"<<q.front()<<endl;
	// cout<<"the back of queue is:"<<q.back()<<endl;
	// while(!q.empty())
	// {
		// cout<<q.front()<<" ";
		// q.pop();
	// }
	// cout<<"the now size of queue is:"<<q.size()<<endl;
	
	stack<int>m;
	m.push(1);
	m.push(1);
	m.push(1);
	
	// for(int i=0;i<3;i++)
	// {
		// cout<<m.top()<<endl;
		// m.pop();
	// }
	

	vector<vector<int>> res = {{1,3},{4},{2,4}};
	// vector<vector<int>> res = {1,2,3,4,5};
	
	// cout<<res.size()<<endl;
	
	// for(int i=0;i<res.size();i++)
	// {	
		// int size_ = res[i].size();
		// for(int j=0;j<size_;j++)
		// {
			// cout<<res[i][j]<<",";
		// }
		// cout<<" ";
	// }
	vector<int> oneh = {3,5};
	
	res.insert(res.begin(),oneh);
	reverse(res.begin(),res.end());
	
	for(int i=0;i<res.size();i++)
	{	
		int size_ = res[i].size();
		for(int j=0;j<size_;j++)
		{
			cout<<res[i][j]<<",";
		}
		cout<<" ";
	}
	return 0;
}






























