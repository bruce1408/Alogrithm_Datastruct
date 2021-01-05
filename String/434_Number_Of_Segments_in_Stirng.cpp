#include <iostream>
#include <vector>
#include <string>
using namespace std;

/**
 * 434 求解字符串中单词的个数
 * 输入 s = "hello, this is the world"
 * 输出 5个单词
*/

/**
 * 方法 1，使用双指针算法来做
*/
int countSegments(string s)
{
    int n = s.size();
    int cnt = 0;
    int i = 0;
    while (i < n)
    {
        int j = i;
        while (j < n && s[j] != ' ')
            j++;
        if (j != i)
            cnt++;
        i = j + 1;
    }
    return cnt;
}

/**
 * 方法 2，使用stringstream字符流来处理
*/
int countSegments2(string s)
{
    int cnt = 0;
    stringstream iss(s);
    while (iss >> s)
    {
        cnt++;
    }
    return cnt;
}

/**
 * 方法 3，使用双指针算法，和方法 1写法不同
*/
int countSegments3(string s)
{
    int res = 0;
    int n = s.size();
    for(int i=0;i<n;i++)
    {
        if(s[i]==' ') continue;
        res++;
        while(i<n && s[i]!=' ') i++;
    }
    return res;
}

int main()
{
    string a = "hello    in this world";
    cout << countSegments2(a) << endl;
}