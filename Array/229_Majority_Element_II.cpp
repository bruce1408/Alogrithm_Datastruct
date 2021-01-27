#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * 229 给定一个数组，然后求重复次数超过n/3的个数的数字，返回一个数组
*/

/**
 * 方法 1，投票法
 * */
vector<int> majorityElement1(vector<int> &nums)
{
    int r1 = 0, r2 = 0, c1 = 0, c2 = 0;
    int n = nums.size() / 3;
    for(int i=0;i<nums.size();i++)
    {
        if(c1 && nums[i] == r1) c1++; // 如果当前数和r1相同，c1自加
        else if(c2 && nums[i]==r2) c2++; // 如果和r2相同，c2自加
        else if(c1==0) r1 = nums[i], c1 = 1; // c1 等于0的话，当前数给r1且c1自加 
        else if(c2==0) r2 = nums[i], c2 = 1; // c2等于0的话，当前数给r2且c2自加
        else c1--, c2--; // c1自减，c2自减
    }

    c1 = c2 = 0; // 重新开始统计r1和r2的次数，如果大于要求就存到结果数组
    for(auto x : nums)
    {
        if(x==r1) c1++; 
        else if(x==r2) c2++;
    }
    vector<int>res;
    if(c1 > n) res.push_back(r1);
    if(c2 > n) res.push_back(r2);

}

int main()
{
    vector<int> res = {3, 2, 2, 2, 1, 1, 2, 3, 3, 3};
    for (auto i : majorityElement2(res))
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}