/*一般情况下main运行结束，程序结束，但是atexit()函数是main执行完后还会执行，他就是程序正常终止时还会被调用的函数
	该函数的参数是函数指针，函数指针指向一个没有参数也没有返回值的函数。*/

#include<iostream>
using namespace std;


void fun1(void);
void fun2(void);
int main()
{
	atexit(fun1);
	atexit(fun2);
	cout<<"main function is over:"<<endl;
	return 0;
}


void fun1()
{
	cout<<"fun1 is calling:"<<endl;
}


void fun2()
{
	cout<<"fun2 is calling:"<<endl;
}