#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

/**
 * A bus has n stops numbered from 0 to n - 1 that form a circle. 
 * We know the distance between all pairs of neighboring stops where
 * distance[i] is the distance between the stops number i and (i + 1) % n.
 * The bus goes along both directions i.e. clockwise and counterclockwise.
 * Return the shortest distance between the given start and destination stops.
 * 
 * Input: distance = [1,2,3,4], start = 0, destination = 1
 * Output: 1
 * Explanation: Distance between 0 and 1 is 1 or 9, minimum is 1.
 * 
 * 公交可以经过n个站点，然后既可以顺时针，也可以逆时针，每个站点的距离是不一样的，所以，求解
 * 出站点之间的最小距离即可
 * *再做一次！
*/

/**
 * 方法 1，超级牛逼，只用一次遍历就可以做出来，这个题目我刚开始的思路是利用方位，上下左右
 * 但是这个上下左右是每次限制走一个格子，所以这里并不是很合适，但是下面只需要一次遍历就可以
 * 做出来，设置顺时针 和 逆时针的两个和变量，然后如果当前指针是在大于等于0且小于destination
 * 那么顺时针累加即可，否则 逆时针累加！
*/
int distanceBetweenBusStops(vector<int>& distance, int start, int destination) 
{
    if(start > destination) swap(start, destination);
    int sumClock = 0, sumCountClock = 0;
    for(int i=0;i<distance.size();i++)
    {
        if(i>=start && i<destination) sumClock+=distance[i];
        else sumCountClock+=distance[i];
    }
    return min(sumCountClock, sumClock);
}

int main()
{
    vector<int> a = {1, 2, 3, 4};
    cout<<distanceBetweenBusStops(a, 0, 3)<<endl;
}