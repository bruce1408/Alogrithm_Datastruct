/*c++继承问题：
  主要是讲派生和继承
  本节的问题
  1、是二义性，怎么解决，
  2、是派生类不会继承基类的构造函数和析构函数，如何解决*/
  
/*二义性问题解决方法之一：作用域限定，如果派生类和基类有相同的成员时，
 未特别限定时，通过派生类对象使用的是派生类的同名成员，这时候会屏蔽基
 类同名的成员函数，如果想要访问基类的成员函数，那么就应该限定基类 */
#include<iostream>
using namespace std;
class Base1
{
	public:
	int val;
	void fun(){cout<<"fun of base1"<<endl;}
	
};

class Base2
{
	public:
	int val;
	void fun(){cout<<"fun of base2"<<endl;}
	
};

/*这种情况是派生类中有基类的同名函数，不会产生二义性，只需要用限定符来
  访问基类的同名函数，但是，如果派生类没有定义同名函数，且从不同基类继承了
  同名函数，那么这时候会产生二义性！！*/
class Derived:public Base1,public Base2
{
	public:
	int val;
	void fun()
	{
		cout<<"fun of derived"<<endl;
	}
};


int main()
{
	Derived d;
	Derived *p = &d;
	d.val = 1;
	d.fun();//直接访问的是派生类的成员函数；
	
	d.Base1::val = 2;
	d.Base1::fun();//通过限定符来访问基类的同名函数，
	
	
	p->Base2::val =3;
	p->Base2::fun();
	
	return 0;
}

//
