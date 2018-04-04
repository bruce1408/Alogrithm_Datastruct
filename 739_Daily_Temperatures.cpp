/*739. Daily Temperatures  和 503的思路很像  */


#include<iostream>
#include<vector>
#include<stack>
using namespace std;



/*第一种算法：两层for循环，遍历，时间复杂度很高，暴力求解么*/
// class Solution
// {
	// public:
	// vector<int> dailyTemperatures(vector<int>& temperatures)
	// {
		// vector<int> res(temperatures.size(),0);
		// int n = temperatures.size();
		// for(int i=0;i<n;i++)
		// {
			// if(i==n-1)
				// res[i]=0;
			// else if(temperatures[i]<temperatures[i+1])
			// {
				// res[i] = 1;
			// }
			// else
			// {
				// for(int j=i;j<n;j++)
				// {
					// if(temperatures[i]<temperatures[j])
					// {
						// res[i]=j-i;
						// break;
					// }
				// }
			// }			
		// }
		// return res;
	// }
	
// };

/*第二种算法：仿照503，利用栈的思想来做*/
class Solution
{
	public:
	vector<int> dailyTemperatures(vector<int>& temperatures)
	{
		vector<int> res(temperatures.size(),0);
		stack<int> s;
		int index;
		int n = temperatures.size();
		for(int i=0;i<n;i++)
		{
			while(!s.empty() && temperatures[i]>temperatures[s.top()])
			{
				res[s.top()]=i-s.top();
				s.pop();
			}
			// if(i<n)
				// s.push(i);
			s.push(i);//没有n遍循环的话就不需要if来判断
			
			
		}
		return res;
	}
};










int main()
{
	
	vector<int> tem = {73, 74, 75, 71, 69, 72, 76, 73};
	// vector<int> tem = {34,80,80,34,34,80,80,80,80,34};
	Solution ss;
	for(auto i:ss.dailyTemperatures(tem))
		cout<<i<<" ";

	// for(auto i:dailyTemperatures(tem))
		// cout<<i<<" ";
	return 0;
}





























