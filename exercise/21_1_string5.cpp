#include<iostream>
#include<string>
using namespace std;
/**
 * 字符串移位包含问题
 * 
 * 对于一个字符串来说，定义一次循环移位操作为：将字符串的第一个字符移动到末尾形成新的字符串。
 * 给定两个字符串s1和s2，要求判定其中一个字符串是否是另一字符串通过若干次循环移位后的新字符串的子串。
 * 例如CDAA是由AABCD两次移位后产生的新串BCDAA的子串，而ABCD与ACBD则不能通过多次移位来得到其中一个字符串是新串的子串。
 * 
 * 输入格式
 * 共一行，包含两个字符串，中间由单个空格隔开。
 * 字符串只包含字母和数字，长度不超过30。
 * 输出格式
 * 如果一个字符串是另一字符串通过若干次循环移位产生的新串的子串，则输出true，否则输出false。
 * 输入样例：
 * AABCD CDAA
 * 输出样例：
 * true
*/
int main()
{
    string s1, s2;
    cin>>s1>>s2;
    if(s1.size() < s2.size()) swap(s1, s2);
    for(int i=0;i<s1.size();i++)
    {
        s1 = s1.substr(1) + s1[0];
        for(int j=0;j+s2.size() < s1.size(); j++)
        {
            int k=0;
            for(k=0;k<s2.size();k++)
            {
                if(s1[k+j] != s2[k]) break;
            }
            if (k==s2.size()) 
            {
                cout<<"true"<<endl;
                return 0;
            }
        }
    }
    cout<<"false"<<endl;
}