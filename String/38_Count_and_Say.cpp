#include <iostream>
#include <vector>
#include <string>
using namespace std;

/**
 * 38 Count and Say 计数和读法
 * 1.     1
 * 2.     11
 * 3.     21
 * 4.     1211
 * 5.     111221
 * 
 * 给定一个数，然后按照读法来学，1表示1个1，写作11，
 * 11是2个1，写作21， 21是1个2 1个1，写成1211....
 * 每次写的都是前一次的值 
*/

string countAndSay(int n)
{
    string s = "1";
    for (int i = 0; i < n - 1; i++)
    {
        string temp;
        for (int j = 0; j < s.size(); j++)
        {
            int cnt = 1; // 初始化每次字符出现的次数为1次
            while (j + 1 < s.size() && s[j] == s[j + 1])
            {
                cnt++;
                j++;
            }
            temp += to_string(cnt) + s[j];
        }
        s = temp;
    }
    return s;
}

int main()
{
    cout << countAndSay(4) << endl;
}