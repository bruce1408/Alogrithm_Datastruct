#include <iostream>
#include <stack>
using namespace std;

/**
 * Given n non-negative integers representing an elevation map where the width of each bar is 1,
 * compute how much water it is able to trap after raining.
 * 这道题目说起来比较抽象，但是画图的话就很容易看明白。就是给一个非负的整数，每个整数的bar是1，可以看成宽，然后高
 * 就是数组里面的值。比如
 * Input: [0,1,0,2,1,0,1,3,2,1,2,1]
 * 第一个数字是0，说明没有高，然后第二个1，第三个0，第四个是2，那么在第二个和第四个之间可以存水，存多少呢？
 * 应该是最小的那个高决定的。最后计算总存水量是多少。
*/

int trap(vector<int> &height)
{
    int sumWater = 0;
}

int main()
{
    vector<int> res = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << trap(res) << endl;
}