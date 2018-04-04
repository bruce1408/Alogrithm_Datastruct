/*503，寻找循环数组的最大值；循环数组的遍历使用：数组如何循环遍历是关键！
	用到了栈，求余操作。
*/

#include<iostream>
#include<vector>
using namespace std;


/*	第一个函数和第二个函数的思路相同，但是具体初始化不同，定义一个容器，
	没有初始化数组是一个循环数组，就是说某一个元素的下一个较大值可以在其前面，
	那么对于循环数组的遍历，为了使下标不超过数组的长度，我们需要对n取余，
	下面先来看暴力破解的方法，遍历每一个数字，	然后对于每一个遍历到的数字，
	遍历所有其他数字，注意不是遍历到数组末尾，而是通过循环数组遍历其前一个数字，
	遇到较大值则存入结果res中，并break，再进行下一个数字的遍历
*/
	
vector<int> nextGreaterElements(vector<int>& nums)//时间算法复杂度高
{
	int n = nums.size();
	vector<int> res;                   //比较粗糙的初始化
	int j=0,k=0;
	int count=0;
	for(int i=0;i<n;i++)
	{
		for(j=i+1;j<i+n;++j)
		{
			if(nums[i]<nums[j%n])
			{
				res.push_back(nums[j%n]);
				break;
			}
			count++;
			if(count==n)
				res.push_back(-1);
			
		}
		
	}
	return res;
}

/*初始化，自动包括了最大数都不满足取值为-1的情况。*/
// class Solution {
// public:
    // vector<int> nextGreaterElements(vector<int>& nums) 
	// {
        // int n = nums.size();
        // vector<int> res(n, -1);                 //容器初始化，常用的！不是只定义，而是定义长度和初始值。
        // for (int i = 0; i < n; ++i) 
		// {
            // for (int j = i + 1; j < i + n; ++j) 
			// {
                // if (nums[i] < nums[j % n]) 
				// {
                    // res[i] = nums[j % n];
                    // break;
                // }
            // }
        // }
        // return res;
    // }
// };


/*方法2：对原来的数组遍历两遍！而且利用了栈！这个时间复杂度更加好一些，
	逻辑非常重要！*/

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) 
	{
        int n = nums.size();
        vector<int> res(n, -1);
        stack<int> st;
        for (int i = 0; i < 2 * n; ++i) 
		{
            int num = nums[i % n];
            while (!st.empty() && nums[st.top()] < num) 
			{
                res[st.top()] = num; st.pop();
            }
            if (i < n) st.push(i);
        }
        return res;
    }
};


/*方法3：时间优化比2更好一些。leetcode上时间复杂度排第一的算法*/
class Solution 
{
	public:
    vector<int> nextGreaterElements(vector<int>& nums)
    {
        int len = nums.size();
        stack<int> s;
        vector<int> ret(len, -1);
        for (int i = 0; i < nums.size(); ++i)
        {
            while (!s.empty() && nums[s.top()] < nums[i])
            {
                ret[s.top()] = nums[i];
                s.pop();
            }
            s.push(i);
        }
        
        for (int i = 0; i < len; ++i)
        {
            while (!s.empty() && nums[s.top()] < nums[i])
            {
                ret[s.top()] = nums[i];
                s.pop();
            }
        }
        return ret;
    }
};



int main()
{
	vector<int>nums = {3,8,4,1,2};
	vector<int> res;
	Solution ss;
	res = ss.nextGreaterElements(nums);
	for(auto i:res)
		cout<<i<<" ";
	
	return 0;
	
}




















