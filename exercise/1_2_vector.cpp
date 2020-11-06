// #include <iostream>
// #include <vector>
// using namespace std;

// /**
//  * vector 不是常规的基本数据类型，而是pair类型的数据类型
//  * 新的数据类型的vector如何排序，下面例子可以说明
// */
// bool cmp(const pair<int, int> &a, const pair<int, int> &b)
// {
//     if (a.first == b.first)
//     {
//         return a.second < b.second;
//     }
//     return a.first < b.first;
// }

// int main()
// {
//     vector<int> oneNum = {2, 1, 2, 3, 4, 5, 1, 9};
//     vector<pair<int, int>> res;
//     for (int i = 0; i < oneNum.size(); i++)
//     {
//         res.push_back(pair<int, int>(oneNum[i], i));
//     }
//     sort(res.begin(), res.end(), cmp);
//     for (auto i : res)
//     {
//         cout << i.first << ' ' << i.second << endl;
//     }
// }

#include <iostream>
#include <vector>
#include <map>
using namespace std;

/**
 * 翻转reverse vector中的前n个元素
*/
// int main()
// {
//     vector<int> res = {1, 2, 3, 4, 5, 2, 4};
//     auto iter = max_element(res.begin(), res.end());
//     cout << iter - res.begin() << endl;
//     // reverse(res.begin(), res.begin() + 4);
//     for (auto i : res)
//     {
//         cout << i << " ";
//     }
//     cout << "hu is: " << endl;
//     vector<int> hu(res.begin() + 2, res.end());
//     for (auto i : hu)
//     {
//         cout << i << endl;
//     }
//     cout << res.back() << endl;
// }


/**
 * c语言风格的数组
 * memset, memcpy分别是 初始化 和 复制 操作 
*/
#include<cstring>
int main()
{
    int a[10], b[10];

    // 初始化全是0，这里的是byte，1个整数是4byte，10个就需要40，这里的0是每个byte是赋值为0，或者其他值。使用memset时间更快。
    memset(a, 0, sizeof(a));  
    for(int i=0;i<10;i++)
    {
        cout<<a[i]<<endl;
    }

    // 把数组a复制给数组b，最后一个参数是赋值的长度。
    memcpy(b, a, sizeof(a));


}