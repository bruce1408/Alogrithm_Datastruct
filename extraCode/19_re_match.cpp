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

//利用指针。
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
int main()
{
	const char *str = "aaa";
	const char *pattern = "ab*ac*a";
	cout<<match(str,pattern);

}