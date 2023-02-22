#include<iostream>
#include<string>
#include <sstream>

using namespace std;


string reverseWords1(string &s)
{
	istringstream iss(s);
	string temp;
	iss >> s;
	cout << s << endl;
	while (iss >> temp)
		s = temp + " " + s;
	if (!s.empty() && s[0] == ' ')
		s = ""; //输入是空格的时候，输出为空
	return s;
}

int main()
{
    string a = "hello world the name";
    reverseWords1(a);
}