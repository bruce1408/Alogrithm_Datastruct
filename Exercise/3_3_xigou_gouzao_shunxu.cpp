#include<iostream>
using namespace std;
// 析构函数 是在对象消亡的时候，开始调用，用来完成删除前的一些
// 工作，比如释放分配的空间，但是如果不定义，编译器会自动生成
// 缺省的析构函数，这个时候不涉及释放用户申请的内存。注意！
// class Demo
// {
//     int id;
//     public:
//     Demo(int i)
//     {
//         id = i;
//         cout<<"id="<<id<<"gouzaohanhsu :"<<endl;
//     }
//     ~Demo()
//     {
//         cout<<"id="<<id<<"xigouhanshu :"<<endl;
//     }
// };
// Demo d1(1);
// void func()
// {
//     static Demo d2(2);
//     Demo d3(3);
//     cout<<"Func"<<endl;
// }

// int main()
// {
//     Demo d4(4);
//     d4 = 6;
//     cout<<"main"<<endl;
//     {Demo d5(5);}
//     func();
//     cout<<"main ends"<<endl;
//     return 0;
// }
