#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

/**
 * 匿名表达式
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
 * 为了满足这一需求，C++11新标准引入了decltype类型说明符，它的作用是选择并返回操作数的数据类型，在此过程中，编译器分析表达式并得到它的类型，却不实际计算表达式的值。
 * 
 * decltype用法
*/

int getSize();
int main(void)
{
    int tempA = 2;
    /*1.dclTempA为int*/
    decltype(tempA) dclTempA;
    /*2.dclTempB为int，对于getSize根本没有定义，但是程序依旧正常，因为decltype只做分析，并不调用getSize，*/
    decltype(getSize()) dclTempB;
    return 0;
}