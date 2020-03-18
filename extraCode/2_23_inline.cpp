/**
 * 内联函数和宏定义比起来更有优势，内联是在编译时展开，宏是在预编译时候展开。
 * 内联函数实现了宏的有点，效率高，他执行的是内敛调用的机制，而不是正常函数调用机制，所以效率高，
 * 但是内敛是以代码膨胀为代价的，就是虽然省去了函数调用的开销，但是每一次内联函数调用都要复制代码，如果你函数体执行的时间远大于调用的时间，那么
 * 内联的意义不大，反而会消耗更多空间，一般不超过10行，没有for循环就可以用内联。
 * https://blog.csdn.net/u011327981/article/details/50601800
 * 
 * */

#include <iostream>
using namespace std;
class A
{
	public:
	inline int add(int a, int b)
	{
		return (a + b);
	}
};

// class A
// {
// 	public:
//     int add(int a, int b);
// };

// inline int A::add(int a, int b)
// {
//    return (a + b);
// }

int main()
{
	A a;
	cout << a.add(3, 5) << endl;
}