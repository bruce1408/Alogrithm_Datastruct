#include <iostream>
#include <vector>
#include <queue>
#include <deque>
using namespace std;

void showq(queue<int> gq)
{
	queue<int> g = gq;
	while (!g.empty())
	{
		cout << g.front() << " ";
		g.pop();
	}
	cout << '\n';
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
	for (int i = 0; i < 5; i++)
	{
		cout << p.top() << " ";
		p.pop();
	}
	cout << endl;
}

/**
 * 例子 2，优先队列输出从小到大的顺序，使用greater<int>来说明,
 * 或者自己定义一个排序方案，cmp，return x < y,大的在前，返回逆序排列，和sort的自定义排序正好相反
*/
struct cmp
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
// struct Node
// {
// 	int x, y;
// 	Node(int a = 0, int b = 0) : x(a), y(b) {}
// };

// struct cmp
// {
// 	bool operator()(Node a, Node b)
// 	{
// 		if (a.x == b.x)
// 			return a.y > b.y;
// 		return a.x > b.x;
// 	}
// };

int main()
{
	// priority_queue<Node, vector<Node>, cmp> p;

	// for (int i = 0; i < 10; ++i)
	// 	p.push(Node(10 - i, i));

	// while (!p.empty())
	// {
	// 	cout << p.top().x << ' ' << p.top().y << endl;
	// 	p.pop();
	// }
	coutBigNum();
	coutSmallNum();
	return 0;
}

// int main()
// {
// 	// queue<int> gquiz;
// 	// gquiz.push(10);
// 	// gquiz.push(20);
// 	// gquiz.push(30);
// 	// cout << "The queue gquiz is : ";
// 	// showq(gquiz);
// 	// cout << "\ngquiz.size() : " << gquiz.size();
// 	// cout << "\ngquiz.front() : " << gquiz.front();
// 	// cout << "\ngquiz.back() : " << gquiz.back();
// 	// cout << "\ngquiz.pop() : ";
// 	// gquiz.pop();
// 	// showq(gquiz);
// 	coutBigNum(); // 优先队列降序输出
// 	coutSmallNum(); // 优先队列升序输出
// 	return 0;
// }

/**
 * 优先队列基本使用
*/
// #include <stdio.h>
// #include<iostream>
// #include <functional>
// #include <queue>
// #include <vector>
// using namespace std;
// //定义结构，使用运算符重载,自定义优先级1
// struct cmp1
// {
// 	bool operator()(int &a, int &b)
// 	{
// 		return a > b; //最小值优先
// 	}
// };
// struct cmp2
// {
// 	bool operator()(int &a, int &b)
// 	{
// 		return a < b; //最大值优先
// 	}
// };
// //定义结构，使用运算符重载,自定义优先级2
// struct number1
// {
// 	int x;
// 	bool operator<(const number1 &a) const
// 	{
// 		return x > a.x; //最小值优先
// 	}
// };
// struct number2
// {
// 	int x;
// 	bool operator<(const number2 &a) const
// 	{
// 		return x < a.x; //最大值优先
// 	}
// };
// int a[] = {14, 10, 56, 7, 83, 22, 36, 91, 3, 47, 72, 0};
// number1 num1[] = {14, 10, 56, 7, 83, 22, 36, 91, 3, 47, 72, 0};
// number2 num2[] = {14, 10, 56, 7, 83, 22, 36, 91, 3, 47, 72, 0};

// int main()
// {
// 	priority_queue<int> que; //采用默认优先级构造队列

// 	priority_queue<int, vector<int>, cmp1> que1; //最小值优先
// 	priority_queue<int, vector<int>, cmp2> que2; //最大值优先

// 	priority_queue<int, vector<int>, greater<int>> que3; //注意“>>”会被认为错误，
// 														 //这是右移运算符，所以这里用空格号隔开
// 	priority_queue<int, vector<int>, less<int>> que4;	 ////最大值优先

// 	priority_queue<number1> que5;
// 	priority_queue<number2> que6;

// 	int i;
// 	for (i = 0; a[i]; i++)
// 	{
// 		que.push(a[i]);
// 		que1.push(a[i]);
// 		que2.push(a[i]);
// 		que3.push(a[i]);
// 		que4.push(a[i]);
// 	}
// 	for (i = 0; num1[i].x; i++)
// 		que5.push(num1[i]);
// 	for (i = 0; num2[i].x; i++)
// 		que6.push(num2[i]);

// 	printf("采用默认优先关系:\n(priority_queue<int>que;)\n");
// 	printf("Queue 0:\n");
// 	while (!que.empty())
// 	{
// 		printf("%3d", que.top());
// 		que.pop();
// 	}
// 	puts("");
// 	puts("");

// 	printf("采用结构体自定义优先级方式一:\n(priority_queue<int,vector<int>,cmp>que;)\n");
// 	printf("Queue 1:\n");
// 	while (!que1.empty())
// 	{
// 		printf("%3d", que1.top());
// 		que1.pop();
// 	}
// 	puts("");
// 	printf("Queue 2:\n");
// 	while (!que2.empty())
// 	{
// 		printf("%3d", que2.top());
// 		que2.pop();
// 	}
// 	puts("");
// 	puts("");
// 	printf("采用头文件\"functional\"内定义优先级:\n(priority_queue<int,vector<int>,greater<int>/less<int> >que;)\n");
// 	printf("Queue 3:\n");
// 	while (!que3.empty())
// 	{
// 		printf("%3d", que3.top());
// 		que3.pop();
// 	}
// 	puts("");
// 	printf("Queue 4:\n");
// 	while (!que4.empty())
// 	{
// 		printf("%3d", que4.top());
// 		que4.pop();
// 	}
// 	puts("");
// 	puts("");
// 	printf("采用结构体自定义优先级方式二:\n(priority_queue<number>que)\n");
// 	printf("Queue 5:\n");
// 	while (!que5.empty())
// 	{
// 		printf("%3d", que5.top());
// 		que5.pop();
// 	}
// 	puts("");
// 	printf("Queue 6:\n");
// 	while (!que6.empty())
// 	{
// 		printf("%3d", que6.top());
// 		que6.pop();
// 	}
// 	puts("");
// 	return 0;
// }
/*
运行结果 ：
采用默认优先关系:
(priority_queue<int>que;)
Queue 0:
83 72 56 47 36 22 14 10  7  3
  
采用结构体自定义优先级方式一:
(priority_queue<int,vector<int>,cmp>que;)
Queue 1:
 7 10 14 22 36 47 56 72 83 91
Queue 2:
83 72 56 47 36 22 14 10  7  3
  
采用头文件"functional"内定义优先级:
(priority_queue<int,vector<int>,greater<int>/less<int> >que;)
Queue 3:
 7 10 14 22 36 47 56 72 83 91
Queue 4:
83 72 56 47 36 22 14 10  7  3
  
采用结构体自定义优先级方式二:
(priority_queue<number>que)
Queue 5:
 7 10 14 22 36 47 56 72 83 91
Queue 6:
83 72 56 47 36 22 14 10  7  3
*/

/**
 * 双端队列，两端元素都可以进行添加和删除，不像vector一样
 * 会把所有的对象保存在一个连续的内存块中，而是多个连续内存块映射
 * deque的内存区块不再被使用时，会被释放
 * 最好采用deque的情形如下：
 * 
 * 1、需要在两端插入和删除元素。
 * 2、无需引用容器内的元素。
 * 3、要求容器释放不再使用的元素。
*/
// int main()
// {
//     deque<int> mydeque;
//     // 1 2 3 4 5
//     for (int i = 1; i < 6; i++)
//         mydeque.push_back(i);
//     deque<int>::iterator it = mydeque.begin();
//     ++it;
//     // 1 10 2 3 4 5
//     it = mydeque.insert(it, 10);
//     // "it" now points to the newly inserted 10
//     // 1 20 20 10 2 3 4 5
//     mydeque.insert(it, 2, 20);
//     // "it" no longer valid!
//     it = mydeque.begin() + 2;
//     vector<int> myvector(2, 30);
//     cout << myvector.size() << endl;
//     mydeque.insert(it, myvector.begin(), myvector.end());
//     cout << "mydeque contains:";
//     for (it = mydeque.begin(); it != mydeque.end(); ++it)
//         cout << ' ' << *it;
//     cout << '\n';
//     return 0;
// }

// #include <iostream>
// #include <deque>
// using namespace std;
// int main()
// {
//     deque<int> a;
//     for (int i = 0; i < 5; i++)
//         a.push_back(i);
//     deque<int>::iterator it;
//     it = a.begin();
//     for (; it != a.end(); it++)
//     {
//         cout << *it << endl;
//         a.erase(it);
//     }
//     return 0;
// }
