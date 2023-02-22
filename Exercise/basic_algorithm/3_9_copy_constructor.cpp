#include<iostream>
using namespace std;
class Point{
	public:
	Point(const Point &p);
	Point(int xx=0, int yy=0){x = xx;y = yy;}
	void setX(int xx){x=xx;}
	void setY(int yy){y=yy;}
	int getX() const{return x;}
	int getY() const{return y;}
	private:
	int x,y;

};

Point::Point(const Point &p)
{
	x = p.x;
	y = p.y;
	cout<<"calling the copy constructor"<<endl;
	
	
}

//形参是对象
void fun1(Point p){
	cout<<p.getX()<<endl;
}


//返回值是point的类对象的函数
Point fun2(){
	Point a(1,2);
	return a;
}


int main()
{
	Point a(4,5);
	Point b(a); //
	cout<<b.getX()<<endl;
	fun1(b);//
	b = fun2();//
	cout<<b.getX()<<endl;
	return 0;
}


// 运算符重载，可以用到实数的加减上
// #include <iostream>
// using namespace std;

// class Box
// {
//   public:
// 	double getVolume(void)
// 	{
// 		return length * breadth * height;
// 	}
// 	void setLength(double len)
// 	{
// 		length = len;
// 	}

// 	void setBreadth(double bre)
// 	{
// 		breadth = bre;
// 	}

// 	void setHeight(double hei)
// 	{
// 		height = hei;
// 	}
// 	// 重载 + 运算符，用于把两个 Box 对象相加
// 	Box operator+(const Box &b)
// 	{
// 		Box box;
// 		box.length = this->length + b.length;
// 		box.breadth = this->breadth + b.breadth;
// 		box.height = this->height + b.height;
// 		return box;
// 	}

//   private:
// 	double length;  // 长度
// 	double breadth; // 宽度
// 	double height;  // 高度
// };
// // 程序的主函数
// int main()
// {
// 	Box Box1;			 // 声明 Box1，类型为 Box
// 	Box Box2;			 // 声明 Box2，类型为 Box
// 	Box Box3;			 // 声明 Box3，类型为 Box
// 	double volume = 0.0; // 把体积存储在该变量中

// 	// Box1 详述
// 	Box1.setLength(6.0);
// 	Box1.setBreadth(7.0);
// 	Box1.setHeight(5.0);

// 	// Box2 详述
// 	Box2.setLength(12.0);
// 	Box2.setBreadth(13.0);
// 	Box2.setHeight(10.0);

// 	// Box1 的体积
// 	volume = Box1.getVolume();
// 	cout << "Volume of Box1 : " << volume << endl;

// 	// Box2 的体积
// 	volume = Box2.getVolume();
// 	cout << "Volume of Box2 : " << volume << endl;

// 	// 把两个对象相加，得到 Box3
// 	Box3 = Box1 + Box2;

// 	// Box3 的体积
// 	volume = Box3.getVolume();
// 	cout << "Volume of Box3 : " << volume << endl;

// 	return 0;
// }


// 类型转换构造函数
// #include<iostream>
// using namespace std;
// class Complex{
// 	public:
// 	double real,imag;
// 	Complex(int i)
// 	{
// 		cout<<"incounstruct called"<<endl;
// 		real = i;imag=0;
// 	}
// 	Complex(double i,double j)
// 	{
// 		real = i;imag=j;
// 	}
// };

// int main()
// {
// 	Complex c1(4,5);
// 	Complex c2 = 12;
// 	cout<<c1.real<<c1.imag<<endl;
// 	c1 = 9;
// 	cout<<c1.real<<c1.imag<<endl;
// 	int a = 18,b=21;
// 	a = a^b;
// 	b = b^a;
// 	a = a^b;
// 	cout<<a<<b<<endl;
	
// 	return 0;
// }