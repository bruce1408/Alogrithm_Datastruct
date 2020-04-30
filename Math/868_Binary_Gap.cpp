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
        N /= 2;
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
    return distance ;
}

int binaryGap1(int N)
{
    while(N)
    {
        N&1
    }
}

int main()
{
    while (true)
    {
        int x;
        cin >> x;
        cout << binaryGap(x) << endl;
    }
}
