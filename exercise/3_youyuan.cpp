#include<iostream>
#include<cmath>
using namespace std;

class Point{
	public:
	Point(int xx=0,int yy=0):x(xx),y(yy){}
	int getX(){return x;}
	int getY(){return y;}
	friend float dist(Point &a,Point &b);
	private:
	int x,y;
};


float dist(Point &a,Point &b)
{
	double x = a.x - a.y;
	double y = b.x - b.y;
	return sqrt(x*x + y*y);
}


int main()
{
	Point a(3,4);
	Point b(4,5);
	cout<<"dist is:"<<endl;
	cout<<dist(a,b)<<endl;
	
	return 0;
	
}