#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

/**
 * 给定一个数组，然后看数组里面是否有 数字*2=其他数字 存在
 * 否则返回false
*/

/**
 * 方法 1，使用暴力解法，时间复杂度较高
*/
bool checkIfExist(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr.size(); j++)
        {
            if (arr[i] / 2.0 == arr[j] and i != j)
            {
                return true;
            }
        }
    }
    return false;
}

/**
 * 方法 2,使用hashmap
*/
bool checkIfExist2(vector<int> &arr)
{
    unordered_map<double, int> res;
    for (int i = 0; i < arr.size(); i++)
    {
        res[arr[i]] = i;
    }

    for (int i = 0; i < arr.size(); i++)
    {
        if (res.find(arr[i] / 2.0) != res.end() && res[arr[i] / 2.0] != i)
        {
            return true;
        }
    }
    return false;
}

/**
 * 方法 3，遍历这个数组，查看是否在集合里面有这个数的倍数或者是4倍的关系，如果有的话
 * 那么就直接返回true，否则，返回的是使用一个新的容器来装每个数的倍数，因为如果是倍数关系
 * 那么比如说是[10, 2, 5, 3];
 * 10的2倍是20，那么相对于原来的5的2倍是10，现在就变大了4倍之多。所以，当目前的数字是它本身或者是4的时候，那么就
 * 直接返回true，
 * 另外有数组比如[7,1,14,11], 当7的2倍是14的时候，那么遍历数组当找到14的时候，就是返回当前这个数字；
*/
bool checkIfExist3(vector<int> &arr)
{
    unordered_set<int> m;
    for (auto i : arr)
    {
        if (m.count(i) || m.count(4 * i))
        {
            return true;
        }
        m.insert(2 * i);
    }
    return false;
}

int main()
{
    vector<int> res = {-2, 0, 10, -19, 4, 6, -8};
    cout << checkIfExist3(res) << endl;
}
