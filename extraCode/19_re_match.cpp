// #include<iostream>
// #include<string>
// using namespace std;
// ////直接是用string 类来做，没有用指针
// bool matchCore(string str ,int nums,string pattern,int nump)
// {
// 	if(nums==str.size()-1 && pattern.size()-1==nump) return true;
// 	if(nums!=str.size()-1 && pattern.size()-1==nump) return false;
// 	if(pattern[nump+1]=='*')
// 	{
// 		if(pattern[nump]==str[nums] || (pattern[nump]=='.' && nums!=str.size()-1))
// 			return matchCore(str,nums+1,pattern,nump+2) 
// 			|| matchCore(str,nums+1,pattern,nump)|| matchCore(str,nums,pattern,nump+2);
// 		else
// 			return matchCore(str,nums,pattern,nump+2);
// 	}
// 	if(str[nums]==pattern[nump] ||(pattern[nump]=='.' &&nums!=str.size()-1))
// 		return matchCore(str,nums+1,pattern,nump+1);
// 	return false;
// }
// bool match(string str,string pattern)
// {
// 	if(str.size()==0 || pattern.size()==0)
// 		return false;
// 	return matchCore(str,0,pattern,0);
// }
// int main()
// {
// 	string str = "aaa";
// 	string pattern = "a.a";
// 	cout<<match(str,pattern);
// }
/*----------------------------------------------------------*/
#include<iostream>
#include<string>
using namespace std;

/**
 * 题目：正则表达式匹配
 * 方法：动态规划的问题
 * 思路：递归方法
 * 需要用递归Recursion来解，大概思路如下：
 * 若p为空，若s也为空，返回true，反之返回false。
 * 若p的长度为1，若s长度也为1，且相同或是p为'.'则返回true，反之返回false。
 * 若p的第二个字符不为*，若此时s为空返回false，否则判断首字符是否匹配，
 * 且从各自的第二个字符开始调用递归函数匹配。
 * 若p的第二个字符为*，进行下列循环，条件是若s不为空且首字符匹配（包括p[0]为点），
 * 调用递归函数匹配s和去掉前两个字符的p（这样做的原因是假设此时的星号的作用是让前面的字符出现0次，
 * 验证是否匹配），若匹配返回true，否则s去掉首字母（因为此时首字母匹配了，我们可以去掉s的首字母，
 * 而p由于星号的作用，可以有任意个首字母，所以不需要去掉），继续进行循环。
 * 返回调用递归函数匹配s和去掉前两个字符的p的结果（这么做的原因是处理星号无法匹配的内容，
 * 比如s="ab", p="a*b"，直接进入while循环后，我们发现"ab"和"b"不匹配，所以s变成"b"，
 * 那么此时跳出循环后，就到最后的return来比较"b"和"b"了，返回true。
 * 再举个例子，比如s="", p="a*"，由于s为空，不会进入任何的if和while，只能到最后的return来比较了，
 * 返回true，正确）。
 * 
 * */

bool matchCore(const char* str, const char*pattern)
{
	if(*str=='\0' && *pattern=='\0') return true;
	if(*str!='\0' && *pattern=='\0') return false;
//下一个元素是‘*’，那么就判断前一个元素，如果相等，字符串要向后移动一次。
	if(*(pattern+1)=='*')
	{
		if(*pattern==*str|| (*pattern=='.' && *str!='\0'))
			return matchCore(str+1,pattern+2) || 
			matchCore(str+1,pattern)||matchCore(str,pattern+2);
		else
			return matchCore(str,pattern+2);
	}
	if(*str==*pattern ||(*pattern=='.' &&*str!='\0'))
		return matchCore(str+1,pattern+1);
	return false;
}

bool match(const char* str,const char* pattern)
{
	if(str==nullptr || pattern==nullptr)
		return false;
	return matchCore(str,pattern);
}
// 方法2 递归
int
int main()
{
	const char *str = "aaa";
	const char *pattern = "ab*ac*a";
	cout<<match(str,pattern);

}