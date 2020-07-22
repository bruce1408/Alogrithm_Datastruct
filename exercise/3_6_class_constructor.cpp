#include <iostream>
using namespace std;

// class Clock
// {

// 	public:
// 	Clock(int newH, int newM, int newS);//构造函数的原型声明
// 	Clock()=default;
// 	void setTime(int newH, int newM, int newS);
// 	void showTime();
// 	private:
// 	int hour,minute,second;

// };

// //构造函数的实现,简单的赋值，初始化列表
// Clock::Clock(int newH, int newM, int newS):hour(newH),minute(newM),second(newS){}
// // Clock::Clock():hour(0),minute(0),second(0){}

// //成员函数的实现
// //类名 限定符
// void Clock::setTime(int newH, int newM, int newS)
// {
// 	hour = newH;
// 	minute = newM;
// 	second = newS;

// }

// void Clock::showTime()
// {
// 	cout<<hour<<":"<<minute<<":"<<second<<endl;
// }

// int main()
// {
// 	Clock c(0,0,0);
// 	c.showTime();
// 	Clock a(2,3,4);
// 	a.showTime();

// 	Clock b;
// 	b.showTime();
// 	return 0;
// }

class Csample
{
	int x;

public:
	Csample()
	{
		cout << "constructor 1  called " << endl;
	}
	Csample(int n)
	{
		x = n;
		cout << "consturctor 2 called" << endl;
		cout << x << endl;
	}
};
// class Test
// {
// 	public:
// 	Test(int n){cout<<"test 1:"<<endl;}
// 	Test(int n,int m){cout<<"test 2:"<<endl;}
// 	Test(){}
// };
// Test array1[3] = {1, Test(1, 2)};
// Test array2[3] = {Test(2, 3), Test(1, 2), 1};
// Test *parray[3] = {new Test(4), new Test(1, 2)};

int main()
{
	Csample array1[2];
	Csample hell(2);
	cout << "step1" << endl;
	Csample array2[2] = {4, 5};
	cout << "step2" << endl;
	Csample array3[2] = {2};
	cout << "step3" << endl;
	Csample *array4 = new Csample[2];
	delete[] array4;
	return 0;
}
