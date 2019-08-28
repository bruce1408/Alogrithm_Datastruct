#include<iostream>
#include<vector>
#include<stack>
using namespace std;

//method1 with 2 stack
/*最小栈的算法非常精妙，非常好。*/
#include<iostream>
#include<stack>
using namespace std;


// method1 用两个栈，思路就是辅助栈只存放最小的数值，如果出栈的话，当前值和辅助栈的top一样，
//那么就一起出栈。
// the second stack is fill the min value

// class MinStack
// {
// 	public:
// 	MinStack() {}
	
// 	void push(int x)
// 	{
// 		s1.push(x);
// 		if(s2.empty()||x<=s2.top())  s2.push(x);
// 	}
	
// 	void pop()
// 	{
// 		if(!s1.empty())
// 		{
// 			if(s1.top()==s2.top())
// 				s2.pop();
// 			s1.pop();
// 		}
		
// 	}
	
// 	int top()
// 	{
// 		if(!s1.empty())  return s1.top();
// 	}
	
// 	int getMin()
// 	{
// 		return s2.top();
// 	}
	
// 	bool empty()
// 	{return s1.empty();}
	
	
// 	private:
// 	stack<int> s1,s2;
	
// };


//method2 only with one stack to implement
// 一个栈的思路是设置一个最小值，新入栈的值只要是小于等于我当前的最小值，
//就把原来的最小值入栈，并且再把新值入栈，
class MinStack
{
public:
    /** initialize your data structure here. */
    MinStack() {
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
    //出栈是先直接出top的值，然后如果出栈的值和最小值相等，就是再出一次，因为(最为最小值)本身入栈了两次。
    void pop() 
	{
        int t = st.top(); st.pop();
        if (t == min_val) {
            min_val = st.top(); st.pop();
			cout<<"the min value is"<<min_val<<endl;
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
	int num;
	cout<<"请输入栈元素的个数："<<endl;
	cin>>num;
	cout<<"输入栈元素"<<endl;
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
	// cout<<"栈顶的元素是："<<s.getMin()<<endl;

	return 0;
	
}


























