#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

/**
 * 方法 1,设置一个记录偶数个数的值nums,然后开始记录,从头开始遍历数组
 * 对当前的数字计算他是几位数,如果是偶数位,那么就记录数+1即可,最后返回
 * 这个记录的数字
 * 时间复杂度是O(nxm)m是数组里面最大的那个数的位数
*/
int findNumbers(vector<int>& nums)
{
    int n = nums.size(), countNum = 0;
    for(int i=0;i<n;i++)
    {
        int result = 0;
        while(nums[i])
        {
            nums[i] = nums[i]/10;
            result+=1;
        }
        if (result%2==0)
        {
            countNum+=1;
        }
    }
    return countNum;
}

/**
 * 方法 2,利用数学上的方法,简化计算,只用一遍for循环即可
 * 利用log以10为底数的函数来会减少一层while循环;
 * 
*/
int findNumbers1(vector<int>& arr)
{
    int n = arr.size(), countNum = 0;
    for(int i=0;i<n;i++)
    {
        if (int(log10(arr[i])+1)%2==0)
        {
            countNum +=1;
        }
    }
    return countNum;
}

/**
 * 方法 3,利用题目给的条件,每一个数组中的数字都是在1 到 10的5次方之间
 * 所以可以用判断语句来写,每一个数字只有在10~99或者是1000~9999范围
 * 是偶数,这种情况下才加1即可;
 * 
 * 这种方法不具有一般性,方法 1/2是比较好的方法;
*/
int findNumbers2(vector<int>& arr)
{
    int n = arr.size(), countNum = 0;
    for(int i=0;i<n;i++)
    {
        if((arr[i] <= 99 && arr[i] >= 10) || (9999 >=arr[i] && arr[i]>=1000))
        {
            countNum+=1;
        }
    }
    return countNum;
}

int main()
{
    vector<int>nums = {12,345,2,6,7896};
    cout<<findNumbers2(nums)<<endl;
}