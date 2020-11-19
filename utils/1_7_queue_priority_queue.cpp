#include <iostream>
#include <vector>
#include <deque>
#include <stdio.h>
#include <functional>
#include <queue>
using namespace std;
/**
 * 队列学习queue函数：
 * top 访问队头元素
 * empty 队列是否为空
 * size 返回队列内元素个数
 * push 插入元素到队尾 (并排序)
 * emplace 原地构造一个元素并插入队列
 * pop 
 * queue 和 stack 有一些成员函数相似，但在一些情况下，工作方式有些不同：
 * front()：返回 queue 中第一个元素的引用。如果 queue 是常量，就返回一个常引用；如果 queue 为空，返回值是未定义的。
 * back()：返回 queue 中最后一个元素的引用。如果 queue 是常量，就返回一个常引用；如果 queue 为空，返回值是未定义的。
 * push(const T& obj)：在 queue 的尾部添加一个元素的副本。这是通过调用底层容器的成员函数 push_back() 来完成的。
 * push(T&& obj)：以移动的方式在 queue 的尾部添加元素。这是通过调用底层容器的具有右值引用参数的成员函数 push_back() 来完成的。
 * pop()：删除 queue 中的第一个元素，
 * size()：返回 queue 中元素的个数。
 * empty()：如果 queue 中没有元素的话，返回 true。
 * emplace()：用传给 emplace() 的参数调用 T 的构造函数，在 queue 的尾部生成对象。
 * swap(queue<T> &other_q)：将当前 queue 中的元素和参数 queue 中的元素交换。它们需要包含相同类型的元素。
 * 也可以调用全局函数模板 swap() 来完成同样的操作。
 * 
 * 定义：priority_queue<Type, Container, Functional>
*/

void print(queue<int> gq)
{
	queue<int> g = gq;
	while (!g.empty())
	{
		cout << g.front() << " ";
		g.pop();
	}
	cout << '\n';
}

void print(priority_queue<int> q)
{
    while(!q.empty())
    {
        cout<<q.top()<<" ";
        q.pop();
    }
    cout<<endl;
}

/**
 * 例子 1，优先队列的用法，默认是输出大顶堆，也就是从大到小的顺序
 */
void coutBigNum()
{
	priority_queue<int> p;
	p.push(1);
	p.push(2);
	p.push(8);
	p.push(5);
	p.push(43);
	print(p);
	cout << endl;
}

/**
 * 例子 2，优先队列输出从小到大的顺序，使用greater<int>来说明,
 * 或者自己定义一个排序方案，cmp，return x < y,大的在前，返回逆序排列，和sort的自定义排序正好相反
*/
struct cmp // 重写仿生函数
{
	bool operator()(int x, int y)
	{
		return x < y;
	}
};

void coutSmallNum()
{
	priority_queue<int, vector<int>, cmp> p;
	p.push(1);
	p.push(2);
	p.push(8);
	p.push(5);
	p.push(43);
	cout << "the greater is:" << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << p.top() << " ";
		p.pop();
	}
	cout << endl;
}

/**
 * 例子 3，自定义优先级别
*/
struct Node
{
	int x, y;
	Node(int a = 0, int b = 0) : x(a), y(b) {}
};

struct cmp1 // 重写仿生函数
{
	bool operator()(Node a, Node b)
	{
		if (a.x == b.x)
			return a.y > b.y;
		return a.x > b.x;
	}
};



/**
 * 优先队列基本使用
*/

//定义结构，使用运算符重载,自定义优先级1
struct cmp2
{
	bool operator()(int &a, int &b)
	{
		return a > b; //最小值优先
	}
};

struct cmp3
{
	bool operator()(int &a, int &b)
	{
		return a < b; //最大值优先
	}
};
//定义结构，使用运算符重载,自定义优先级2
struct number1
{
	int x;
	bool operator<(const number1 & a) const
	{
		return x > a.x; //最小值优先
	}
};

struct number2
{
	int x;
	bool operator<(const number2 &a) const
	{
		return x < a.x; //最大值优先
	}
};

void priority_queue_example()
{
	int a[] = {14, 10, 56, 7, 83, 22, 36, 91, 3, 47, 72, 0};
	number1 num1[] = {14, 10, 56, 7, 83, 22, 36, 91, 3, 47, 72, 0};
	number2 num2[] = {14, 10, 56, 7, 83, 22, 36, 91, 3, 47, 72, 0};
	priority_queue<int> que; //采用默认优先级构造队列

	priority_queue<int, vector<int>, cmp2> que1; //最小值优先
	priority_queue<int, vector<int>, cmp3> que2; //最大值优先

	priority_queue<int, vector<int>, greater<int>> que3; //注意“>>”会被认为错误，这是右移运算符，所以这里用空格号隔开，从小到大
	priority_queue<int, vector<int>, less<int>> que4;	 // 从大到小

	priority_queue<number1> que5;
	priority_queue<number2> que6;

	int i;
	for (i = 0; a[i]; i++)
	{
		que.push(a[i]);
		que1.push(a[i]);
		que2.push(a[i]);
		que3.push(a[i]);
		que4.push(a[i]);
	}
	for (i = 0; num1[i].x; i++)
		que5.push(num1[i]);
	for (i = 0; num2[i].x; i++)
		que6.push(num2[i]);

	printf("采用默认优先关系:\n(priority_queue<int>que;)\n");
	printf("Queue 0:\n");
	while (!que.empty())
	{
		printf("%3d", que.top());
		que.pop();
	}
	puts("");
	puts("");

	printf("采用结构体自定义优先级方式一:\n(priority_queue<int,vector<int>,cmp>que;)\n");
	printf("Queue 1:\n");
	while (!que1.empty())
	{
		printf("%3d", que1.top());
		que1.pop();
	}
	puts("");
	printf("Queue 2:\n");
	while (!que2.empty())
	{
		printf("%3d", que2.top());
		que2.pop();
	}
	puts("");
	puts("");
	printf("采用头文件\"functional\"内定义优先级:\n(priority_queue<int,vector<int>,greater<int>/less<int> >que;)\n");
	printf("Queue 3:\n");
	while (!que3.empty())
	{
		printf("%3d", que3.top());
		que3.pop();
	}
	puts("");
	printf("Queue 4:\n");
	while (!que4.empty())
	{
		printf("%3d", que4.top());
		que4.pop();
	}
	puts("");
	puts("");
	printf("采用结构体自定义优先级方式二:\n(priority_queue<number>que)\n");
	printf("Queue 5:\n");
	while (!que5.empty())
	{
		printf("%3d", que5.top());
		que5.pop();
	}
	puts("");
	printf("Queue 6:\n");
	while (!que6.empty())
	{
		printf("%3d", que6.top());
		que6.pop();
	}
	puts("");
}


int main()
{
	priority_queue<Node, vector<Node>, cmp1> p;

	for (int i = 0; i < 10; ++i)
		p.push(Node(10 - i, i*10));

	while (!p.empty())
	{
		cout << p.top().x << ' ' << p.top().y << endl;
		p.pop();
	}
	coutBigNum();
	coutSmallNum();
	priority_queue_example();
	return 0;
}