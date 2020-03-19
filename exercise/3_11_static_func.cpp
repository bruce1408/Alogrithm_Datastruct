/*
	static 在函数体内被声明为静态变量，在函数调用的过程中保持不变，
	在模块内，函数体外，可以被模块内的所有函数调用，但不能被外部的函数访问。
	在模块内的声明为静态的函数，可以被所有模块内的函数调用，但是只能在模块内部使用。
	
	
	static 全局变量和普通全局变量的区别是只能初始化一次
	static 局部变量和普通局部变量的区别是只能被初始化一次
	static 函数和普通函数的区别是在内存中只有一份，普通函数在每个被调用中维持一份复制。
*/
#include <iostream>
using namespace std;

class Point {
	//Point类定义
	public:       //外部接口
    Point(int x = 0, int y = 0) : x(x), y(y) { //构造函数
    //在构造函数中对count累加，所有对象共同维护同一个count
    count++;
    }
    Point(Point &p) {    //复制构造函数
    x = p.x+1;
    y = p.y+2;
    count++;
    }
	
    ~Point() {  count--; }//析构函数 每次减一
    int getX() { return x; }
    int getY() { return y; }
	static void showCount() {           //输出静态数据成员
    cout << "  Object count = " << count << endl;
    }
	private:      //私有数据成员
    int x, y;
    static int count;       //静态数据成员声明，用于记录点的个数
};

int Point::count = 0;//静态数据成员定义和初始化，使用类名限定, 必须在类外初始化和定义
int main() 
{  

     //主函数
	   Point::showCount();
       Point a(4, 5);     //定义对象a，其构造函数会使count增1
       cout << "Point A: " << a.getX() << ", " << a.getY();
       Point::showCount(); //输出对象个数
 
       Point b(a); //定义对象b，其构造函数回使count增1
       cout << "Point B: " << b.getX() << ", " << b.getY();
       b.showCount();       //输出对象个数
	   
       return 0;
}










