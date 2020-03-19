/**
 * 常数据成员，常量必须要在初始化列表中对它进行赋值。
 * a(i) 这种赋值，不能是在大括号体内。
 * */
#include<iostream>
using namespace std;

class A{
	public:
	A(int i);
	void print();
	private:
	const int a;
	static const int b;
};

const int A::b =10;
A::A(int i):a(i){} 
// A::A(int i){a = i;}

void A::print(){
	cout<<a<<":"<<b<<endl;
}

int main()
{
	A a1(100),a2(20);
	a1.print();
	a2.print();
	return 0;
}