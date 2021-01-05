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
    while(i<n)
    {
        int j = i;
        
    }

    return cnt;
}

int main()
{
    string a = "hello in this world";
    cout << countSegments(a) << endl;
}