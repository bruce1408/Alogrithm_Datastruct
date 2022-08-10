#include<iostream>
#include<vector>
using namespace std;

/**
 * @brief 
 * 给定一个数组，然后查找其中目标值是否存在数组之中，返回即可
 */
class Solution {
public:
    // solution one; easy to write ,and the time complex is equal to the solution two;
	// int search(vector<int> &nums, int target) {
	// 	int begin = 0, end = nums.size();
	// 	while (begin != end) {
	// 		int middle = (begin + end) / 2;
	// 		if (nums[middle] < target)
	// 			begin = middle + 1;
	// 		else
	// 			end = middle;
	// 	}
	// 	return begin == nums.size() || nums[begin] > target ? -1 : begin;
	// }
    
    // solution two,
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0, right = n-1;
        while(left<=right) // 如果容器中只有一个数，那么就需要“=”，重点！
        {
            int mid = left + (right - left)/2;
            if(nums[mid]>target)
            {
                right = mid-1;
            }
            else if(nums[mid]<target)
            {
                left = mid + 1;
            }
            else return mid;
        }
        return -1;
    }
};

int main()
{
    Solution s;
    vector<int> res = {5};
    cout<<s.search(res, 5)<<endl;
}

