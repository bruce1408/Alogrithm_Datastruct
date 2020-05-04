#include <iostream>
#include <vector>
#include <vector>
using namespace std;

/**
 * Your task is to calculate ab mod 1337 
 * where a is a positive integer and b is an extremely large positive integer given in the form of an array
 * 
*/

/**
 * 方法 1，数的很大的次方对1337取余的值，开始一直在想这个1337有什么玄机，
 * 为啥突然给这么一个数，感觉很突兀，后来想来想去也没想出来为啥，估计就是怕结果太大无法表示，
 * 随便找个数取余吧。那么这道题和之前那道Pow(x, n)的解法很类似，我们都得对半缩小，
 * 不同的是后面都要加上对1337取余。由于给定的指数b是一个一维数组的表示方法，我们要是折半缩小处理起来肯定十分不方便，
 * 所以我们采用按位来处理，比如223 = (22)10 * 23, 所以我们可以从b的最高位开始，算出个结果存入res，
 * 然后到下一位是，res的十次方再乘以a的该位次方再对1337取余
*/
int superPow(int a, vector<int> &b)
{
    int dig = 0, res = 1;
    for (int i = 0; i < b.size(); i++)
    {
        dig = dig * 10 + b[i];
    }
    for (int i = 0; i < dig; i++)
    {
        res = res * a;
    }
    return res;
}

int main()
{
    vector<int> res = {1, 0};
    cout << superPow(2, res) << endl;
}