#include <iostream>
#include <vector>
using namespace std;

/**
 * In a list of songs,
 * the i-th song has a duration of time[i] seconds. 
 * Return the number of pairs of songs for which their 
 * total duration in seconds is divisible by 60.  
 * Formally, 
 * we want the number of indices i < j with 
 * (time[i] + time[j]) % 60 == 0.
 * 
 * Input: [30,20,150,100,40]
 * Output: 3
 * 两个数的和相加之后能够被60整除即可；
 * 这个题目是twoSum的变体，题目更加灵活；
*/

/**
 * 方法 1，寻找两个数能够被60整除，然后countNum加1，
 * 利用两重for循环，时间复杂度是O(n^2)，太高了；
*/
int numPairsDivisibleBy60(vector<int> &time)
{
    int countNum = 0;
    for (int i = 0; i < time.size(); i++)
    {
        for (int j = i + 1; j < time.size(); j++)
        {
            if ((time[i] + time[j]) % 60 == 0)
            {
                countNum++;
            }
        }
    }
    return countNum;
}

/**
 * 方法 2，优化两层for循环，降低时间复杂度；
 * 
*/
int numPairsDivisibleBy60_1(vector<int> &time)
{
    int len = time.size(), count = 0;
    for(int i=0;i<len;i++)
    {
        if(time[i]==60) count++;
        else if(time[i]> 60)
        {
            if(time[i]%60==0) count++;
            else
            {
                /* code */
            }
            
        }
    }

}
int main()
{
    vector<int> res = {30, 20, 150, 100, 40};
    cout << numPairsDivisibleBy60(res) << endl;
}
