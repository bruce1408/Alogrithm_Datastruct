#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

/**
 * 273 把数字转换为字符表示
 * 123 -> "One Hundred Twenty Three"
 * */

/**
 * 方法 1，先把是1-999的范围的数字表示成为一个字符串，然后再按照位数添加
 * 然后这里小于20的数不一样，有单独的表达，所以三位数还要看一下十位是不是小于20
*/
string convertHundred(int num);

string numberToWords(int num)
{
    string res = convertHundred(num % 1000);
    vector<string> v = {"Thousand", "Million", "Billion"};
    for (int i = 0; i < 3; i++)
    {
        num /= 1000;
        res = num % 1000 ? convertHundred(num % 1000) + " " + v[i] + " " + res : res;
    }
    while (res.back() == ' ')
        res.pop_back(); // 123000 比如后面都是0删除 ' '
    return res.empty() ? "Zero" : res;
}

string convertHundred(int num)
{
    vector<string> v1 = {"", "One", "Two", "Three", "Four", "Five",
                         "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve",
                         "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};

    vector<string> v2 = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty",
                         "Seventy", "Eighty", "Ninety"};

    string res;
    int a = num / 100, b = num % 100, c = num % 10;
    res = b < 20 ? v1[b] : v2[b / 10] + (c ? " " + v1[c] : "");
    if (a > 0)
        res = v1[a] + " Hundred" + (b ? " " + res : "");
    return res;
}

/**
 * 方法 2
*/

int main()
{

    cout << numberToWords(294564) << endl;
}
