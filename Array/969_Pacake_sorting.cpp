#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

/**
 * 方法1，先找到这个数组中的最大的数字
 * 翻转排序(也叫煎饼排序？)
 * 然后把这个数字和前面的翻转，然后再把第一个数字和最后一个数字
 * 翻转，这样，最大的数字就放到了最后一位；然后开始继续找下一个
 * 第二大的数字即可
 * 方法1 并不能解决这个题目，只是翻转排序的思路，写的逻辑不是很好
 * 从1_1开始参考
*/
vector<int> pancakeSort1(vector<int> &A)
{
    vector<int> res;
    int n = A.size(), beginIndex;
    for (beginIndex = n; beginIndex > 0; beginIndex--)
    {
        vector<int>::iterator iter = max_element(A.begin(), A.begin() + beginIndex);
        int position = iter - A.begin(); // 最大值的位置
        cout << beginIndex << " " << position << endl;
        if (position != beginIndex - 1)
        {
            if (position != 0)
            {
                for (int i = 0; i <= (position) / 2; i++)
                {
                    swap(A[i], A[position - i]);
                }
                swap(A[0], A[beginIndex - 1]);
            }
            else
            {
                for (int j = 0; j < beginIndex / 2; j++)
                {
                    cout << beginIndex << " " << j << endl;
                    swap(A[j], A[beginIndex - j - 1]);
                }
            }
        }
        res.push_back(position + 1);
        for (auto i : A)
        {
            cout << i << " ";
        }
        cout << endl;
        res.push_back(beginIndex);
    }
    return A;
    // return res;
}

/**
 * 方法1_1, 思路一样，就是利用stl来做，写法更加简单
*/
vector<int> pancakeSort1_1(vector<int> &A)
{
    vector<int> res;
    int n = A.size(), beginIndex;
    for (beginIndex = n; beginIndex > 0; beginIndex--)
    {
        vector<int>::iterator iter = max_element(A.begin(), A.begin() + beginIndex);
        int position = iter - A.begin(); // 最大值的位置，从0开始计数
        cout << beginIndex << " " << position << endl;
        if (position != beginIndex - 1)
        {
            reverse(A.begin(), A.begin() + position + 1);
            reverse(A.begin(), A.begin() + beginIndex);
        }
        res.push_back(position + 1);
        cout << endl;
        res.push_back(beginIndex);
    }
    return A;
    // return res;
}

/**
 * 方法2，和方法1的思路是一样的，写法更加简单
*/
vector<int> pancakeSort2(vector<int> &A)
{
    vector<int> tmp, rev, ans;
    tmp = rev = A;
    sort(tmp.begin(), tmp.end());
    int ptr = A.size() - 1;
    for (int i = 0; i < tmp.size(); i++)
    {
        int j;
        for (j = 0; j < A.size(); j++)
            if (A[j] == tmp[i])
                break;
        reverse(A.begin(), A.begin() + (j + 1));
        ans.push_back(j + 1);
        reverse(A.begin(), A.begin() + (ptr + 1));
        ans.push_back(ptr + 1);
        ptr--;
        for (auto i : A)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    ans.push_back(A.size());
    return ans;
}

/**
 * 方法3，思路都和上面一样；写法更加简单
*/
vector<int> pancakeSort3(vector<int> &A)
{
    vector<int> res;
    int x, i;
    for (x = A.size(); x > 0; --x)
    {
        for (i = 0; A[i] != x; ++i)
        {
        };
        reverse(A.begin(), A.begin() + i + 1);
        cout << endl;
        res.push_back(i + 1);
        reverse(A.begin(), A.begin() + x);
        for (auto i : A)
        {
            cout << i << " ";
        }
        res.push_back(x);
    }
    return res;
}

int main()
{
    vector<int> res = {3, 2, 4, 1};
    cout << endl;
    for (auto i : pancakeSort1(res))
    {
        cout << i << " ";
    }
}