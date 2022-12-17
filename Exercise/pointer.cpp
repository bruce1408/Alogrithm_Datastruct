#include<iostream>
using namespace std;

int main()
{
	// int a = 5;
	// double b = 6.09;
	// cout<<&a<<endl;
	// cout<<&b<<endl;
	// cout<<*(&b)<<endl;
	// cout<<a<<endl;
	
	
	
	// int a=5,b=6,c=7,d=8;
	// double e=3.1415;
	// //单独赋值,并且*和p_a紧挨着
	// int *p_a=&a;
	// //多个赋值(既有指针,又有普通变量)
	// int * p_b=&b,* p_c=&c,*p_d=&d,temp=100;

	// //单独赋值,double类型
	// double * p_e=&e;

	// cout<<p_a<<endl;
	// cout<<p_b<<endl;
	// cout<<p_c<<endl;
	// cout<<p_d<<endl;
	// cout<<p_e<<endl;
	// cout<<temp<<endl;
	
	
	
	
	// int num=5;
    // //p_a没有初始化
    // int *p_a1,*p_a2;
    // cout<<p_a1<<endl;
    // cout<<p_a2<<endl;

    // int *p_b=&num;
    // cout<<p_b<<endl;

    /*同类型指针可以赋值*/
    // //没有初始化的指针依然可以被赋值(地址)
    // p_a1=p_b;
    // p_a2=&num;
    // cout<<p_a1<<endl;
    // cout<<*p_a1<<endl;
    // cout<<p_a2<<endl;
    // cout<<*p_a2<<endl;
	
	
	/*指针没有初始化就开始复制会出问题，建议指针初始化，不知道指哪的时候指空，nullptr*/
	// int num=5;
    // //p_a没有初始化
    // int *p_a1,*p_a2;
    // cout<<"p_a1:"<<p_a1<<endl;
    // cout<<"p_a2:"<<p_a2<<endl;

    // *p_a1=12;
    // cout<<*p_a1<<endl;
	
	
	/*
	有一个非常重要的是,因为NULL不指向任何地方,所以,也就肯定不能够解引用了,空指针解引用会报错！！
	*/
	//测试NULL是不是0
    // if(NULL==0)
        // cout<<"yes"<<endl;

    // //转化为NULL指针
    // int *p_a=0;
    // int *p_b=NULL;

    // //试图解引用
    // cout<<*p_a<<endl;
	
	
	/*
	Void*是一种特殊类型的指针,能够用来存放任何类型对象的地址.
	通俗来说,就是我不知道这个指针指向的是什么类型的对象.
	*/
	// double x=25.5;
    // //普通指针的话类型要严格保证
    // double *p=&x;
    // //void* 类型可以接受任意类型对象地址
    // void *p_v=&x;
    // void *p_v2;
	// p_v2 = p;
	
    // std::cout<<"p_v:"<<p_v<<std::endl;
    // std::cout<<"p_v2:"<<p_v2<<std::endl;
	
	
	
	/*指向指针的指针*/
	// int a=10;
	// int *p_a=&a;
	// int **pp_a=&p_a;

	// cout<<"p_a:"<<p_a<<endl<<"*p_a:"<<*p_a<<endl;
	// cout<<endl;

	// cout<<"PP_a的地址: "<<pp_a<<endl
	// <<"*pp_a表示他里面保存的值，二级指针就是指针p_a的地址: "<<*pp_a
	// <<endl<<"**pp_a表示一级指针p_a保存的数值："<<**pp_a<<endl;
	
	int a =0;
	const int *p = &a;//指向常量的指针，地址可以随意指向，但是指向的数值不能修改
	int b =1;
	p = &b;
	// *p = 3;
	cout<<*p<<endl;
	
	/*声明的对象是一个常量，且它的内容是一个指针，也就是一个地址。
	上面的声明可以这么读，声明了一个常量u，它的值是变量c的地址
	（变量a的地址，不就是指向变量a的指针吗）*/
	int c = 0;
	int *const u = &c;//指针类型的常量，地址不能改，但是指向的数值可以修改
	cout<<*u<<endl;
	*u = 30;
	cout<<*u<<endl;
	c = 35;
	cout<<*u<<endl;
	// u = &b;//指向的是常量
	
	
	
	
	return 0;
}




















