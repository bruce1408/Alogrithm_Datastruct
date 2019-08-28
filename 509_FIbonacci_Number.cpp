#include<iostream>
using namespace std;
/**
 * 题目：斐波那契数列计算
 * 方法 滚动变量
 * 思路：
 * 利用滚动变量的方法，每次只要计算两个数字就可以
*/
class Solution {
public:
    int fib(int N) 
    {
        int a = 0, b = 1;
        int x = 0;
        for(int i=0;i<N;i++)
        {
            x = a + b;
            b = a;
            a = x;
        }
        return x;  
    }
};