#include <iostream>
#include <vector>
#include <cmath>
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
    int remain = 0;
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
 * 方法 3，不使用循环能不能判断出来。因为int整型的最大范围是2^31，所以3的最大的次方是19，3^19 = 1162261467，只要输入的数字能够被这个
 * 数字整除即可
*/
bool isPowerOfThree3(int n)
{
    return (n > 0 && 1162261467 % n == 0);
}

/**
 * 方法 4，利用对数的换底公式来做，高中学过的换底公式为logab = logcb / logca，
 * 那么如果n是3的倍数，则log3n一定是整数，我们利用换底公式可以写为log3n = log10n / log103，
 * 注意这里一定要用10为底数，不能用自然数或者2为底数，否则当n=243时会出错，原因请看这个帖子。
 * 现在问题就变成了判断log10n / log103是否为整数，在c++中判断数字a是否为整数，我们可以用 a - int(a) == 0 来判断
*/

bool isPowerOfThree4(int n)
{
    if (n > 0 && int(log10(n) / log10(3)) - log10(n) / log10(3) == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    int a, count = 9;
    cout << "" << endl;
    while (count)
    {
        cin >> a;
        cout << "the a is:" << a << " !the res is: " << isPowerOfThree4(a) << endl;
        count--;
    }
}
