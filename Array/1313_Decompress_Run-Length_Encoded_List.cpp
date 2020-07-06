#include <iostream>
#include <vector>
using namespace std;

/**
 * 给定一个数组，然后解码这个数组，具体做法就是每两个数字作为一对，
 * 然后这一对的第一个数字是要重复的值，第二个数字是值，每次给新的数组中添加i个值，
 * 比如[1,1,2,3],第一对是1，1，那么添加的是1个1，第二对是2，3，添加的是2个3即可；
*/
vector<int> decompressRLElist(vector<int> &nums)
{
    vector<int> res;
    for (int i = 0; i < nums.size(); i += 2)
    {
        for (int j = 0; j < nums[i]; j++)
        {
            res.push_back(nums[i + 1]);
        }
    }
    return res;
}
int main()
{
    vector<int> res = {1, 1, 2, 3};
    for (auto i : decompressRLElist(res))
    {
        cout << i << " ";
    }
}