#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * vector 是变长的数组，不是常规的基本数据类型，而是pair类型的数据类型
 * 新的数据类型的vector如何排序，下面例子可以说明
*/
bool cmp(const pair<int, int> &a, const pair<int, int> &b)
{
    if (a.first == b.first)
    {
        return a.second < b.second;
    }
    return a.first < b.first;
}

int main()
{
    vector<int> oneNum = {2, 1, 2, 3, 4, 5, 1, 9};
    vector<pair<int, int>> res;
    for (int i = 0; i < oneNum.size(); i++)
    {
        res.push_back(pair<int, int>(oneNum[i], i));
    }
    sort(res.begin(), res.end(), cmp);

    // 使用vector<int>::iterator 迭代器或者是auto来比遍历
    for (auto it = oneNum.begin(); it != oneNum.end(); it++)
    {
        cout << *it << endl;
    }
    // 第一个和最后一个元素
    cout << oneNum.front() << " " << oneNum.back() << endl;
    // 删除最后一个元素
    oneNum.pop_back();
    for (auto i : res)
    {
        cout << i.first << ' ' << i.second << endl;
    }
}

/**
 * 翻转reverse vector中的前n个元素
*/
void reverseVector()
{
    vector<int> res = {1, 2, 3, 4, 5, 2, 4};
    auto iter = max_element(res.begin(), res.end());
    cout << iter - res.begin() << endl;
    // reverse(res.begin(), res.begin() + 4);
    for (auto i : res)
    {
        cout << i << " ";
    }
    cout << "hu is: " << endl;
    vector<int> hu(res.begin() + 2, res.end());
    for (auto i : hu)
    {
        cout << i << endl;
    }
    cout << res.back() << endl;
}

/**
 * 对字符数组，有以下几种定义方法：
 * 1)char str[]="12345";
 * 或给字符串加上大括号：char str[]={"12345"};
 * 这种方法定义时，系统会自动在字符串的末尾加上字符串结束符，即 ‘\0’,
 * 2)char str[10]={'1','2','3','4','5'};
 * 这种方法定义时，系统会自动从未初始化的元素开始，将之后的元素赋为\0，如上面的数组str中的元素实际上是：'1','2','3','4','5','\0','\0','\0','\0','\0'
 * 3)char str[]={'1','2','3','4','5'};
 * 这种方法定义时，系统不会自动在字符串的末尾加上字符串结束符;
 * 此时用sizeof()函数可以正确求出其所占的内存大小；
 * 但用strlen()函数不能正确求出其长度，
 * 因为strlen是通过\0判断字符串结束的。
 * c语言风格的数组
 * memset, memcpy分别是 初始化和复制操作 
*/

// #include<cstring>
// int main()
// {
//     int a[10], b[10];
//     // 初始化全是0，这里的是byte，1个整数是4byte，10个就需要40，这里的0是每个byte是赋值为0，或者其他值。使用memset时间更快。
//     memset(a, 0, sizeof(a));
//     for(int i=0;i<10;i++)
//     {
//         cout<<a[i]<<endl;
//     }
//     // 把数组a复制给数组b，最后一个参数是赋值的长度。
//     memcpy(b, a, sizeof(a));
// }