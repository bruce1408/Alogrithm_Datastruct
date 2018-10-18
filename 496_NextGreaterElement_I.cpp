/*	496. Next Greater Element I
	Input: nums1 = [4,1,2], nums2 = [1,3,4,2].
	Output: [-1,3,-1]
*/
// #include<iostream>
// #include<vector>
// #include<unordered_map>
// using namespace std;



/*这种方法是右边的第一个数大于就保存，否则是-1*/
// vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums)
// {
	
	// vector<int> temp;
	// for(auto index:findNums)
	// {
		// for(int i=0;i<nums.size();i++)
		// {
			// if(index==nums[i])
			// {
				// if(i+1!=nums.size() && nums[i+1]>index)
				// {
					// temp.push_back(nums[i+1]);
					// break;
				// }
				// else
					// temp.push_back(-1);	
			// }
		// }
	// }	
	// return temp;
// }






/*这才是题目要求的，如果后面只有一个大于的，那么遍历大于的数放进去*/
// vector<int> nextGreaterElement1(vector<int>& findNums, vector<int>& nums)
// {
	// vector<int> res(findNums.size());
	// for (int i = 0; i < findNums.size(); ++i) 
	// {
		// int j = 0, k = 0;
		// for (; j < nums.size(); ++j) 
		// {
			// if (nums[j] == findNums[i]) break; //保存j的位置
		// }
		// for (k = j + 1; k < nums.size(); ++k)  // 从j开始向后遍历数组
		// {
			// if (nums[j] < nums[k]) //如果是找到了，放到里面，否则k==长度的时候，为-1
			// {
				// res[i] = nums[k];
				// break;
			// }
		// }
		// if (k == nums.size()) res[i] = -1;
	// }
	// return res;
// }

/*上面的解决方案时间复杂度太高，用下面这种方法来解决*/
class Solution 
{
	public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) 
	{
        vector<int> res(findNums.size());
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); ++i) 
		{
            m[nums[i]] = i;
        }
        for (int i = 0; i < findNums.size(); ++i) 
		{
            res[i] = -1;
            int start = m[findNums[i]];
            for (int j = start + 1; j < nums.size(); ++j) 
			{
                if (nums[j] > findNums[i]) {
                    res[i] = nums[j];
                    break;
                }
            }
        }
        return res;
    }
};

/*第三种解法，这种解法很好理解，但是时间复杂度没有降下来。*/
int search(vector<int> &nums,int A)
{
    int i=0;
    for(i=0;i<nums.size();i++)
        if(nums[i] == A)
            break;
    
    if(i == nums.size() || i == nums.size()-1)
        return -1;
    
    for(;i<nums.size();i++)
        if(nums[i] > A)
            return nums[i];
    
    return -1;
}


vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) 
{
    
    vector<int> ans(findNums.size());
    for(int i=0;i<findNums.size();i++)
    {
        ans[i] = search(nums,findNums[i]);
    }
    return ans;
}



int main()
{
	vector<int> a = {1,3,5,2,4};
	// vector<int> a = {4,1,2};
	// vector<int> b = {1,3,4,2};
	vector<int> b = {6,5,4,3,2,1,7};
	vector<int> c;
	Solution ss;
	c = ss.nextGreaterElement(a,b);
	for(auto i:c)
		cout<<i<<endl;
	return 0;	
}



























