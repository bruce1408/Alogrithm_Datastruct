/*56  和 57 是很类似的题目，56是给定的区间然后合并，而57新给一个区间。*/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;



struct Interval
{
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};


class Solution
{
	public:
	vector<Interval> insert(vector<Interval>& intervals, Interval newInterval)
	{
		vector<Interval> res;
		
		int i=0;
		//插入区间开始是否大于待输入到结果的区间？如果是的话直接插入这个区间：
		while(i<intervals.size() && newInterval.start>intervals[i].end)
		{
			res.push_back(intervals[i++]);
		}	
		//这个判断是插入区间的结束段是否大于待输入区间的开始部分，如果是的话插入区间
		while(i<intervals.size() && newInterval.end>=intervals[i].start)
		{
			newInterval.start = min(newInterval.start,intervals[i].start);
			newInterval.end = max(newInterval.end,intervals[i].end);
			i++;
		}
		res.push_back(newInterval);
		while(i<intervals.size())
			res.push_back(intervals[i++]);
		
		return res;
	}
	
	static bool comp(Interval a,Interval b)
	{
		return a.start<b.start;
	}
};

int main()
{
	Interval num1(1,2);
	Interval num2(3,5);
	Interval num3(6,7);
	Interval num4(8,10);
	Interval num5(12,16);
	Interval num6(4,9);
	// Interval num4(10,14);
	vector<Interval> nums = {num1,num2,num3,num4,num5};
	Solution ss;
	vector<Interval> res;
	res = ss.insert(nums,num6);
	
	for(int i=0;i<res.size();i++)
		cout<<res[i].start<<" "<<res[i].end<<endl;
	
	return 0;
}