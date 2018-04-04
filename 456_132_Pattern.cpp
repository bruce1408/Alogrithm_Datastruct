/*456. 132 Pattern 判断一个数组是否是132模式*/

#include<iostream>
#include<vector>
#include<stack>
using namespace std;


//方法1
bool find132pattern(vector<int>& nums)
{
	if(nums.size()<=2) return false;
	stack<int>s;
	int i=0,j=0,k=0;
	int min=nums[0];
	int max=nums[0];
	int mid=nums[0];
	int count=0;
	int count1=0;
	
	for(int a=0;a<nums.size()-1;a++) // 判断升序
	{
		if(nums[a]<nums[a+1])
			count++;
	}
	for(int a=0;a<nums.size()-1;a++) // 判断降序
	{
		if(nums[a]<nums[a+1])
			count++;
	}
	
	if(count==nums.size()-1) return false;
	if(count1==nums.size()-1) return false;

	while(i<nums.size())  // 找最小值
	{
		if(min>nums[i])
		{	
			min = nums[i];
			s.push(i);
		}
		i++;
	}
		
	if(s.size()==0)
		s.push(0);
	
	while(j<nums.size())  // 找最大值
	{
		if(max<nums[j])
		{	
			max = nums[j];
			s.push(j);
		}
		j++;
	}
	
	
	while(k<nums.size()) //找中间值
	{
		if(nums[k]<max && nums[k]>min && k>s.top())
		{
			s.push(k);	
		}
		k++;
	}
	
	if(s.size()==3)
		return true;
	else return false;
	
}

// 方法2
class Solution {
public:
    bool find132pattern(vector<int>& nums) 
	{
        if (nums.size() < 3) return false;
        int n = nums.size(), i = 0, j = 0, k = 0;
        while (i < n) 
		{
            while (i < n - 1 && nums[i] >= nums[i + 1]) ++i;  //求最小的数
            j = i + 1;                                        //最小的数的下标
            while (j < n - 1 && nums[j] <= nums[j + 1]) ++j;  //最大的数字
            k = j + 1;                                        //最大的数的下标
            while (k < n)                                     //中间数字，注意，这个数字的下标缺失最大的   
			{
                if (nums[k] > nums[i] && nums[k] < nums[j]) return true;  //判断k是否是中间的数字
                ++k;
            }
            i = j + 1;// 如果上面的k都不是的话，那么就从i从j+1开始重新查找。
        }
        return false;
    }
};



//方法3
class Solution {
public:
    bool find132pattern(vector<int>& nums) 
	{
        if(nums.size()<3) return false;
        int s3=INT_MIN;
        stack<int> st;
		
        for(int i=nums.size()-1; i>=0; i--)
		{
            if(nums[i]<s3) return true;
            while(!st.empty() && nums[i]>st.top())
			{
                s3=st.top(); st.pop();
            }
            st.push(nums[i]);
        }
        return false;
    }
};

int main()
{
	vector<int> nums = {3, 1, 4, 2};
	// vector<int> nums = {1, 2, 3, 4};
	// vector<int> nums = {-1, 3, 2, 0};
	// vector<int> nums = {4,3,2,1};
	Solution ss;
	cout<<ss.find132pattern(nums);
	cout<<INT_MIN<<endl;
	return 0;
}































































