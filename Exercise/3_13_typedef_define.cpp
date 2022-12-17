/*下面代码是讲解typedef 和 define 的区别
  define 宏定义，不需要编译，傻瓜式的替换，
  #define不只是可以为类型取别名，还可以定义常量、变量、编译开关等
  #define没有作用域的限制，只要是之前预定义过的宏，在以后的程序中都可以使用
  typedef用来定义类型的别名，定义与平台无关的数据类型，与struct的结合使用等。
  typedef 是需要编译的，有自己的作用域
  二者修饰指针类型时，作用不同。 
  */
#include<iostream>
using namespace std;
#define int_define int*
typedef int* int_pre;





//define 不受作用域的限制
void func1()
{
	#define HW "HelloWorld";
}

void func2()
{
	string str = HW;
	cout << str << endl;
}



int main()
{
	int a = 1,b = 2;
	const int_pre p1 = &a; //相当于是int* const p1；
	const int_define p2;   //相当于是const int* p2；
	
	p2 = &a;
	cout<<*p2<<endl;
	p2 = &b;
	cout<<*p2<<endl;
	// *p2 = 10;
	cout<<*p1<<endl;
	// p1 = &b;
	*p1 = 100;
	cout<<*p1<<endl;
	
	
	
	func2();
	return 0;
}