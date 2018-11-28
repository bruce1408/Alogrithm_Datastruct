#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
using namespace std;

// 判断版本号的大小，版本1是version1，版本2是version2，用c_str() 函数和 atoi函数即可
int compareVersion(string version1, string version2) 
{
    int v1 = version1.size(), v2 = version2.size();
    int i = 0, j=0, d1=0, d2=0;
    string s1, s2;
    while(i<v1 || j<v2)
    {
        while(i<v1 && version1[i]!='.') s1.push_back(version1[i++]);
        d1 = atoi(s1.c_str());
        while(j<v2 && version2[j]!='.') s2.push_back(version2[j++]);
        d2 = atoi(s2.c_str());
        if(d1>d2) return 1;
        else if(d1<d2) return -1;
        s1.clear(); // 之前的保存要清除
        s2.clear();
        ++i;
        ++j;
    }
    return 0;
}


// 累加每一个数，不是转换成整数判断大小
int compareVersion1(string version1, string version2) 
{
    int n1 = version1.size(), n2 = version2.size();
    int i = 0, j = 0, d1 = 0, d2 = 0;
    while (i < n1 || j < n2) {
        while (i < n1 && version1[i] != '.') d1 = d1 * 10 + version1[i++] - '0';
        while (j < n2 && version2[j] != '.') d2 = d2 * 10 + version2[j++] - '0';
        if (d1 > d2) return 1;
        else if (d1 < d2) return -1;
        d1 = d2 = 0;
        ++i; ++j;
    }
    return 0;
}

// 字符流函数
// int compareVersion2(string version1, string version2) 
// {
//     istringstream v1(version1 + "."), v2(version2 + ".");
//     int d1 = 0, d2 = 0;
//     char dot = '.';
//     while (v1.good() || v2.good()) {
//         if (v1.good()) v1 >> d1 >> dot;
//         if (v2.good()) v2 >> d2 >> dot;
//         if (d1 > d2) return 1;
//         else if (d1 < d2) return -1;
//         d1 = d2 = 0;
//     }
//     return 0;
// }
int main()
{
    string s1 = "1.0.1",s2 = "1";
    cout<<compareVersion(s1, s2);
}