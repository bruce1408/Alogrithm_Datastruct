#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/**
 * 操作符重载最有名的就是对一个复数进行运算，分实部和虚部两部分
*/
// class Complex
// {
//     public:
//     Complex()
//     {
//         real=0;
//         imag=0;
//     }
//     Complex(double r,double i)
//     {
//         real=r;
//         imag=i;
//     }
//     Complex complex_add(Complex &c2);      //声明复数相加函数
//     void display();
//     private:
//     double real;    //实部
//     double imag;    //虚部
// };
//  Complex Complex::complex_add(Complex &c2)
// {
//     Complex c;
//     c.real=real+c2.real;
//     c.imag=imag+c2.imag;
//     return c;
// }
// void Complex::display()
// {
//     cout<<"("<<real<<","<<imag<<"i)"<<endl;
// }

/**
 * 重载运算符例子 2，使用重载关键字operator来重载复数的加减操作；
 * 值得注意的是，重载函数是类中的成员函数，所以有一个参数是隐含的，this指针隐式地访问类对象的成员
*/
class Complex
{

public:
    Complex()
    {
        real = 0;
        imaginary = 0;
    }
    Complex(double r, double i)
    {
        real = r;
        imaginary = i;
    }
    Complex operator+(const Complex &) const;
    Complex operator-(const Complex &) const;
    void display();

private:
    double real;      // real part
    double imaginary; // imaginary part
};

void Complex::display()
{
    cout << "(" << real << "," << imaginary << "i)" << endl;
}

Complex Complex::operator+(const Complex &operand2) const
{
    return Complex(real + operand2.real, imaginary + operand2.imaginary);
}

Complex Complex::operator-(const Complex &operand2) const
{
    return Complex(real - operand2.real, imaginary - operand2.imaginary);
}

// int main()
// {
//     Complex c1(1, 2), c2(3, -4), c3, c4; //定义3个复数对象
//     c3 = c1 + c2;                        //调用复数相加函数
//     c4 = c1 - c2;
//     cout << "c1=";
//     c1.display(); //输出c1的值
//     cout << "c2=";
//     c2.display(); //输出c2的值
//     cout << "c1+c2=";
//     c3.display(); //输出c3的值
//     cout << "c1-c2=";
//     c4.display();
//     return 0;
// }

/**
 * 对于单目运算符的重载，在重载函数里面，加上一个形参表示后置，没有加形参表示前置运算符。
*/
class Time
{
public:
    Time()
    {
        minute = 0;
        sec = 0;
    }
    Time(int m, int s) : minute(m), sec(s) {}
    Time operator++();    //声明前置自增运算符“++”重载函数
    Time operator++(int); //声明后置自增运算符“++”重载函数
    void display();

private:
    int minute;
    int sec;
};

Time Time::operator++() //定义前置自增运算符“++”重载函数
{
    if (++sec >= 60)
    {
        sec -= 60; //满60秒进1分钟
        ++minute;
    }
    return *this; //返回当前对象值
}

Time Time::operator++(int) //定义后置自增运算符“++”重载函数
{
    Time temp(*this);
    sec++;
    if (sec >= 60)
    {
        sec -= 60;
        ++minute;
    }
    return temp; //返回的是自加前的对象
}
void Time::display()
{
    cout << "(" << minute << "," << sec << "i)" << endl;
}
int main()
{
    Time c1(2, 30), c2(3, 45), c3, c4;
    c3 = c1++;
    c4 = ++c2;
    c1.display();
    c2.display();
    c3.display();
    c4.display();
}
