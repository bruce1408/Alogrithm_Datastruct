#include<iostream>
#include<string>
#include<sstream>
#include<algorithm>
using namespace std;


//基于字符串流的操作sstream
void reverseWords(string &s)
{
	istringstream iss(s);
	string temp;
	iss>>s;
	while(iss>>temp)
	{
		s = temp+" "+s;
		cout<<s<<endl;
	}
	if(!s.empty() && s[0]==' ') s = "";//输入是空格的时候，输出为空
}


int main()
{
	string s = "hello world my name";
	cout<<"before reverse is: "<<s<<endl;
	reverseWords(s);
	cout<<"after reverse is: "<<s<<endl;
}



  
