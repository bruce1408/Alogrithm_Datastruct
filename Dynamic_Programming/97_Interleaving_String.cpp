#include <iostream>
#include <vector>
using namespace std;

/**
 * 97 交错字符串问题，给定三个字符串s1,s2,s3,求问s3是不是s1和s2交错构成的
*/

/**
 * 方法 1，使用动态规划方法来做
 * f[i][j]表示的是所有由s字符串中1-i和t字符串中的1-j交错而成的字符串k[1-i+j]
 * 属性就是集合是否为非空集合；
 * 状态计算：
 * k中的最后一个字符是属于s还是属于t，
 * 如果属于s，那么说明s[1~i-1] 和t中的[1~j]组成的是k[i+j-1],前提保证的是s[i] = k[i+j]
 * f[i][j] = f[i-1,j]
 * 同理，f[i][j] = f[i][j-1];
*/
bool isInterleave(string s1, string s2, string s3)
{
    int n = s1.size(), m = s2.size();
    if(s3.size() != n+m) return false;
    vector<vector<bool>>f(n, vector<bool>(m));

    

}
