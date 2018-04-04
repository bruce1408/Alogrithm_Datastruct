// given [3, 30, 34, 5, 9], the largest formed number is 9534330
/*sort的比较函数的写法是很关键的，还有就是求最小的组合的
  时候要用的是小于号，防止0打头的情况出现。
  */
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

class Solution
{
	public:
	string largestNumber(vector<int> &nums)
	{
		sort(nums.begin(),nums.end(),compare);
		string res;
		for(auto i:nums)
		{
			res+=to_string(i);
		}
		//以下两句是说去掉最小数的时候0打头的情况，一般最大数的同时为0的情况也需要判断
		auto pos = res.find_first_not_of('0');
        return pos == string::npos ? "0" : res.substr(pos);
		// return res; //在求最大的数的时候没有问题，但是如果是最小数的话那么可能有0打头。
	}
	
	
	/*   类内的比较函数一定是静态函数   */
	static bool compare(int a,int b)
	{
		auto stra = to_string(a);
		auto strb = to_string(b);
		return (stra+strb>strb+stra);//小于号就是返回最小数。
	}
	
};


int main()
{
	
	vector<int> num = {0,0,0};
	Solution s;
	
	cout<<s.largestNumber(num)<<endl;
}