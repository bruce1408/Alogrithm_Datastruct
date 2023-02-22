 /*这个程序的问题就是str1它指的是谁，在函数体内部他是一直指向末尾，但是
  这个没有反应在指针上，回到main函数，指针依然是首地址！有疑问！！？？解决了*/
  //这个p指针最后消失了，但是str1一直再改吧，所以就算返回，也返回的是p，但是最后输出的
  //却是str1.

#include<iostream>
using namespace std;

// void strcat(char *str1,char *str2);
char *strcat(char *str1,char *str2);

int main()
{
	cout<<"input two str:"<<endl;
	char str1[200];
	char str2[50];
	cin>>str1;
	cout<<"next"<<endl;
	cin>>str2;
	// char *q = str1;
	strcat(str1,str2);
	cout<<str1<<endl;
	return 0;
}


char *strcat(char *str1,char *str2)
{
	char *p = str1;
	
	while(*p!='\0')
		p++;
	
	while(*str2!='\0')
	{
		*p = *str2;
		p++;
		str2++;
	}
	*p = '\0';
	return p; //这是有指针的部分
}