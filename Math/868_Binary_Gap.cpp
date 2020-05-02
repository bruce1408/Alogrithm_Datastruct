#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
using namespace std;

/**
 * Given a positive integer N,
 * find and return the longest distance between two consecutive 1's in the binary representation of N.
 * If there aren't two consecutive 1's, return 0.
 * 
 * Input: 22
 * Output: 2
 * 
*/

/**
 * 方法 1，按照逻辑算法来做，每次这个数对2求余数，看余数是不是1，然后统计出现1的个数,
 * 如果当前的余数是1，且出现2次以上了，那么才开始判断这个1之间的距离，否则，只是记录这个1目前的轮次就好。
 * 最后，返回距离的值即可
*/
int binaryGap(int N)
{
    int remain = 0;
    int pos = 0, distance = 0, onePost = 0, count = 0;
    while (N)
    {
        remain = N % 2;
        N = N >> 1;
        if (remain == 1)
        {
            count++;
            if (count >= 2)
            {
                distance = max(distance, pos - onePost);
            }
            onePost = pos;
        }
        pos++;
    }
    return distance;
}
/**
 * 方法 2，使用位运算来算这个题目，在用第一种方法的时候，就是能不能用for循环，但是不知道一个数的二进制
 * 到底是多少为，所以没有用for，使用的while来除以2，后来看到一个解答是，int整型是32位，所以可以使用额外的数组空间
 * 来保存1；这种思路也很好，没有想到整型数范围这个知识点。
*/
int binaryGap1(int N)
{
    vector<int> res;
    for (int i = 0; i < 32; i++)
    {
        if (((N >> i) & 1) != 0)
            res.push_back(i);
    }

    int pos = 0;
    for (int i = 1; i < res.size(); i++)
    {
        pos = max(pos, res[i] - res[i - 1]);
    }
    return pos;
}

int main()
{
    int k = 4;
    while (k)
    {
        int x;
        cout << "请输入数字：" << endl;
        cin >> x;
        cout << "最大的1之间的距离为： " << binaryGap1(x) << endl;
        k--;
    }
}
