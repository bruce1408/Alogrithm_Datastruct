#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<unordered_map>
#include<unordered_map>
using namespace std;

//50
char first_char(string str)
{
	
	int n = str.size();
	if(n<1)
		return '\0';
	int a[26]={0};
	for(auto i:str) ++a[i-'a'];
	for(auto i:str)
	{
		if(a[i-'a']==1)
		{
			return i;
		}
	}
	return '\0';
}


/*
	字符数组 和 字符串指针：
	书上应该是用字符数组，否则，题目所有值都要变成const char *p;
	字符数组和字符串指针的区别：字符数组在C++11标准实际上个数一般包含终止符，但是C没有包含，strlen和sizeof的区别。另外
	字符串指针指向的是字符串字面值，相当于你只能度，不能写，所以必须是const char * 来修饰，而字符数组没有这个规矩,
	计算字符串指针和字符数组，他们都有‘\0’结束标志符，可以利用这个来计算长度
*/
//50_book
// char Firstnote(char *p)
// {
	// if(p==nullptr)
		// return '\0';
	// const int tablesize=256;
	// unsigned int hashTable[tablesize]={0};
	// char *pHash = p;
	// while(*(pHash)!='\0')
	// {
		// hashTable[*(pHash++)]++;
	// }
	// pHash = p;
	// while(*pHash!='\0')
	// {
		// if(hashTable[*(pHash++)]==1)
			// return *pHash;
	// }
	// return '\0';
// }



//50_1 删除第一个字符中所有在第二个字符出现的个数
void delete_str(string &str1,string &str2)
{
	int a[256] ={0};
	for(char i:str2)
		++a[i];
	for(char &j:str1)
	{
		if(a[j]!=0)
		{
			cout<<j<<endl;
			j = '\0';
		}
	}
}



//50_2
void delete_duplicate_char(string &a)
{
	int n = a.size();
	bool temp[256]={0};
	for(int i=0;i<n;i++)
	{
		if(temp[a[i]]==1)
		{
			a.erase(i,1);         //另一种写法就是用const char*p,指针在这里p++;，跳过这个值，相应的在else增加一个把当前值放进结果的命令。
			--i;
			--n;
		}
		else
			temp[a[i]]=1;	
	}
}


//50_2第二种方法
string stringFilter(const char *pInputString)
{
	string pOutputStr;
	string u = pOutputStr;
	int lInputLen = sizeof(pInputString)-1;
	bool g_flag[26];
   
    int i = 0 ;
    if(pInputString == NULL || lInputLen <= 1)
    {
        return NULL;
    }
    const char *p = pInputString;
    while(*p != '\0')
    {
        if(g_flag[(*p - 'a')]) p++;
        else
        {
            pOutputStr+= *p;
            g_flag[*p - 'a'] = 1;
			
        }
    }	
	return pOutputStr;
}

//50_3 
/*两种思路，第一种思路很好理解，就是用map，带有自动排序功能，最后逐个比较。
	第二种思路就是利用数组，或者是容器，然后比较容器元素是否相同。这里采用第二种思路。*/
bool isAnagram(string a,string b)
{
	if(a.size()!=b.size())
		return false;
	vector<int>temp1(256,0);
	vector<int>temp2(256,0);
	for(auto i:a) ++temp1[i];
	for(auto i:b) ++temp2[i];
	if(temp1==temp2)
		return true;
	else
		return false;

}


int main()
{
	
	//50_2
	// const char *a = "google";
	// string res;
	// res = stringFilter(a);
	// cout<<res;
	//50_3
	// string a = "live";
	// string b = "evil";
	// cout<<isAnagram(a,b);
	return 0;
	
}