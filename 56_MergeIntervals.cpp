/*56. Merge Intervals 
  这么一个问题其实很简单，就是说只要你能找到一个对应这个问题的数据类型，然后
  就可以很快求解，关键问题是数据类型是否能够描述出来，然后再利用所有的函数块，
  对抽象问题建模解决。
  此问题的关键之一是构建一个数据类型，然后是写排序函数的comp比较函数。*/

  
/* 容器强大，只要你自己定义一个数据类型，就可以写出一个容器。*/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


// struct Interval 
// {
	// int start;
	// int end;
	// Interval(): start(0), end(0) {}
	// Interval(int s, int e) : start(s), end(e){}
// };


// class Solution {
	// public:
    
    // vector<Interval> merge(vector<Interval>& intervals)
    // {
       
        // vector<Interval> res;     // 存放结果区间
        // if (intervals.empty())   return res; //增加程序的健壮性
        // sort(intervals.begin(), intervals.end(),comp);//sort函数的用法
        // res.push_back(intervals[0]);// 将第一个区间存放进结果中
        // for(int i = 1; i < intervals.size(); ++i)
        // {
            if (res.back().end >= intervals[i].start)
                res.back().end = max(res.back().end, intervals[i].end);// 如果区间有重叠则进行区间融合
            else
                res.push_back(intervals[i]);  // 否则将区间直接存入结果
        // }
        // return res;
    // }
	
	// // 写在类内的比较函数，(必须为静态函数)
	// static bool comp(Interval a, Interval b)
    // {
        // return (a.start < b.start);
    // }      
	
// };



// int main()
// {
	// Interval num1(1,3);
	// Interval num2(2,5);
	// Interval num3(6,9);
	// Interval num4(10,14);
	
	// vector<Interval> inlist = {num1,num2,num3,num4};
	// Solution s;
	// vector<Interval> list_num;
	// list_num = s.merge(inlist);
	
	// for(int i=0;i<list_num.size();i++)
		// cout<<list_num[i].start<<" "<<list_num[i].end<<endl;
		// // cout<<inlist[i].start<<endl;
	
	// return 0;
// }




//手写代码
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
	vector<Interval> merge(vector<Interval> & intervals)
	{
		vector<Interval> res;
		sort(intervals.begin(),intervals.end(),comp);
		res.push_back(intervals[0]);
		for(int i=1;i<intervals.size();i++)
		{
			if(res.back().end>intervals[i].start)
			{
				res.back().end = max(intervals[i].end,res.back().end);
				i++;
			}
			res.push_back(intervals[i]);
		}
		
		return res;
	}
	
	static bool comp(Interval a,Interval b)
	{
		return a.start<b.start;
	}
	
};

int main()
{
	Interval num1(1,3);
	Interval num2(2,5);
	Interval num3(6,9);
	// Interval num4(10,14);
	vector<Interval> nums = {num1,num2,num3};
	Solution ss;
	vector<Interval> res;
	res = ss.merge(nums);
	
	for(int i=0;i<res.size();i++)
		cout<<res[i].start<<" "<<res[i].end<<endl;
	
	return 0;
}







































































