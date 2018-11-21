#include<iostream>
#include<vector>
using namespace std;

void moveZeroes(vector<int> &nums)
{
    /*
        函数功能就是把0移到后面即可；
        思路就是两个指针，第一个找到非0位置， 第二个遍历，然后互换非0数和j 的数字
    */
    for(int i =0,j=0;i<nums.size();i++)
    {
        if(nums[i])
        {
            swap(nums[i],nums[j++]);
        }         
    }
}
int main()
{
    vector<int> res = {0,0,0,1,3,12};
    moveZeroes(res);
    for(auto u: res)
    {
        cout<<u<<" ";
    }

}