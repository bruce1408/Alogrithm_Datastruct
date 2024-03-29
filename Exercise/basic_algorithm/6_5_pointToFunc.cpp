#include<iostream>
using namespace std;
/**
 * 指向函数的指针：它的作用就是为了实现函数的回调, 主要是用来调用的，否则就是返回的是一个指针。
*/
int comput(int a,int b,int (*func)(int, int))
{
	return func(a,b);
}

int sum(int a,int b)
{
	return a+b;
}

int max(int a,int b)
{return ((a>b)?a:b);}

int min(int a,int b)
{return ((a<b)?a:b);}

int main()
{
	cout<<"max:"<<comput(3,8,&max)<<endl;
	cout<<"min:"<<comput(3,8,&min)<<endl;
	cout<<"sum:"<<comput(3,8,&sum)<<endl;
	return 0;
}