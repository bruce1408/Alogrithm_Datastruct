#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
using namespace std;

/**
 * 第一种方法超时了，效果不是很好，O(n^2)的时间复杂度
 * 逻辑就是按照题目要求的那样去解决就好了，但是时间复杂度太高了
*/
int numEquivDominoPairs(vector<vector<int>> &dominoes)
{
    int count = dominoes.size();
    int cur = 0, after = 0;
    int res = 0;
    while (cur < count)
    {
        for (after = cur + 1; after < count; after++)
        {
            // 满足题目要去就继续加1
            if (((dominoes[cur][0] == dominoes[after][0]) &&
                 (dominoes[cur][1] == dominoes[after][1])) ||
                ((dominoes[cur][0] == dominoes[after][1]) &&
                 dominoes[cur][1] == dominoes[after][0]))
                res += 1;
        }
        cur += 1;
    }
    return res;
}

/**
 * 方法 2， 二维数组变成1位数组即可
 * 使用unordered_map来使用，这里我们考虑，[1,2] = [2,1]的话那么有一种办法就是把二维数组变成一维数组，
 * 让[1,2]=12;[2,1]=21,然后比较两个是否相同，如果相同的话，那么对应的哈希表的元素则加上1，
 * 最后遍历这个哈希表，然后使用组合排列法则来计算，C N 2 = (N-1)*N/2;利用排列法则来计算这个结果即可
*/
int reverseNum(int num)
{
    int sum = 0;
    while (num > 0)
    {
        sum = sum * 10 + (num % 10);
        num = num / 10;
    }
    return sum;
}

int numEquivDominoPairs1(vector<vector<int>> &dominoes)
{
    unordered_map<int, int> temp;
    for (int i = 0; i < dominoes.size(); i++)
    {
        int sumElement = 0;
        for (int j = 0; j < dominoes[i].size(); j++)
        {
            sumElement = sumElement * 10 + dominoes[i][j];
        }
        if ((temp.count(sumElement) > 0) || (temp.count(reverseNum(sumElement)) > 0))
        {
            if (temp.count(sumElement) > 0)
                temp[sumElement] += 1;
            else
                temp[reverseNum(sumElement)] += 1;
        }
        else
            temp[sumElement] = 1;
    }
    int maxNum = 0;
    for (unordered_map<int, int>::iterator iter = temp.begin(); iter != temp.end(); iter++)
    {
        maxNum += (iter->second - 1) * (iter->second) / 2;
    }
    return maxNum;
}

/**
 * 方法2的改进版本：不再使用双层for循环了,但是前提是每个子数组只有两个元素，元素是固定的，如果不是，那么第一种方法可以；
*/
int numEquivDominoPairs1_1(vector<vector<int>> &dominoes)
{
    unordered_map<int, int> temp;
    for (int i = 0; i < dominoes.size(); i++)
    {
        temp[min(dominoes[i][0], dominoes[i][1]) * 10 + max(dominoes[i][0], dominoes[i][1])] += 1;
    }
    int maxNum = 0;
    for (unordered_map<int, int>::iterator iter = temp.begin(); iter != temp.end(); iter++)
    {
        maxNum += (iter->second - 1) * (iter->second) / 2;
    }
    return maxNum;
}

/**
 * 方法3， 只用一层for循环即可，整体思路还是二维数组变成一维数组，但是有技巧，我们不再把每个数组的元素相加变成一个整数了
 * 而是使用使用map来存储每个子数组，map<pair<int, int>, int>temp;遍历二维数组，如果每次遍历的时候，子数组的第一个数字大于第二个数字，那么
 * 就交换即可，然后再添加到map的临时容器中，最后按照排列法则去排列即可
*/
int numEquivDominoPairs2(vector<vector<int>> &dominoes)
{
    int result = 0;
    map<pair<int, int>, int> temp;
    for (auto &i : dominoes)
    {
        if (i[0] > i[1])
            swap(i[0], i[1]);
        temp[make_pair(i[0], i[1])] += 1;
    }
    for (auto p = temp.begin(); p != temp.end(); p++)
    {
        result += p->second * (p->second - 1) / 2;
    }
    return result;
}

/**
 * 方法4 不是很能理解下面的写法
*/
int numEquivDominoPairs5(vector<vector<int>> &dominoes)
{
    unordered_map<int, int> count;
    int res = 0;
    for (auto &d : dominoes)
    {
        res += count[min(d[0], d[1]) * 10 + max(d[0], d[1])]++;
    }
    return res;
}

int main()
{
    vector<vector<int>> res = {
        {1, 2},
        {2, 1},
        {3, 4},
        {5, 6}};
    cout << numEquivDominoPairs1_1(res) << endl;
    // cout << numEquivDominoPairs2(res) << endl;
    // cout << reverseNum(12) << endl;
}
