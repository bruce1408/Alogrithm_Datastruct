/*最小栈的算法非常精妙，非常好。*/
#include<iostream>
#include<stack>
using namespace std;

// class MinStack
// {
	
	// public:
	// MinStack() {}
	
	// void push(int x)
	// {
		// s1.push(x);
		// if(s2.empty()||x<=s2.top())
		// {s2.push(x);}
	// }
	
	// void pop()
	// {
		// if(!s1.empty())
		// {
			// if(s1.top()==s2.top())//
				// s2.pop();
			// s1.pop();
		// }
		
	// }
	
	// int top()
	// {
		// if(!s1.empty())
		// {
			// return s1.top();
		// }
		
	// }
	
	// int getMin()
	// {
		
		// return s2.top();
		// /**自己写的这部分只适合一个不变的stack来做，而且会每次删除s2*/
		// // int x = 0;
		// // while(!s2.empty())
		// // {
			
			// // int y = s2.top();
			// // if(y<x)
			// // {
				// // x = y;
			// // }
			// // s2.pop();
			
		// // }
		
		// // return x;
	// }
	
	// bool empty()
	// {return s1.empty();}
	
	
	// private:
	// stack<int> s1,s2;
	
// };


class MinStack 
{
	public:
    /** initialize your data structure here. */
    MinStack() 
	{
        min_val = INT_MAX;
    }
    
    void push(int x) 
	{
        if (x <= min_val) 
		{
            st.push(min_val);
            min_val = x;
        }
        st.push(x);
    }
    
    void pop() 
	{
        int t = st.top(); st.pop();
        if (t == min_val) {
            min_val = st.top(); st.pop();
        }
    }
    
    int top() 
	{
        return st.top();
    }
    
    int getMin() 
	{
        return min_val;
    }
	
	private:
    int min_val;
    stack<int> st;
};



int main()
{
	MinStack s;
	int num ;
	cout<<"请输入个数："<<endl;
	cin>>num;
	while(num--)
	{
		int a;
		cin>>a;
		s.push(a);
	}
	
	cout<<"最小的数字是："<<s.getMin()<<endl;
	cout<<"栈顶元素是："<<s.top()<<endl;
	cout<<"删除栈顶一个元素之后："<<endl;
	s.pop();
	cout<<"栈顶元素是："<<s.top()<<endl;
	// cout<<"s 是否为空："<<s.empty()<<endl;
	cout<<"最小的数字是："<<s.getMin()<<endl;
	cout<<"栈顶的元素是："<<s.getMin()<<endl;
	
	
	return 0;
	
}