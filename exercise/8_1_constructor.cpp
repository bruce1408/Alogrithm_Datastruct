#include<iostream>
#include<cstring>
using namespace std;
// class Point
// {
	// public:
	
	// // Point(int x, int y)
	// // {
		// // cout<<"创建完毕："<<endl;
		// // xx = x;
		// // yy = y;
		
	// // }
	
	// Point(int x=0,int y=0)
	// {
		// cout<<"创建完毕："<<endl;
		// xx = x;
		// yy = y;
		
	// }
	// void print()
	// {
		// cout<<xx<<" "<<yy<<endl;
		
		
	// }
	// private:
	// int xx;
	// int yy;
// };

// int main()
// {
	// // Point p;
	
	// Point p1(3,4);
	// // Point p(3);
	// Point p2;
	// Point p3(3);
	
	// return 0;
	
	
// }



/*析构函数的例子*/
// class computer
// {
	// private:
	// char *brand;
	// float price;
	
	// public:
	// computer(const char *sz,float p)
	// {
		// brand = new char[strlen(sz)+1];
		// strcpy(brand,sz);
		// price = p;
	// }
	// ~computer()
	// {
		// delete[] brand;
		// cout<<"清理现场："<<endl;
		
	// }
	
	// void print()
	// {
		// cout<<"brand:"<<brand<<endl;
		// cout<<"price:"<<price<<endl;
	// }
// };


// int main()
// {
	// computer comp("dell",900);
	// comp.print();
	// comp.~computer();//可以显示调用，但是构造函数不能显示调用！
	// return 0;
// }


/*这个例子的目的是数据成员是const类型和引用类型的时候，
  则一定要用初始化列表来赋值，不能用构造函数那一套；会出错！*/
class point
{
	private:
	const int xx;//这是const类型的数据成员
	const int yy;
	int &zz;//这是引用数据类型的数据成员；
	public:
	point(int x,int y,int z):xx(x),yy(y),zz(z)
	{
		cout<<"构造函数调用开始："<<endl;
	}
	
	point(const point &pt):xx(pt.xx),yy(pt.yy),zz(pt.zz)
	{
		cout<<"调用复制构造函数："<<endl;
	}
	void print()
	{
		cout<<xx<<" "<<yy<<" "<<zz<<endl;
	}
	
	
};


int main()
{
	point p1(3,4,5);
	point p2(p1);
	p1.print();
	p2.print();
	return 0;
}

/*------------------------- 类对象成员 -------------------------*/


// #include<iostream>
// using namespace std;

// class point//第一个类：点
// {
	// public:
	// point(int x=0,int y=0)
	// {
		// xx = x;
		// yy = y; 
		// cout<<"point构造函数初始化···"<<endl;
	// }
	
	// point(const point &pt)
	// {
		// xx = pt.xx;
		// yy = pt.yy;
		// cout<<"point复制构造函数："<<endl;
	// }
	
	// void print()
	// {
		// cout<<"("<<xx<<","<<yy<<")";	
	// }
	// private:
	// int xx;
	// int yy;
// };


// class line
// {
	// private:
	// point pt1;
	// point pt2;
	// public:
	// line(int x1,int y1,int x2,int y2):pt1(x1,y1),pt2(x2,y2)
	// {
		
		// cout<<"line的构造函数执行: "<<endl;
	// }
	
	// line(const line &l1):pt1(l1.pt1),pt2(l1.pt2)
	// {
		// cout<<"line的复制构造函数执行"<<endl;
	// }
	
	// void draw()
	// {
		// pt1.print();
		// cout<<" to ";
		// pt2.print();
		
		// cout<<endl;
	// }
// };


// int main()
// {
	// line l1(3,4,5,6);
	// l1.draw();
	// line l2(l1);
	// l2.draw();
	// return 0;
	
// }



























