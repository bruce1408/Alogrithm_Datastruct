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
            for (int j = i; j < N;)
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
        }
        else
        {
            i++;
        }
    }
    return maxDis;
}

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
    cout << maxDistToClosest3(res) << endl;
}
