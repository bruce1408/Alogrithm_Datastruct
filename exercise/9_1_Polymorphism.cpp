/*多态的部分，主要是虚函数的用法。运算符重载
第一:什么是虚函数，定义一个指针，他访问成员对象的时候，只是取决于指针的类型，
而不是指针所指向的对象，这样比较麻烦，所以我们需要类似于一个接口，一种接口，
多种方法。*/



/*程序一这个程序是利用虚函数实现多态，基类是虚函数即可；*/
// #include<iostream>
// using namespace std;
// class base
// {
	// public:
	// virtual void disp()//基类是虚函数，加virtual。派生类不加virtual，也是会继承。
	// // void disp()
	// {
		// cout<<"base"<<endl;
	// }
// };

// class child1:public base
// {
	// public:
	// void disp()//肯定也是虚函数！
	// {
		// cout<<"child1"<<endl;
	// }
// };


// void display(base *p)
// {
	// p->disp();
// }


// int main()
// {
	// base *pbase=0,baseobj;
	// baseobj.disp();
	// child1 *pchild,childobj;
	// pchild = &childobj;
	// pchild->disp();
	// pchild = (child1*)&baseobj;// 情知转换 不再是指针的类型，而是所指对象
	// pchild->disp();
	
	
	// //虚函数，就是多态，和指针的类型无关，之和指针所指的对象有关系！
	// display(&baseobj);//他们打印出来都是base类（基类）的成员函数,
	// display(&childobj);//无法起到一种借口，多种方法的调用方式！
	// display(pchild);//那么可以用虚函数来解决。
	// childobj.base::disp();//也可以用限定符来指明调用的版本
	// return 0;
// }

#include<iostream>
using namespace std;
class BaseClass
{
	public:
	virtual void fn1()
	{
		cout<<"调用基类的虚函数fn1:"<<endl;
	}
	void fn2()//注意；这里的fn2不是虚函数，所以不会有多态的变化。
	{
		cout<<"调用基类的非虚函数fn2:"<<endl;
	}
};


class DerivedClass:public BaseClass
{
	public:
	void fn1()
	{
		cout<<"调用派生类的函数fn1"<<endl;
	}
	void fn2()
	{
		cout<<"调用派生类的函数fn2"<<endl;
	}
};

int main()
{
	DerivedClass aDer;
	DerivedClass *pDer = &aDer;
	BaseClass *pBas = &aDer;
	pBas->fn1();
	pBas->fn2();//不是虚函数；仍然是指针所指向的函数
	pDer->fn1();
	pDer->fn2();
	return 0;
}

/*------------------------------ 纯虚函数的声明和定义 和 抽象类 ----------------------*/
// #include<iostream>
// using namespace std;
// class A
// {
	// public:
	// virtual void disp()=0;//没有任何操作，叫纯虚函数。一个类中只要有一个纯虚函数，这个类
	// //就是抽象类
// };


// class B:public A
// {
	// virtual void disp()//virtual is no need to write
	// {
		// cout<<"this is from B"<<endl;
	// }
// };


// class C:public B
// {
	// public:
	// virtual void disp()
	// {
		// cout<<"this is from C"<<endl;
	// }
	
// };

// void display(A *a)
// {
	// a->disp();
// }

// int main()
// {
	// B *pb = new B;
	// C *pc = new C;
	// display(pb);
	// display(pc);
	// //动态内存记得释放；
	// delete pb;
	// delete pc;
	// pb =  NULL;
	// pc =  NULL;
	// return 0;
// }


/*测试程序*/
// #include<iostream>
// using namespace std;
// class Mammal
// {
	// public:
	// virtual void speak()
	// {
		// cout<<"mammal"<<endl;
	// }
// };

// class Dog:public Mammal
// {
	// public:
	// void speak();
// };
// void Dog::speak()
// {
	// cout<<"dog"<<endl;
// }

// int main()
// {
	// Mammal *p,a;
	// p = &a;
	// p->speak();
	// Dog *d,q;
	// d = &q;
	// d->speak();
	// p = &q;
	// p->speak();
	// return 0;
	
// }

// 继承关系
// #include<iostream>
// #include<cmath>
// using namespace std;

// const double PI = 3.1415926;
// class Geometric_shape
// {
	// public:
	// virtual double perimeter()=0; //一个纯虚函数，就是抽象类
	// virtual double area()=0;            //面积
	// virtual double volume()=0;         //体积
	// virtual void show(){}             //显示
	
// };


// //矩形
// class Rectangle:public Geometric_shape
// {
	// public:
	// Rectangle()
	// {
		// width = 0;
		// length = 0;
	// }
	
	// Rectangle(double xx,double yy)
	// {
		// width = xx;
		// length = yy;
	// }
	
	// Rectangle(Rectangle &rr)
	// {
		// width = rr.width;
		// length = rr.length;
	// }
	
	
	// double perimeter()
	// {
		// return 2*(width+length);
	// }
	
	// double area()
	// {
		// return width*length;
	// }
	// double volume()
	// {
		// return 0;
	// }
	
	// void show()
	// {
		// cout<<"width:"<<width<<"\t"<<"length:"<<length<<endl;
	// }
	
	// private:
	// double width;
	// double length;
	
// };



// //三角形
// class Triangle:public Geometric_shape
// {
	// private:
	// double a,b,c;
	
	// public:
	// Triangle(double xx,double yy,double zz)
	// {
		// a = xx;
		// b = yy;
		// c = zz;
	// }
	
	// Triangle()
	// {
		// a = 0;
		// b = 0;
		// c = 0;
	// }
	
	// double perimeter()
	// {
		// return a+b+c;
	// }
	
	// double area()
	// {
		// double s = (a+b+c)/2.0;
		// return sqrt(s*(s-a)*(s-b)*(s-b));
	// }
	
	// double volume()
	// {
		// return 0;
	// }
	
	// void show()
	// {
		// cout<<"a: "<<a<<"b: "<<"c: "<<c<<endl;
	// }
	
// };



// //圆形
// class Circle:public Geometric_shape
// {
	// public:
	// Circle()
	// {
		// ridaus = 0.0;
	// }
	
	// Circle(double r)
	// {
		// ridaus = r;
	// }
	
	// double perimeter()
	// {
		// return 2.0*PI*ridaus;
	// }
	
	// double area()
	// {
		// return PI*ridaus*ridaus;
	// }
	
	// double volume()
	// {
		// return 0;
	// }
	
	// void show()
	// {
		// cout<<"ridaus: "<<ridaus<<endl;
	// }
	
	// private:
	// double ridaus = 0.0;
// };


// //长方体
// class Box:public Rectangle
// {
	// private:
	// double height;
	
	// public:
	// Box()
	// {
		// height = 0.0;
	// }
	
	// Box(double wid,double lent,double h):Rectangle(wid,lent)//初始化列表，名字需要一致
	// {
		// height = h;
	// }
	
	// double volume()
	// {
		// return area()*height;
	// }
	
// };

// //圆柱
// class Cylinder:public Circle
// {
	// private:
	// double height;
	
	// public:
	// Cylinder()
	// {
		// height = 0.0;
	// }
	
	// Cylinder(double ri,double hei):Circle(ri)
	// {
		// height = hei;
	// }
	
	// double volume()
	// {
		// return area()*height;
	// }
	
// };


// int main()
// {
	// Geometric_shape *p;
	// Circle cc1(10);
	// Rectangle r1(3,4);
	// Triangle t1(3,4,5);
	// Box b1(6,8,3);
	// Cylinder cy(10,9);
	// cc1.show();
	// cout<<cc1.perimeter()<<endl;
	// cout<<cc1.volume()<<endl;
	// cout<<cc1.area()<<endl;
	
	// p = &r1;
	// p->show();
	// cout<<p->perimeter()<<endl;
	// cout<<p->volume()<<endl;
	// cout<<p->area()<<endl;
		
	// p = &b1;
	// p->show();
	// cout<<p->perimeter()<<endl;
	// cout<<p->volume()<<endl;
	// cout<<p->area()<<endl;
	
	
	
	
	// return 0;
// }


//虚析构函数的执行顺序，先是派生类的析构，然后是基类的析构
// #include<iostream>
// using namespace std;

// class Baseclass
// {
	// public:
	// virtual ~Baseclass()
	// {
		// cout<<"~bse"<<endl;
	// }
// };

// class Deri:public Baseclass
// {
	// public:
	// ~Deri()
	// {
		// cout<<"~Deri"<<endl;
	// }
// };

// int main()
// {
	// Baseclass *p = new Deri;
	// p
	// delete p;
	// return 0;
// }






































