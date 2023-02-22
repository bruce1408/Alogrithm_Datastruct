#include<iostream>
using namespace std;

/**
 * 给定一个只包含字符0和1的字符串，然后按照顺序对多个区间进行反转，字符0变成1，1变成0，
 * 例如：
 * 5 2
 * 01010 输入字符串
 * 1 3
 * 10110 区间1-3反转结果
 * 2 2 
 * 11110 区间2-2反转结果
*/
string reverse_str(int l, int r, string &s)
{
    for(int i = l-1; i<r;i++)
    {
        if(s[i] & 1) s[i] = '0';
        else s[i] = '1';
    }
    return s;
}


int main()
{
    int n , m;
    cin>>n>>m;
    string s ;
    cin>>s;
    while(m--)
    {
        int l , r;
        cin>>l>>r;
        cout<<reverse_str(l, r, s)<<endl;
    }
}