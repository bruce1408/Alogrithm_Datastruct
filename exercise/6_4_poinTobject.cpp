#include<iostream>
using namespace std;
/**
 * 对象指针；类名 *对象指针名
*/
class Point
{
	public:
	Point(int x=0,int y=0):x(x),y(y){}  //初始化列表
	int getX(){return x;}
	int getY(){return y;}
	private:
	int x;
	int y;
};


int main()
{
	Point a(4,6);
	Point *p1 = &a;//对象指针，用a的成员函数，或者是指针指向成员函数。(*p1).getX()
	cout<<a.getX()<<endl;
	//两种方式来调用函数
	cout<<(*p1).getX()<<endl;//解引用，然后再访问成员函数。
	cout<<p1->getX()<<endl;
	return 0;
}