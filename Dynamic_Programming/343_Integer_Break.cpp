#include <iostream>
#include <vector>
using namespace std;

/**
 * 343 整数拆分，把一个整数进行拆分，将其拆分成至少两个整数的和，然后使得这个
 * 整数的乘积的最大化，返回这个乘积的最大乘积即可；
*/

/**
 * 方法 1，尽可能分成3和2，且最多是2个2
*/
int integerBreak(int n)
{
    if(n<=3) return 1 *(n-1);
    int s =1;
    if(n >5) n-=3, p*=3;
}