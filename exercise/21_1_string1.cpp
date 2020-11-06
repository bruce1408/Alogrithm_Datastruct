// #include<iostream>
// #include<cstdio>
// using namespace std;

// int main()
// {
//     string a;
//     getline(cin, a);
//     cout<<a.size()<<endl;
// }


#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char a[105];
    cin.get(a,105);//需要注意cin.get()不会把换行符取出删除，影响下一次读入！
    cout<<strlen(a)<<endl;
    return 0;
}