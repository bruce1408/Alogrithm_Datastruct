/*594. Longest Harmonious Subsequence
Input: [1,3,2,2,5,2,3,7]
Output: 5
Explanation: The longest harmonious subsequence is [3,2,2,2,3].

寻找和谐序列，最大值和最小值相差1即可。
方法1是后一个减去前一个，如果是1就加，方法2是只要加1存在，就相加，方法2思路更好一些
*/

#include<iostream>
#include<vector>
#include<map>
#include<string>
using namespace std;


//方法1
int findLHS(vector<int>& nums)
{
	if(nums.size()==0) return 0;
	int max_size=0;
	map<int,int>temp;
	for(auto i: nums) ++temp[i];
	for(auto it = next(temp.begin());it!=temp.end();it++)
	{
		auto pre = prev(it);
		if(it->first - pre->first==1)
			max_size = max(max_size,it->second+pre->second);
	}
	return max_size;
	
}

//方法2
int findLHS(vector<int>& nums) 
{
	int res = 0;
	map<int, int> m;
	for (int num : nums) ++m[num];
	for (auto a : m) 
	{
		if (m.count(a.first + 1)) 
		{
			res = max(res, m[a.first] + m[a.first + 1]);
		}
	}
	return res;
}





int main()
{
	vector<int>res= {1,3,2,2,5,2,3,7};
	cout<<findLHS(res);
	
	
	return 0;

}












































































