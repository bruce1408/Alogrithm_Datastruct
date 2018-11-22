#include<iostream>
using namespace std;
// 判断一个数是否是回文数，考虑负数的情况。
/*
    Input: 121
    Output: true
    Example 2:

    Input: -121
    Output: false
*/ 

int reverse(int x)
{
    int res=0;
    while(x)
    {
        if(res>INT_MAX/10) return -1;// 不能是组大的整数，否则最后一个数字翻转会溢出
        res = res*10 + x%10;
        x/=10;
    }
    return res;
}
bool isPalindrome(int x)
{
    // 如果说是负数或者是个位数字是0的话，那么直接判断不是回文数
    if(x<0 ||(x%10==0&&x!=0)) return false; 
    return reverse(x)==x;
}

int main()
{
    int x ;
    int y = INT_MAX;
    cout<<"input a num: ";
    cin>>x;
    cout<<isPalindrome(x)<<endl;
    return 0;
}