#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

/**
 * In a row of seats, 1 represents a person sitting in that seat, 
 * and 0 represents that the seat is empty. 
 * There is at least one empty seat, and at least one person sitting.
 * Alex wants to sit in the seat such that the distance between him and the closest person to him is maximized. 
 * Return that maximum distance to closest person.
 * 
 * Example 1:
 * Input: [1,0,0,0,1,0,1]
 * Output: 2
 * Explanation: 
 * If Alex sits in the second open seat (seats[2]), then the closest person has distance 2.
 * If Alex sits in any other open seat, the closest person has distance 1.
 * Thus, the maximum distance to the closest person is 2.
 * 
 * 给定一个数组，然后1表示当前的索引有人已经坐了，0表示没有人坐，现在就是要找到一个0的空位置，可以让
 * 其他人坐到这个位置，而且这个位置必须和周围的人离得越远越好才可以
 */

/**
 * 方法 1，我的思路就是统计相邻1之间的0的个数，然后找到其中最大的，
 * 找到之后这个(最大个数)/2即可；下面的写法出错了；
*/
int maxDistToClosest(vector<int> &seats)
{
    int N = seats.size();
    int left = 0;
    int maxDis = 0;
    int i = 0;
    while (i < N)
    {
        int tempMax = 1;
        if (seats[i] == 1)
        {
            for (int j = i+1; j < N;)
            {
                if (seats[j] != 1)
                {
                    j++;
                    tempMax++;
                }
                else
                {
                    maxDis = max(tempMax, maxDis);
                    i = j;
                    break;
                }
            }
            i++;
        }
        else
        {
            i++;
        }
    }
    return maxDis;
}

/**
 * 方法 2，以及方法 3都是直接求解的是连续0出现的最大次数，只用一次for循环即可，但是没有考虑到
 * 如果靠墙的情况，就是[1,0,0,0]
*/
int maxDistToClosest2(vector<int> res)
{
    int maxDis = 0;
    int start = 0;
    for (int i = 0; i < res.size(); i++)
    {
        if (res[i] == 1)
        {
            maxDis = max(i - start, maxDis);
            start = i;
        }
    }
    return (maxDis - 1) / 2 + 1;
}

int maxDistToClosest3(vector<int> res)
{
    int maxDis = 0;
    int count = 0,index= 0, N = res.size();
    for (int i = 0; i < res.size(); i++)
    {
        if (res[i] == 0)
        {
            count++;
            index = i;
        }
        else
        {
            maxDis = max(count, maxDis);
            count = 0;
            
        }
    }
    cout<<"the max index is: "<<index<<endl;
    return index==N-1? max(maxDis, count) : max(maxDis, count)/2+1;
}

int main()
{
    vector<int> res = {1, 0, 0, 1};
    cout << maxDistToClosest(res) << endl;
}
