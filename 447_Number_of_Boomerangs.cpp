/*447. Number of Boomerangs

Input:
[[0,0],[1,0],[2,0]]

Output:
2

计算距离相同的点的排列方式，如果是五个点的话，有20中可能。


*/




#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
#include<sstream>

using namespace std;



int numberOfBoomerangs(vector<pair<int, int>>& points)
{
	int res=0;
	for(int i=0;i<points.size();i++)
	{
		unordered_map<int,int>temp;
		for(int j=0;j<points.size();j++)
		{
			int a = points[i].first - points[j].first;
			int b = points[i].second - points[j].second;
			++temp[a*a + b*b];
		}
		for(auto it:temp)
		{
			res+=it.second * (it.second - 1);/*减1是距离的索引为1，肯定不能加，从2算起，所以res不断增加*/
		}
	}
	return res;
}


int main()
{
	vector<pair<int, int>> res = {{1,0},{0,1},{1,1},{2,1},{1,2}};	
	cout<<numberOfBoomerangs(res);
	return 0;

}





























