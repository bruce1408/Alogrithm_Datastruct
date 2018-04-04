/*524. Longest Word in Dictionary through Deleting删除后得到的字典中的最长单词*/

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

/*第一种方法；用排序，按字符串的长度由小到大，如果长度相同，按照字幕顺序，然后遍历
  字典里的每一个字符，看待测的字符是不是和他匹配，如果是，返回，因为遍历每个，所以
  后面出现的也可能匹配，最后会返回一个最后匹配的字符*/
// class Solution 
// {
	// public:
    // string findLongestWord(string s, vector<string>& d) 
	// {
        // sort(d.begin(), d.end(),comp);
        // for (string str : d) 
		// {
            // int i = 0;
            // for (char c : s)
			// {
                // if (i < str.size() && c == str[i]) 
					// ++i;
            // }
            // if (i == str.size()) return str;
        // }
        // return "";
    // }
	// static bool comp(string a,string b)
	// {
		// if(a.size() == b.size())
			// return a<b;
		// else
			// return a.size()>b.size();
		
	// }
// };

/*不需要排序；只是用一个记录的数字来更新就可以了
  这个算法很好理解，思路很好！！
  和上面的思路大致一样，只不过没有排序，一直在更新最新的带选取的字符串。如果找到匹
  配的字符串，是否i和字符串的长度一样并且str长度>=存放结果的字符串，然后再看，str字符串
  要比你原来的字符串长度长，或者如果相同的话，我的首字母要小于你的首字母，也就是
  相同长度去字母最小*/

class Solution
{
	public:
	string findLongestWord(string s,vector<string> &d)
	{
		string res = "";
		for(string str:d)
		{
			int i=0;
			for(char c:s)
			{
				if(i<str.size() && c==str[i])
					++i;	
			}
			if(i==str.size() && str.size()>=res.size())
				if(str.size()>res.size() || str<res)//大于和等于两种情况的时候！！
					res = str;
		}
		return res;
	}
};




int main()
{
	string s = "abpcplea";
	// vector<string> d = {"ale","apple","monkey","plea","aplea"};
	vector<string> d = {"a","b","c"};
	string s1;
	Solution ss;
	s1 = ss.findLongestWord(s,d);
	cout<<s1<<endl;
	return 0;
}





























































































































































































































