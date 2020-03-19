#include<iostream>
#include<string>
using namespace std;

//3-11
// int main()
// {
	// int a[5] = {1,2,3,4,5};
	// int *pt =(int*)(&a+1);
	// cout<<*(a+1)<<endl;
	// cout<<*(pt-1)<<endl;
	
// }


//3-12


// int main()
// {
	// char str1[] = "abc";
	// char str2[] = "abc";
	// const char str3[] = "abc";
	// const char str4[] = "abc";
	// const char* str5 = "abc";
	// const char* str6 = "abc";
	
	
	// cout<<(str1==str2)<<endl;
	// cout<<(str3==str4)<<endl;
	// cout<<(str5==str6)<<endl;
	// // cout<<(str7==str8)<<endl;
// }


//3_13
// int main()
// {
	// char a;
	// char *str1 = &a;
	// char str2[] = "AAA";
	// // strcpy(str1,"hello");
	// cout<<str1<<endl;
	// str2[0] = 'f';
	// cout<<str2<<endl;
// }

//3_14

int main()
{
	const char* node1 = "abc";
	
	
	node1 = "xyz";
	// node1 = "xyz";
	return 0;
}






















