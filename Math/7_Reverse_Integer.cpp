#include<iostream>
#include<sstream>
#include<string>
using namespace std;
// 翻转整数，考虑到越界问题。
int reverseNum(int x)
{
    int res=0;
    while(x)
    {
        // 如果你翻转越界了，那么就直接为0
        if(abs(res)>INT_MAX/10) return 0; 
        res = res * 10 + x % 10;
        x /= 10;
    }
    return res;
}

int main()
{
    int n = -2134567898;
    cout<<reverseNum(n)<<endl;
    return 0;
}