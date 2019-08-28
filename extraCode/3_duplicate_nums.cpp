/*数组中的重复数字
	哈希是这类题目比较好的解法，不用重新排列数组*/
// The MIT License (MIT)

// Copyright (c) YEAR NAME

//  Permission is hereby granted, free of charge, to any person obtaining a
//  copy of this software and associated documentation files (the "Software"),
//  to deal in the Software without restriction, including without limitation
//  the rights to use, copy, modify, merge, publish, distribute, sublicense,
//  and/or sell copies of the Software, and to permit persons to whom the
//  Software is furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in
//  all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
//  OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
//  FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
//  DEALINGS IN THE SOFTWARE.

// 一般不做任何要求的话，那么就是利用哈希，或者统计出现的次数

// 还可以把当前序列当成是一个下标和下标对应值是相同的数组（时间复杂度为O(n),空间复杂度为O(1)）； 遍历数组，判断当前位的值和下标是否相等：
// 若相等，则遍历下一位；
// 若不等，则将当前位置i上的元素和a[i]位置上的元素比较：若它们相等，则找到了第一个相同的元素；若不等，则将它们两交换。
// 换完之后a[i]位置上的值和它的下标是对应的，但i位置上的元素和下标并不一定对应；重复2的操作，直到当前位置i的值也为i，将i向后移一位，再重复2。
// 本文采用思路3，如果还是不懂，看下面的实例分析就懂了！

// 举例说明：{2,3,1,0,2,5,3}

// 0(索引值)和2(索引值位置的元素)不相等，并且2(索引值位置的元素)和1(以该索引值位置的元素2为索引值的位置的元素)不相等，则交换位置，
// 数组变为：{1,3,2,0,2,5,3}；
// 0(索引值)和1(索引值位置的元素)仍然不相等，并且1(索引值位置的元素)和3(以该索引值位置的元素1为索引值的位置的元素)不相等，则交换位置，
// 数组变为：{3,1,2,0,2,5,3}；
// 0(索引值)和3(索引值位置的元素)仍然不相等，并且3(索引值位置的元素)和0(以该索引值位置的元素3为索引值的位置的元素)不相等，则交换位置，
// 数组变为：{0,1,2,3,2,5,3}；
// 0(索引值)和0(索引值位置的元素)相等，遍历下一个元素；
// 1(索引值)和1(索引值位置的元素)相等，遍历下一个元素；
// 2(索引值)和2(索引值位置的元素)相等，遍历下一个元素；
// 3(索引值)和3(索引值位置的元素)相等，遍历下一个元素；
// 4(索引值)和2(索引值位置的元素)不相等，但是2(索引值位置的元素)和2(以该索引值位置的元素2为索引值的位置的元素)相等，则找到了第一个重复的元素。
//  本篇的代码3-4，3-5就是这个思路，前面的是通过哈希表的情况来做

/*
发散思维，如果是n个数， 从1~n-1之间的话，那么应该怎么做？ leetcode287 就是这么一道题目
*/
/* code */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//3_1 方法1找到所有重复的数字,适用于最一般的情况
vector<int> find_duplicate_nums1(vector<int> res)
{
	sort(res.begin(),res.end());
	vector<int> temp;
	for(int i=0;i<res.size()-1;i++)
	{
		if(res[i+1]-res[i]==0)
			temp.push_back(res[i]);
	}
	return temp;
}


//3_2 方法2哈希表，统计每个数字出现的次数
vector<int> find_duplicate_nums2(vector<int> res)
{
	vector<int>temp(res.size(),0);
	vector<int>u;
	for(auto j:res) ++temp[j];
	for(int i=0;i<temp.size();i++)
	{
		if(temp[i]>1)
			u.push_back(i);
	}
	return u;
}

/*书上3_3,3_4的这种方法超级麻烦，这种类型的利用哈希是比较好的实现方法；
	思路就是如果下标和当前下标的数值不一样了，就交换，直到一样为止，如果这个值和要交换的值一样的话，就是重复数
	这里要注意边界条件是数组的数小于0或者大于数组本身的长度，那么直接就是false*/
//3_3_book 实现
vector<int> find_duplicate_nums3(vector<int> res)
{
	vector<int>temp;
	// 边界条件的问题
	if(res.size()==0)
		return {};
	for(int i=0;i<res.size();i++)
	{
		if(res[i]<0 || res[i]>res.size()-1)
			return temp;
	}
	// 核心代码
	for(int i=0;i<res.size();i++)
	{
		while(res[i]!=i)
		{
			if(res[res[i]]==res[i])
			{
				temp.push_back(res[i]);
				break;
			}	
			else
			{
				int temp=res[i];
				res[i]=res[temp];
				res[temp]=temp;
			}
		}
	}
	return temp;
}


// //3_4 4、5其实是一种方法，但是就是思路比较奇特，找到的是第一个重复的数
bool find_duplicate_nums4(vector<int> res, int *duplication)
{
	if(res.size()==0)
		return false;
	for(int i=0;i<res.size();i++)
	{
		if(res[i]<0 || res[i]>res.size()-1)
			return false;
	}
	for(int i=0;i<res.size();i++)
	{
		while(res[i]!=i)
		{
			if(res[res[i]]==res[i])
			{
				*duplication = res[i];
				return true;
			}
			int temp=res[i];
			res[i]=res[temp];
			res[temp]=temp;
		}
	}
	return false;
}
// //3_5book
bool find_duplicate_nums5(int nums[],int length,int *duplication)
{

	if(nums==nullptr || length<=0)
		return false;
	for(int i=0;i<length;i++)
	{
		if(nums[i]<0 || nums[i]>length-1)
			return false;
	}
	for(int i=0;i<length;i++)
	{
		while(nums[i]!=i)
		{
			if(nums[nums[i]]==nums[i]) // 这一步主要是判断当前的数和之前的数是否相等，如果相等，就把这个数给duplication
			{
				*duplication = nums[i];
				return true;
			}
			int temp=nums[i];
			nums[i]=nums[temp];
			nums[temp]=temp;
		}
	}
	return false;
}

int main()
{
	vector<int>res = {2,3,1,0,2,5,3};
	vector<int>t;
	//3_1
	t = find_duplicate_nums1(res);
	for(auto i:t)
	{
		cout<<i<<endl;
	}
	//3_4
	
	
	int duplication;
	find_duplicate_nums4(res, &duplication);
	cout<<duplication<<endl;
	
	//3_5
	// int res1[] = {1,2,2,5,6};
	// int *p=nullptr;
	// cout<<find_duplicate_nums5(res1,5,p);
}