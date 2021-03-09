/*394. Decode String 解码字符串
	The encoding rule is: k[encoded_string], 
	where the encoded_string inside the square brackets is being repeated
	exactly k times.Note that k is guaranteed to be a positive integer.
*/
//s = "3[a]2[bc]", return "aaabcbc".
//s = "3[a2[c]]", return "accaccacc".
//s = "2[abc]3[cd]ef", return "abcabccdcdcdef".

#include<iostream>
#include<string>
#include<stack>
using namespace std;
/*解题思路*/
//这道题让我们把一个按一定规则编码后的字符串解码成其原来的模样，
//编码的方法很简单，就是把重复的字符串放在一个中括号里，
//把重复的次数放在中括号的前面，注意中括号里面有可能会嵌套中括号，
//这题可以用递归和迭代两种方法来解，我们首先来看递归的解法，
//我们把一个中括号中的所有内容看做一个整体，
//一次递归函数返回一对中括号中解码后的字符串。
//给定的编码字符串实际上只有四种字符，数字，字母，左中括号，和右中括号。
//那么我们开始用一个变量i从0开始遍历到字符串的末尾，
//由于左中括号都是跟在数字后面，所以我们首先遇到的字符只能是数字或者字母，
//如果是字母，我们直接存入结果中，如果是数字，
//我们循环读入所有的数字，并正确转换，那么下一位非数字的字符一定是左中括号，
//我们指针右移跳过左中括号，对之后的内容调用递归函数求解，
//注意我们循环的停止条件是遍历到末尾和遇到右中括号，
//由于递归调用的函数返回了子中括号里解码后的字符串，
//而我们之前把次数也已经求出来了，那么循环添加到结果中即可

//两种方法 第一中方法，递归求解
string decoding(string &num,int &i)
{
	string res;
	while(i<num.size() && num[i]!=']')// 递归终止的条件
	{
		if(!isdigit(num[i]))
			res+=num[i++];
		else
		{
			int n=0;
			while(i<num.size() && isdigit(num[i]))
				n = n*10+num[i++]-'0';
			i++; //   '['
			string t = decoding(num,i);
			i++; //   ']' 如果没有这个的话，那么就会忽略2[c]后面的这部分
			//因为下一个结束的标志是 num[i]!=']'，会结束循环。所以i++是跳出这一步
			
			while(n-->0)
				res+=t;
		}
	}
	return res;
}

string simple(string num)
{
	int i=0;
	return decoding(num,i);
}


//第二种方法，迭代！
//我们也可以用迭代的方法写出来，当然需要用stack来辅助运算，
//我们用两个stack，一个用来保存个数，一个用来保存字符串，
//我们遍历输入字符串，如果遇到数字，我们更新计数变量cnt；如果遇到左中括号，
//我们把当前cnt压入数字栈中，把当前t压入字符串栈中；如果遇到右中括号时，
//我们取出数字栈中顶元素，存入变量k，然后给字符串栈的顶元素循环加上k个t字符串，
//然后取出顶元素存入字符串t中；如果遇到字母，我们直接加入字符串t中即可，

string decodeString(string s) 
{
	string res = "", t = "";
	stack<int> s_num;
	stack<string> s_str;
	int cnt = 0;
	for (int i = 0; i < s.size(); ++i) 
	{
		if (s[i] >= '0' && s[i] <= '9') //统计字符串重复的数字。
		{
			cnt = 10 * cnt + s[i] - '0';
		} 
		else if (s[i] == '[') 
		{
			s_num.push(cnt);
			s_str.push(t);
			cnt = 0; t.clear();
		} 
		else if (s[i] == ']') 
		{
			int k = s_num.top(); s_num.pop();
			for (int j = 0; j < k; ++j) s_str.top() += t;
			t = s_str.top(); s_str.pop();
		} 
		else 
		{
			t += s[i];
		}
	}
	return s_str.empty() ? t : s_str.top();
}

int main()
{
	string num = "3[a]2[c]";
	cout<<simple(num);
	return 0;
}
























































