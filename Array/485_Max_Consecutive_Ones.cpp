#include<iostream>
#include<vector>
using namespace std;

/**
 * Given a binary array, find the maximum number of consecutive 1s in this array.
 * Example 1:
 * Input: [1,1,0,1,1,1]
 * Output: 3
 * 
 * Explanation: The first two digits or the last three digits are consecutive 1s.
 * The maximum number of consecutive 1s is 3.
 * 找到数字中连续出现1最多的次数
*/

/**
 * 方法 1, 找两个变量,一个是全局变量记录最大的和局部最大值的变量,便利数组,然后当前的值是1的话,那么就让局部便利加1,否则,把全局变量
 * 和局部变量的最大值给全局变量,最后把最大的值返回即可.时间复杂度是O(n),空间复杂度是O(1)
 * 
*/
int findMaxConsecutiveOnes(vector<int>& nums){
    int zeroCount=0, index = 0, tempCount = 0;
    while(index<nums.size())
    {
        if(nums[index]&1) zeroCount+=1;
        else
        {
            tempCount = max(zeroCount, tempCount);
            zeroCount=0;
        } 
        index++;
    }
    return max(tempCount, zeroCount);
}


/**
 * 方法 2,此方法超时,记录的连续的出现1的个数,但是这个思路自然,写法并不讨巧.
 * */
class Solution1 {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 1, maxnum = 0;
        if (nums.size() == 1) return 1;
        if (nums.size()>1)
        {  
            for(int i=0;i<nums.size();i++)
            {
                int flag = i+1;
                if(nums[i]==nums[flag] && flag<nums.size()) count+=1;
                else{
                    if(count >= maxnum) maxnum=count;
                    count=1;
                }
            }
        }
        return maxnum;
    }
};

/**
 * 方法 3, 这个方法和我自己写的方法1思路完全是一样的.
 * */
class Solution2 {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        if (nums.size() == 1) return nums[0]==1? 1 : 0;
        int count = 0, maxnum = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==1) count+=1;
            else count=0;
            maxnum = max(maxnum, count);
        }
        return maxnum;
    }
};

/**
 * 方法 4,这个思路都是一样的,但是写法更加巧妙,一般不会想到这么写,不过还是很fancy
 * */
class Solution3 {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        if (nums.size() == 1) return nums[0]==1? 1 : 0;
        int count = 0, maxnum = 0;
        for(int i=0;i<nums.size();i++)
        {
            count = (nums[i]+count)*nums[i]; 
            maxnum = max(maxnum, count);
        }
        return maxnum;
    }
};

int main()
{  
    vector<int> num = {1,1,0,1,1,1};
    // 方法 1
    // Solution s;
    // int a = s.findMaxConsecutiveOnes(num);
    // 方法 2
    cout<<findMaxConsecutiveOnes(num)<<endl;
}