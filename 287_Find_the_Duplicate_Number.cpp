#include<iostream>
#include<vector>

using namespace std;
/**
 * 找到第一个不重复的数，数的范围限定在1--n之间，利用快慢指针，由于是
 * 重复的数，肯定会形成闭环，用快慢指针找到环的起始位置，用两次while，第一次
 * 找到相交的入口处。
 * 第二次就是找重复数的过程。
 * */
int findDuplicate(vector<int>&nums)
{
    int slow=0, fast=0;
    while(true)
    {
        slow = nums[slow];
        fast = nums[nums[fast]];
        if(slow==fast)
        {
            break;
        }
    }
    int t=0;
    while(true)
    {
        slow = nums[slow];
        t = nums[t];
        if(slow==t) break;
    }
    return slow;
}
int main()
{
    vector<int> a = {2,5,9,6,9,3,8,9,7,1};
    cout<<findDuplicate(a)<<endl;

}