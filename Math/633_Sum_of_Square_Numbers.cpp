#include <iostream>
#include <vector>
#include <unordered_set>
#include <cmath>
using namespace std;

/**
 * Given a non-negative integer c, your task is to decide whether there're two integers a and b such that a2 + b2 = c.
 * 
 * Example 1:
 * Input: 5
 * Output: True
 * Explanation: 1 * 1 + 2 * 2 = 5
 * 
 * 给定一个数，然后看是不是有两个数字满足勾股定理的条件可以凑成这个数！
*/

/**
 * 方法 1，直接判断两次就行了。我们可以从c的平方根，注意即使c不是平方数，
 * 也会返回一个整型数。然后我们判断如果 i*i 等于c，
 * 说明c就是个平方数，只要再凑个0，就是两个平方数之和，返回 true；
 * 如果不等于的话，那么算出差值 c - i*i，如果这个差值也是平方数的话，返回 true
*/
bool judgeSquareSum(int c)
{
    for (int i = sqrt(c); i >= 0; i++)
    {
        if (i * i == c)
            return true;
        int d = c - i * i, t = sqrt(d);
        if (t * t == d)
            return true;
    }
    return false;
}

/**
 * 方法 2，这个方法也很好，类似于二分查找的写法
*/
int judgeSquareSum1(int c)
{
    long int i = 0, j = sqrt(c);
    while (i <= j)
    {
        if (i * i + j * j == c)
            return true;
        else if (i * i + j * j < c)
        {
            i++;
        }
        else
        {
            j--;
        }
    }
    return false;
}

/**
 * 方法 3，使用哈希表来记录当前的i的平方的值，如果c - i^2 存在的话，返回true；
*/
bool judgeSquareSum(int c)
{
    unordered_set<int> s;
    for (int i = 0; i <= sqrt(c); ++i)
    {
        s.insert(i * i);
        if (s.count(c - i * i))
            return true;
    }
    return false;
}
int main()
{
    int a = 5;
    cout << judgeSquareSum(a) << endl;
}