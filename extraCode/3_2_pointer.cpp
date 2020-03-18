
#include<iostream>
using namespace std;

int main()
{
	int a = 1;
	int b =10;
	int *p = &a;
	int *&pa = p;
	(*pa)++;
	cout<<"a=:"<<a<<endl;
	cout<<"b=:"<<b<<endl;
	cout<<"*pa= :"<<*p<<endl;
	pa = &b;
	(*pa)++;
	cout<<"a=:"<<a<<endl;
	cout<<"b=:"<<b<<endl;
	cout<<*p<<endl;
	
	return 0;
	
}