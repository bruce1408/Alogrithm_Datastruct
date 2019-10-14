#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;
/**
 * 方法 1，标准答案,后来自己做的和这个答案也是类似的，思路就是
 * 和计数排序的思路很接近，因为数组的长度是小于等于1000的，且数组的元素
 * 取值范围是从0 到 1000，那么我们新建一个长度是1001的新数组res,(可以取值是0-1000)
 * 这个res用来记录原数组arr1中元素出现的次数，再建立一个结果数组ans，用来返回最后的结果，
 * 长度初始默认为和arr1的长度相同，然后开始遍历参考数组arr2，对于每一个arr2，
 * 如果res[arr1[i]]中对应的元素次数是大于0的，那么就把这个值给ans数组，同时res[arr1[i]]--
 * 最后把arr2中的数组全都遍历完了，开始把剩余的arr2没有的元素按照升序的方式装进ans中，
 * 这个时候利用的就是计数排序的思想，其实res本来就是记录的元素出现的次数，这个时候继续对res进行
 * 遍历即可，从0开始到res.size()之间，如果res[i]>0,那么结果放进ans中间去，res[i]--;最后返回
 * 结果数组ans即可。
 * 
*/
vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2)
{
    vector<int> res(1001, 0);
    vector<int> ans(arr1.size());
    int k = 0;
    for (int i = 0; i < arr1.size(); i++)
    {
        res[arr1[i]]++; // arr1中每一个数的次数
    }

    for (int i = 0; i < arr2.size(); i++)
    {
        while (res[arr2[i]] > 0)
        {
            ans[k++] = arr2[i];
            res[arr2[i]]--;
        }
    }
    for (int i = 0; i < 1001; i++)
    {
        while (res[i] > 0)
        {
            ans[k++] = i;
            res[i]--;
        }
    }
    return ans;
}

/**
 * 方法 2，并不是这道题目的解，他只能按照参考数组2对数组1进行一个排列，凡是数组1中不在
 * 数组2的元素，都会按照原来的位置，不是按照题目要求的升序排列。所以仅供参考而已，这里
 * 使用了双指针，不需要开辟新的空间。如果题目要求变了，这个就是满足的。
 * arr1是长数组，arr2是短数组,个人做法思路很自然，就是遍历短的数组，然后开始
 * 匹配长的数组的每一个数字，看是不是和短数组当前的数字相同，如果不同，那么就
 * 遍历长数组，找到相同的数字然后替换，终止条件是如果找到最后了也没有找到，说明
 * 这个数字已经找完了，那么就进行下一个数字的匹配即可；
 * 我个人的做法虽然满足数字条件，但是结果不是升序排列；需要考虑其他解法，而且
 * 时间复杂度较高。
*/
vector<int> relativeSortArray1(vector<int> &arr1, vector<int> &arr2)
{
    int index = 0, len = arr1.size();
    for (int i = 0; i < arr2.size(); i++)
    {
        bool breakCut = true;
        while (index < len && breakCut)
        {
            int temp = index; // 新的指针temp指向index所在的位置
            if (arr2[i] != arr1[index])
            {
                while (temp < len)
                {
                    if (arr2[i] == arr1[temp])
                    {
                        swap(arr1[index], arr1[temp]);
                        break;
                    }
                    else temp += 1;
                }
            }
            if (temp == len) breakCut = false;
            else index++;
        }
    }
    return arr1;
}

/**
 * 方法 3，是后面自己摸索着做的，发现和方法 1其实完全一样，都是利用了新的数组
 * 来保存元素出现的次数，解题思路参考方法 1吧。
*/
vector<int> relativeSortArray2(vector<int> &arr1, vector<int> &arr2)
{
    vector<int> res(1001);
    vector<int> temp(arr1.size());
    int j = 0;
    for (int i = 0; i < arr1.size(); i++)
    {
        res[arr1[i]]++;
    }
    for (int i = 0; i < arr2.size(); i++)
    {
        while (res[arr2[i]] > 0)
        {
            temp[j++] = arr2[i];
            res[arr2[i]]--;
        }
    }
    for (int i = 0; i < res.size(); i++)
    {
        while (res[i] > 0)
        {
            temp[j++] = i;
            res[i]--;
        }
    }
    return temp;
}

int main()
{
    vector<int> arr1 = {2, 21, 43, 38, 0, 42, 33, 7, 24, 13, 12, 27, 12, 24, 5, 23, 29, 48, 30, 31},
                arr2 = {2, 42, 38, 0, 43, 21};
    vector<int> res = relativeSortArray2(arr1, arr2);
    for (auto i : res)
    {
        cout << i << " ";
    }
    cout << endl;
}
