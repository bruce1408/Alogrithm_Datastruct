/*
当封闭类的对象生成并初始化时，它包含的成员对象也需要被初始化，
这就会引发成员对象构造函数的调用。如何让编译器知道，
成员对象到底是用哪个构造函数初始化的呢？
这可以通过在定义封闭类的构造函数时，添加初始化列表的方式解决
也就是说，如果一个类的成员变量是另外一个类的对象，就称之为
“成员对象”，包含成员对象的类叫封闭类，
那么这个封闭类构造函数初始化要用初始化列表
调用顺序是先执行成员对象的构造函数，然后再执行封闭类的构造函数
析构函数的执行顺序正好和构造函数相反
*/
#include <iostream>
using namespace std;
class CTyre //轮胎类
{
  private:
    int radius; //半径
    int width;  //宽度
  public:
    CTyre(int r, int w) : radius(r), width(w) {}
};
class CEngine //引擎类
{
};
class CCar
{ //汽车类
  private:
    int price; //价格
    CTyre tyre;
    CEngine engine;

  public:
    CCar(int p, int tr, int tw);
};
// 构造函数，初始化列表。
CCar::CCar(int p, int tr, int tw) : price(p), tyre(tr, tw){};
int main()
{
    // 编译器需要知道如何初始化，所以对应上面的构造函数初始化的问题
    CCar car(20000, 17, 225);
    return 0;
}
// #include <iostream>
// using namespace std;
// class CTyre
// {
//   public:
//     CTyre() { cout << "CTyre constructor" << endl; }
//     ~CTyre() { cout << "CTyre destructor" << endl; }
// };
// class CEngine
// {
//   public:
//     CEngine() { cout << "CEngine constructor" << endl; }
//     ~CEngine() { cout << "CEngine destructor" << endl; }
// };
// class CCar
// {
//   private:
//     CEngine engine;
//     CTyre tyre;

//   public:
//     CCar() { cout << "CCar constructor" << endl; }
//     ~CCar() { cout << "CCar destructor" << endl; }
// };
// int main()
// {
//     CCar car;
//     return 0;
// }