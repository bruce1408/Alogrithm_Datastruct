#include<iostream>
#include<cmath>
using namespace std;

class Point
{
	
	public:
	Point(int xx=0, int yy=0){x = xx;y = yy;}
	Point(const Point &p);
	int getX(){return x;}
	int getY(){return y;}
	
	private:
	int x;
	int y;
};


Point::Point(const Point&p)
{
	x = p.x;
	y = p.y;
}



class Line 
{

	public:	//外部接口
	Line(Point xp1, Point xp2);
	Line(Line &l);//复制构造函数
	double getLen() { return len; }
	private:	//私有数据成员
	Point p1, p2;	//Point类的对象p1,p2
	double len;
};


/*初始化列表和单一的赋值其实都是一样的*/
// Line::Line(Point xp1, Point xp2) : p1(xp1), p2(xp2) {
Line::Line(Point xp1, Point xp2) {
p1 = xp1;
p2 = xp2;	
cout << "Calling constructor of Line" << endl;
double x = static_cast<double>(p1.getX() - p2.getX());
double y = static_cast<double>(p1.getY() - p2.getY());
len = sqrt(x * x + y * y);

}

Line::Line (Line &l): p1(l.p1), p2(l.p2) {//组合类的复制构造函数
cout << "Calling the copy constructor of Line" << endl;
len = l.len;
}


int main() 
{
	Point myp1(1, 1), myp2(4, 5);	//建立Point类的对象
	Line line(myp1, myp2);	//建立Line类的对象
	Line line2(line);	//利用复制构造函数建立一个新对象
	cout << "The length of the line is: ";
	cout << line.getLen() << endl;
	cout << "The length of the line2 is: ";
	cout << line2.getLen() << endl;
	return 0;
}















