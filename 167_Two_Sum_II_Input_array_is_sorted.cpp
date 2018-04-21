/*167. Two Sum II - Input array is sorted

O(n)的解法，我们只需要两个指针，一个指向开头，一个指向末尾，然后向中间遍历，如果指向的两个数相加正好等于target的话，
直接返回两个指针的位置即可，若小于target，左指针右移一位，若大于target，右指针左移一位，以此类推直至两个指针相遇停止

*/



#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
using namespace std;


vector<int> twoSum(vector<int>& numbers, int target) 
{
	int l = 0, r = numbers.size() - 1;
	while (l < r) 
	{
		int sum = numbers[l] + numbers[r];
		if (sum == target) return {l + 1, r + 1};
		else if (sum < target) ++l;
		else --r;
	}
	return {}; 
}


int main()
{
	vector<int>nums = {2,7,11,15};
	vector<int>res_inde;
	int t = 9;
	res_inde = twoSum(nums,t);
	for(auto i:res_inde)
		cout<<i<<" ";
	
	return 0;

}























