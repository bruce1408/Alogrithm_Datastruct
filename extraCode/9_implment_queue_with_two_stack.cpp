#include <stack>
#include<iostream>
using namespace std;

/**
 * 题目：用两个栈来实现一个队列
 * 方法1 根据栈和队列的性质
 * 思路：
 * 此题目的是实现队列，我们可以用链表，但是此题需要用栈来实现，
 * 栈的特点是后进先出，而队列是先进先出的形式，所以思路就是用两个栈来相互倒腾。这样才能实现此功能！
 * 把主栈的元素放到辅栈，然后拿出第一个元素之后再把辅栈的元素再放回主栈当中去即可；
 * 发散思维：leetcode上类似的解法 效率也一般
*/

class MyQueue 
{
  public:
    /** Initialize your data structure here. */
    MyQueue() {}

    /** Push element x to the back of queue. */
    void push(int x) { myStack.push(x); }

    /** Removes the element from in front of queue and returns that element. */
    int pop() 
	{
        while (!myStack.empty()) //把主栈的元素全部给辅栈，然后主栈清空；
		{
            myStackTemp.push(myStack.top());
            myStack.pop();
        }
        int x = myStackTemp.top();//辅栈的top元素就是队列对应的第一个元素。
        myStackTemp.pop();        //然后删除这个元素。
        while (!myStackTemp.empty()) //接着再把辅栈的元素装回主栈。
		{
            myStack.push(myStackTemp.top());
            myStackTemp.pop();     //辅栈清空；
        }
        return x;
    }

    /** Get the front element. */
    int peek()/* Get the front element*/   //返回队列首元素，但不删除
	{
        while (!myStack.empty()) 
		{
            myStackTemp.push(myStack.top());
            myStack.pop();
        }
        int x = myStackTemp.top(); //没有删除的操作
        while (!myStackTemp.empty()) 
		{
            myStack.push(myStackTemp.top());
            myStackTemp.pop();
        }
        return x;
    }

    /** Returns whether the queue is empty. */
    bool empty() { return myStack.empty(); }

  private:
    stack<int> myStack;//一个主栈
    stack<int> myStackTemp;//辅助栈
};

/*MyQueue_0 leetcode上比较好的解法  代码比较优雅*/ 
class MyQueue_0 
{
  public:
    /** Initialize your data structure here. */
    MyQueue_0() {}

    /** Push element x to the back of queue. */
    void push(int x) { input.push(x); }

    /** Removes the element from in front of queue and returns that element. */
    int pop() 
	{
        int x = peek();
        output.pop();
        return x;
    }

    /** Get the front element. */
    int peek() 
	{
        if (output.empty()) 
		{
            while (!input.empty()) 
			{
                output.push(input.top());
                input.pop();
            }
        }
        return output.top();
    }
    /** Returns whether the queue is empty. */
    bool empty() { return input.empty() && output.empty(); }

  private:
    // stack<int> input,output;//辅助栈
    stack<int> input;//辅助栈
    stack<int> output;//辅助栈
};

int main()
{
	MyQueue_0 q;
	int num;
	cout<<"请输入数字："<<endl;
	while(cin>>num)
	{
		q.push(num);
	}
	cout<<"the top elements is: "<<q.peek()<<endl;
	cout<<"the q num is:"<<endl;
	while(!q.empty())
	{
		cout<<q.pop()<<" ";
	}
	return 0;
}
























