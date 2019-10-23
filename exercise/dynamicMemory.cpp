#include<iostream>
#include<string>
using namespace std;

// 动态内存分配
/*
第一种是分配一个变量
*/
int main()
{
	int *a = new int;//默认初始化 随机给
	int *b = new int();//是0
	string *c = new string;//空
	string *d = new string();//空
	int *e = new int[20];
	e[0] = 20;

	
	
	// auto e = new auto(string);
	
	
	cout<<"a:"<<*a<<endl;
	cout<<"b:"<<*b<<endl;
	cout<<"c:"<<*c<<endl;
	cout<<"d:"<<*d<<endl;
	cout<<e[0]<<endl;
	// cout<<"e:"<<*e<<endl;
	
	delete a;	
	delete b;	
	delete c;	
	delete d;
	delete []e;
	// delete e;
	
	
	int *p = (int *)malloc(sizeof(int)*5);
	cout<<"input 5 num:"<<endl;
	for (int i =0;i<5;++i)
		*(p+i) = i;
	for(int j=0;j<5;++j)
		cout<<*(p+j)<<endl;
		
	free(p);
	return 0;
	
}