#include <iostream>
#include <vector>
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
 * 方法 1，
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
 * 方法 2
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

int main()
{
    int a = 5;
    cout << judgeSquareSum(a) << endl;
}