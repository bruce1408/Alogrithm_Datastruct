#include <iostream>
#include <vector>
using namespace std;

/**
 * 给定一个数，然后判断这个数是不是3的n次幂的结果，比如9是3^2,27是3^3。
*/

/**
 * 方法 1，判断一个数是不是3的 n次方,不停的除以3，看余数是否能被3整除，如果不可以，那么看这个是是不是1，如果是1的话
 * 那么就是3的n次幂，否则不是，比如说4，4%3余数不是0，所以推出循环，最后看4是不是等于1，不是的话返回false；
*/
bool isPowerOfThree1(int n)
{
    while (n && n % 3 == 0)
    {
        n /= 3;
    }
    return n == 1;
}

/**
 * 方法 2，循环遍历,居然超时了！丧心病狂啊
*/
bool isPowerOfThree2(int n)
{
    int cnt = 0, remain = 0;
    while (n != 1)
    {
        remain = n % 3;
        if (remain != 0)
            return false;
        n /= 3;
    }
    return true;
}

/**
 * 方法 3，不使用循环能不能判断出来。
*/
int main()
{
    int a, count = 9;
    cout << "" << endl;
    while (count)
    {
        cin >> a;
        cout << "the a is:" << a << " !the res is: " << isPowerOfThree1(a) << endl;
        count--;
    }
}
