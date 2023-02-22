#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

/**
 * 匿名表达式
 * 
 * lambda表达式（C++11）
 * 使用场景
 * 1. lambda表达式又叫匿名函数(可以理解为一个未命名的内联函数),那么肯定就跟函数挂上关系了,通常情况写你在编程的时候需要将这段代码封装到一个函数里面再来调用,
 * 那这个时候就避免不了取函数名了,那么这个时候你就要想起我们的lambda表达式了,它可以很好的帮你解决函数命名困难这个问题。 
 * 2. 在你的整个项目编程中,你独立出来一个函数,但这个函数实现相对简单并且可能在整个项目只使用了一次(即不存在复用的情况),那么这个时候我们就可以考虑使用下lambda表达式了,
 * 这样可以让代码更加紧凑,更加容易维护。
 * 
 * 先看看lambda表达式变量截取的方式：
 * [] 不截取任何变量
 * [&] 截取外部作用域中所有变量，并作为引用在函数体中使用
 * [=] 截取外部作用域中所有变量，并拷贝一份在函数体中使用
 * [=, &foo] 截取外部作用域中所有变量，并拷贝一份在函数体中使用，但是对foo变量使用引用
 * [bar] 截取bar变量并且拷贝一份在函数体重使用，同时不截取其他变量
 * [this] 截取当前类中的this指针。如果已经使用了&或者=就默认添加此选项。
*/

/**
 * 例子 1，传统解法，使用sort的compare函数来觉得排序顺序。默认是升序排列
 */
bool compare(int &a, int &b)
{
    return a > b;
}

// int main(void)
// {
//     int data[6] = {3, 4, 12, 2, 1, 6};
//     vector<int> testdata;
//     testdata.insert(testdata.begin(), data, data + 6);
//     sort(testdata.begin(), testdata.end(), compare); // 升序
//     for (auto i : testdata)
//     {
//         cout << i << " ";
//     }
//     return 0;
// }

/**
 * 例子 2，lambda表达式的解法: 比较函数[](int a, int b){return a > b;}
*/
// int main(void)
// {
//     int data[6] = {3, 4, 12, 2, 1, 6};
//     vector<int> testdata;
//     testdata.insert(testdata.begin(), data, data + 6);
//     sort(testdata.begin(), testdata.end(), [](int a, int b) { return a > b; });
//     for (auto i : testdata)
//     {
//         cout << i << " ";
//     }
//     return 0;
// }

/**
 * 例子 3，使用auto来接收一个lambda表达式, 当然我们也可以直接使用C++11里面的新特性function来接收
 * lambda表达式,两者等价的,因为auto是自动类型转换, 所以在某些场合使用起来更方便。
 * 最终的运行结果都是：17 
 * 解析： function中的第一个int是返回值类型，括号里面的两个int都是函数的参数类型
*/
// int main(void)
// {
//     int x = 8, y = 9;
//     auto add = [](int a, int b) { return a + b; };
//     std::function <int(int, int)> Add = [=](int a, int b) { return a + b; };
//     cout << "add: " << add(x, y) << endl;
//     cout << "Add: " << Add(x, y) << endl;
//     return 0;
// }

/**
 * 使用lambda表达式来实现递归算法 
 * 递归题目:已知f(1)=1,f(2)=2,那么请实现f(n)=f(n-1)+f(n-2),此处的n>2
*/

// int main()
// {
//     std::function<int(int)> recursion = [&recursion](int n)
//     {
//         return n < 2 ? 1 : recursion(n - 1) + recursion(n - 2);
//     };
//     cout << "recursion(2):" << recursion(2) << endl;
//     cout << "recursion(3):" << recursion(3) << endl;
//     cout << "recursion(4):" << recursion(4) << endl;
//     return 0;
// }

/**
 * decltype关键字（C++11）
 * decltype意义
 * 有时我们希望从表达式的类型推断出要定义的变量类型，但是不想用该表达式的值初始化变量（如果要初始化就用auto了）。
 * 为了满足这一需求，C++11新标准引入了decltype类型说明符，它的作用是选择并返回操作数的数据类型，在此过程中，编译器分析表达式并得到它的类型，
 * 却不实际计算表达式的值。
 * 
 * decltype和auto都可以用来推断类型，但是二者有几处明显的差异：
 * 1.auto忽略顶层const，decltype保留顶层const；
 * 2.对引用操作，auto推断出原有类型，decltype推断出引用；
 * 3.对解引用操作，auto推断出原有类型，decltype推断出引用；
 * 4.auto推断时会实际执行，decltype不会执行，只做分析。
 * 总之在使用中过程中和const、引用和指针结合时需要特别小心。
 * 
 * decltype用法
*/

/**
 * 例子 1，基本用法
*/
// int getSize();
// int main(void)
// {
//     int tempA = 2;
//     /*1.dclTempA为int*/
//     decltype(tempA) dclTempA;
//     /*2.dclTempB为int，对于getSize根本没有定义，但是程序依旧正常，因为decltype只做分析，并不调用getSize，*/
//     decltype(getSize()) dclTempB;
//     return 0;
// }

/**
 * 例子 2，与const结合使用
*/
// void example()
// {
//     double tempA = 3.0;
//     const double ctempA = 5.0;
//     const double ctempB = 6.0； const double *const cptrTempA = &ctempA;

//     　　 /*1.dclTempA推断为const double（保留顶层const，此处与auto不同）*/
//         decltype(ctempA) dclTempA = 4.1;
//     /*2.dclTempA为const double，不能对其赋值，编译不过*/
//     dclTempA = 5;
//     /*3.dclTempB推断为const double * const*/
//     decltype(cptrTempA) dclTempB = &ctempA;
//     /*4.输出为4（32位计算机）和5*/
//     cout << sizeof(dclTempB) << "    " << *dclTempB << endl;
//     /*5.保留顶层const，不能修改指针指向的对象，编译不过*/
//     dclTempB = &ctempB;
//     /*6.保留底层const，不能修改指针指向的对象的值，编译不过*/
//     *dclTempB = 7.0;
// }

/**
 * 例子 3，与引用结合使用
*/
// void example3()
// {
//     int tempA = 0, &refTempA = tempA;
//     /*1.dclTempA为引用，绑定到tempA*/
//     decltype(refTempA) dclTempA = tempA;
//     /*2.dclTempB为引用，必须绑定到变量，编译不过*/
//     decltype(refTempA) dclTempB = 0;
//     /*3.dclTempC为引用，必须初始化，编译不过*/
//     decltype(refTempA) dclTempC;
//     /*4.双层括号表示引用，dclTempD为引用，绑定到tempA*/
//     decltype((tempA)) dclTempD = tempA;

//     const int ctempA = 1, &crefTempA = ctempA;

//     /*5.dclTempE为常量引用，可以绑定到普通变量tempA*/
//     decltype(crefTempA) dclTempE = tempA;
//     /*6.dclTempF为常量引用，可以绑定到常量ctempA*/
//     decltype(crefTempA) dclTempF = ctempA;
//     /*7.dclTempG为常量引用，绑定到一个临时变量*/
//     decltype(crefTempA) dclTempG = 0;
//     /*8.dclTempH为常量引用，必须初始化，编译不过*/
//     decltype(crefTempA) dclTempH;
//     /*9.双层括号表示引用,dclTempI为常量引用，可以绑定到普通变量tempA*/
//     decltype((ctempA)) dclTempI = ctempA;
// }

/**
 * 例子 4，与指针结合使用
*/
// void example4()
// {
//     int tempA = 2;
//     int *ptrTempA = &tempA;
//     /*1.常规使用dclTempA为一个int *的指针*/
//     decltype(ptrTempA) dclTempA;
//     /*2.需要特别注意，表达式内容为解引用操作，dclTempB为一个引用，引用必须初始化，故编译不过*/
//     decltype(*ptrTempA) dclTempB;
// }

bool cmp(int a, int b)
{
    return a > b; // 从大到小排列顺序
}
int main()
{
    vector<int> res = {4, 3, 5, 7, 1, 2, 6};
    sort(res.begin(), res.end(), cmp);
    for (auto i : res)
    {
        cout << i << " ";
    }
}