#include<iostream>
using namespace std;
/*
 * 类的友元函数是定义在类外部，
 * 但有权访问类的所有私有（private）成员和保护（protected）成员。
 * 尽管友元函数的原型有在类的定义中出现过，
 * 但是友元函数并不是成员函数。
 * 友元可以是一个函数，该函数被称为友元函数；
 * 友元也可以是一个类，该类被称为友元类，在这种情况下，
 * 整个类及其所有成员都是友元。
 * 如果要声明函数为一个类的友元，
 * 需要在类定义中该函数原型前使用关键字 friend，如下所示：
 */
class Box
{
    double width;
    public:
    friend void printWidth(Box box); // 友元函数
    void setWidth(double wid);
};

void Box::setWidth(double wid)
{
    width = wid;
}

void printWidth(Box box)// 不是成员函数，直接定义，不需要加限定
{
    cout<<"the box width is:"<<box.width<<endl;
}


// int main()
// {
//     Box box;
//     box.setWidth(10.9);
//     printWidth(box);
//     return 0;
// }

/**
 * 友元类
 * 类A中的成员函数访问类B中的私有或者保护成员
*/
class B
{
    public:
    B(int _b):b(_b){};
    friend class C;
    private: int b;
};


class C
{
    public:
    int getB_b(B _classB)
    {
        return _classB.b;
    }
};


int main()
{
    B _classB(3);
    C _classC;
    cout<<_classC.getB_b(_classB);
    return 0;
}
