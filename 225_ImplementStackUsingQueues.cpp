#include<iostream>
#include<queue>
using namespace std;


/*第一种方法*/
class MyStack {
  private:
    queue<int> myQueue;

  public:
    /** Initialize your data structure here. */
    MyStack() {}

    /** Push element x onto stack. */
    void push(int x) { myQueue.push(x); }

    /** Removes the element on top of the stack and returns that element. */
    int pop()
	{
        // int x = myQueue.back();
        int len = myQueue.size();
        for (int i = 0; i < len - 1; ++i) 
		{
            myQueue.push(myQueue.front());
            myQueue.pop();
        }
		int x = myQueue.front();//尽量不用back()函数;使用front()函数;
		myQueue.pop();
		return x;
	}
		
		
    int top() 
	{
		return myQueue.back();  
	}

    /** Get the top element. */

    /** Returns whether the stack is empty. */
    bool empty() { return myQueue.empty(); }
};



/*第二种方法,这种算法太经典了！就是把所有输入的书全部反序排列*/

class MyStack_0 {
	public:
	MyStack_0() {}

    // Push element x onto stack.
	/** 很关键的算法，让输入的数倒序*/
    void push(int x) 
	{
        
        while (!q.empty()) 
		{
            qtmp.push(q.front());
            q.pop();
        }
        q.push(x);
        while (!qtmp.empty())
		{
            q.push(qtmp.front());
            qtmp.pop();
        }
    }

    // Removes the element on top of the stack.
    void pop() {
        q.pop();
    }

    // Get the top element.
    int top() {
        return q.front();
    }

    // Return whether the stack is empty.
    bool empty() {
        return q.empty();
    }
    
private:
    queue<int> q;
	queue<int> qtmp;
};





int main()
{
	// MyStack input;
	MyStack input;
	cout<<"输入数字："<<endl;
	int num;
	while(cin>>num)
	{
		input.push(num);
	}
	
	cout<<"栈顶的元素是："<<input.top()<<endl;
	// cout<<"栈的pop功能实现是："<<input.pop()<<endl;
	
	while(!input.empty())
	{
		cout<<input.top()<<" ";
		input.pop();
	}
	cout<<endl;
	if(input.empty())
		cout<<"当前的队列是empty"<<endl;
	
	return 0;
}
