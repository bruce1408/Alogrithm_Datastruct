#include<iostream>
#include<vector>
using namespace std;


int titleToNumber(string s) 
{
    /*
        输入是字符串，输出是整数。
        A -> 1
        B -> 2
        C -> 3
        ...
        Z -> 26
        AA -> 27
        AB -> 28
        26进制转换成10进制
    */ 
    int n= s.size();
    int temp = 1;
    int res = 0;
    for(int i=n-1;i>=0;i--)
    {
        res += (s[i]-'A'+1)*temp;
        temp*=26;
    }
    return res; 
}

int main()
{
    string a = "AAA";
    cout<<titleToNumber(a);
}