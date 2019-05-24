#include<iostream>
#include<vector>
using namespace std;

// 二分查找，前提条件是必须是有序的数组，然后可以利用二分查找
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
        while(left<=right) // if only one num in vector, the "=" is important !
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

