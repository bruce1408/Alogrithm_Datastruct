#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
using namespace std;

int main()
{
    // 使用getline 读取一整行,包括空格也会计算进去 例如在输入两行字符串的情况，用getline
    //  cin输入不会计算空格，遇到空格会自动结束！；输入两个字符串，中间用空格隔开就用cin
    // 读取一行含有空格的话就用getline,如果是不包含空格，两行字符串的话，就是使用cin
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
    // string s1(10, 'c'), s2 = s1;
    // s2  = "helllo world";
    // for(auto i: s2)
    // {
    //     cout<<i<<" ";
    // }
    // cout<<s2<<endl;
    // string s1;
    // cin>>s1;
    // string s3;
    // getline(cin, s3);
    // cout<<s1<<" "<<s2<<endl;
    // cout<<s1.size()<<endl;
    // cout<<s2.size()<<endl;
    // cout<<s3.size()<<endl;


    string a,b;
    getline(cin,a);
    getline(cin,b);

    for (int i = 0; i < a.size(); i ++)
        if (a[i] >= 'A' && a[i] <= 'Z') a[i] += 32;

    for (int i = 0; i < b.size(); i ++)
        if (b[i] >= 'A' && b[i] <= 'Z') b[i] += 32;

    int c;
    c = strcmp(a.c_str(),b.c_str());
    if(c < 0) cout << "<";
    if(c == 0) cout << "=";
    if(c > 0) cout << ">";

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