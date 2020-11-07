#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

int main()
{
    // 使用getline 读取一整行
    // string a;
    // getline(cin, a);
    // cout<<a.size()<<endl;
    // int b = 'b'-'a';
    // cout<<b<<endl;
    // char str[100];

    // 遇到空格回停止输入
    // cin >> str;  
    // cout<<str<<endl;
    // printf("%s \n", str);

    // empty 表示是否是空字符
    // string s1, s2 = "abc";
    // cout<<s1.empty()<<endl;
    // cout<<s2.empty()<<endl;

    // 为string 对象赋值
    string s1(10, 'c'), s2 = s1;
    s2  = "helllo world";
    for(auto i: s2)
    {
        cout<<i<<" ";
    }
    cout<<s2<<endl;
}


// #include <iostream>
// #include <cstring>

// using namespace std;

// int main()
// {
//     char a[105];
//     cin.get(a,105);//需要注意cin.get()不会把换行符取出删除，影响下一次读入！
//     cout<<strlen(a)<<endl;
//     return 0;
// }