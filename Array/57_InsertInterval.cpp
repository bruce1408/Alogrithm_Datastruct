#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
/**
 * 57 区间插入，给定一个区间数组，按照第一个元素排列的有序区间。然后插入一个新的
 * 区间，新的区间可能会和原来区间进行合并，所以最后返回这个区间
 * */
// struct Interval
// {
// 	int start;
// 	int end;
// 	Interval() : start(0), end(0) {}
// 	Interval(int s, int e) : start(s), end(e) {}
// };

// class Solution
// {
// 	public:
// 	vector<Interval> insert(vector<Interval>& intervals, Interval newInterval)
// 	{
// 		vector<Interval> res;
		
// 		int i=0;
// 		//插入区间开始是否大于待输入到结果的区间？如果是的话直接插入这个区间：
// 		while(i<intervals.size() && newInterval.start>intervals[i].end)
// 		{
// 			res.push_back(intervals[i++]);
// 		}	
// 		//这个判断是插入区间的结束段是否大于待输入区间的开始部分，如果是的话插入区间
// 		while(i<intervals.size() && newInterval.end>=intervals[i].start)
// 		{
// 			newInterval.start = min(newInterval.start,intervals[i].start);
// 			newInterval.end = max(newInterval.end,intervals[i].end);
// 			i++;
// 		}
// 		res.push_back(newInterval);
// 		while(i<intervals.size())
// 			res.push_back(intervals[i++]);
		
// 		return res;
// 	}
	
// 	static bool comp(Interval a,Interval b)
// 	{
// 		return a.start<b.start;
// 	}
// };

vector<vector<int>> insert(vector<vector<int>>& s, vector<int>& t) 
{
	vector<vector<int>>res ;

}

int main()
{
	vector<vector<int>>res = {{1,3},{6,9}};
	vector<int> ne = [{2, 5};
	for(auto x: insert(res, ne))
	{
		for(auto i:x)
		{
			cout<<i<<" ";
		}
		cout<<endl;
	}

}