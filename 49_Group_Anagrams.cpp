/*49. Group Anagrams

Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[["ate","eat","tea"], ["nat","tan"], ["bat"]]

*/

#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
#include<algorithm>
using namespace std;

/*方法一：*/
// vector<vector<string>> groupAnagrams(vector<string>& strs)
// {
	// unordered_map<string,vector<string>>temp;
	// vector<vector<string>> res;
	// for(string str:strs)
	// {
		// string t = str;
		// sort(t.begin(),t.end());
		// temp[t].push_back(str);
	// }
	// for(auto a:temp)
	// {
		// res.push_back(a.second);
	// }
	// return res;
	
// }

/*方法二： 和方法一其实差不多，就是处理每一个字符串的时候方法不一样，和242题目很想*/ 
vector<vector<string>> groupAnagrams(vector<string>& strs)
{
	unordered_map<string,vector<string>>temp;
	vector<vector<string>> res;
	vector<string>m;
	for(string str:strs)
	{
		string t;
		vector<int>m(26,0);
		for(char c:str) ++m[c-'a'];
		for(int d:m) t+=to_string(d);// 相当于是字典的键，然后对于每一个键值相同的元素，全部都添加进去
		temp[t].push_back(str);
	}

	for(auto a:temp) res.push_back(a.second);
	return res;
}



int main()
{
	vector<string>trs = {"eat", "tea", "tan", "ate", "nat", "bat"};
	vector<vector<string>> res;
	res = groupAnagrams(trs);
	for(auto i:res)
	{
		for(auto j:i)
			cout<<j<<" ";
		cout<<endl;
	}
	
	return 0;

}


























