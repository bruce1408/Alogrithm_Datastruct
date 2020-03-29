#include <iostream>
#include <vector>
#include <unordered_map>
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
    int sumNum = 0;
    unordered_map<int, int> temp;
    for (int i = 0; i < time.size(); i++)
    {
        time[i] = time[i] % 60;
        temp[time[i]]++;
    }
    for (auto iter = temp.begin(); iter != temp.end();)
    {
        cout << iter->first << " : " << iter->second << endl;
        auto anotherNum = temp.find(60 - iter->first);
        if (anotherNum != temp.end())
        {
            if (iter->first == 60 - iter->first)
            {
                sumNum += (iter->second * (iter->second - 1) / 2);
            }
            else
            {
                sumNum += iter->second * anotherNum->second;
            }
            iter = temp.erase(anotherNum);
        }
        else
        {
            iter++;
        }
    }
    return sumNum;
}

/**
 * 方法 3，利用的是hashmap来做的,思路和方法 2相同，但是方法2在题目上面编译不通过，不知道
 * 为什么，方法3就是更加简单，不再考虑遍历所有的数，而是考虑几个特殊情况，如果0~30之间的
 * 特殊几个边界条件即可；
*/
int numPairsDivisibleBy60_2(vector<int> &time)
{
    int sumNum = 0;
    unordered_map<int, int> temp;
    for (int i = 0; i < time.size(); i++)
    {
        time[i] = time[i] % 60;
        temp[time[i]]++;
    }
    for (auto iter = temp.begin(); iter != temp.end(); iter++)
    {
        cout << iter->first << " : " << iter->second << endl;
        if (iter->first == 0 || iter->first == 30)
        {
            sumNum += temp[iter->first] * (temp[iter->first] - 1) / 2;
        }
        else if (temp.find(60 - iter->first) != temp.end() && iter->first < 30)
        {
            sumNum += iter->second * temp[60 - iter->first];
        }
    }
    return sumNum;
}

/**
 * 方法 4，思路基本一样但是写法更加简单；
*/
int numPairsDivisibleBy60_3(vector<int> &time)
{
    int count = 0, r;
    int l = time.size();
    vector<int> m(60, 0);

    for (int i = 0; i < l; i++)
    {
        r = time[i] % 60;
        int temp =(60-r)%60;
        count += m[(60 - r) % 60];
        m[r]++;
    }
    return count;
}

int main()
{
    vector<int> res = {30, 20, 150, 100, 40};
    cout << numPairsDivisibleBy60_3(res) << endl;
}
