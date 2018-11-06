/*242 是变位词的题目，只要一个单词的顺序稍微改变，即可变成另外的一个单词。

s = "anagram", t = "nagaram", return true.
s = "rat", t = "car", return false.

*/
#include<iostream>
#include<string>
#include<vector>
using namespace std;
//这种解法我还是不太满意，就是对于字符排序的方法怎么解？后面留着在做
// class Solution
// {
	// public:
	// bool isAnagram(string s,string t)
	// {
		// sort(s.begin(),s.end());
		// sort(t.begin(),t.end());
		// return s==t;
	// }
// };
/*方法二：利用哈希来解决*/
bool isAnagram(string s,string t)
{
	if(s.size()!=t.size())
		return false;
	int m1[26] = {0};
	for(int i=0;i<s.size();i++)
		++m1[s[i]-'a'];
	for(int j=0;j<t.size();j++)
	{
		if(--m1[t[j]-'a']<0)
			return false;
	}
	return true;
	
}


int main()
{
	int a[4] = {0};
	for(int i=0;i<4;i++)
		cout<<a[i]<<" ";
}










