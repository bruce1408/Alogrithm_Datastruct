#include <stack>
#include <iostream>
using namespace std;

/**
 * 232 使用栈来实现队列
 * 此题目的是实现队列，我们可以用链表，但是此题需要用栈来实现，
 * 栈的特点是后进先出，而队列是先进先出的形式，所以思路就是用两个栈来相互保存。这样才能实现此功能！
 */

/**
 * 方法 1，使用两个栈*
 */
class MyQueue
{
public:
    /** Initialize your data structure here. */
    stack<int> a, b;
    MyQueue()
    {
    }

    /** Push element x to the back of queue. */
    void push(int x)
    {
        a.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop()
    {
        while (a.size() > 1)
        {
            b.push(a.top());
            a.pop();
        }
        int t = a.top();
        a.pop();
        while (b.size())
        {
            a.push(b.top());
            b.pop();
        }
        return t;
    }

    /** Get the front element. */
    int peek()
    {
        while (a.size() > 1)
        {
            b.push(a.top());
            a.pop();
        }
        int t = a.top();
        while (b.size())
        {
            a.push(b.top());
            b.pop();
        }
        return t;
    }
    /** Returns whether the queue is empty. */
    bool empty()
    {
        return a.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
