/*242 是变位词的题目，只要一个单词的顺序稍微改变，即可变成另外的一个单词。*/

//这种解法我还是不太满意，就是对于字符排序的方法怎么解？后面留着在做
class Solution
{
	public:
	bool isAnagram(string s,string t)
	{
		sort(s.begin(),s.end());
		sort(t.begin(),t.end());
		return s==t;
	}
}；