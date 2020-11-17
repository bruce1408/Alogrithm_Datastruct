#include<iostream>
using namespace std;
/**
 * 指针保存的就是变量的地址;
*/
void pointer_level_1()
{
	//单独给a，b指针，然后让a，b指向空NULL，然后依然不能赋值；但是new可以。
	int* a = new int;
	int* b = new int;
	*a = 10;
	*b = 11;
	cout << *a << endl;
	cout << *b << endl;
	delete a;
	a = nullptr;
	delete b;
	b = nullptr;
}


void pointer_level_2()
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
}


int main()
{
	pointer_level_1();
	pointer_level_2();
}