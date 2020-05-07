#include <iostream>
#include <vector>
#include <string>
using namespace std;

/**
 * 左减只能是1位，左边减法不能跨级，右加不能超过3位，
*/
/**
 * 方法 1，使用的逻辑算法来解，参考一位网友的解法，就是
*/
string intToRoman(int num)
{
    string res(num / 1000, 'M');
    num %= 1000; // 剩下小于1000的数字了
    if (num >= 900)
    {
        res += "CM";
        num -= 900;
    }
    else if (num >= 500)
    {
        res += "D";
        num -= 500;
    }
    else if (num >= 400)
    {
        res += "CD";
        num -= 400;
    }
    res += string(num / 100, 'C');
    num %= 100;
    if (num >= 90)
    {
        res += "XC";
        num -= 90;
    }
    else if (num >= 50)
    {
        res += "L";
        num -= 50;
    }
    else if (num >= 40)
    {
        res += "XL";
        num -= 40;
    }
    res += string(num / 10, 'X');
    num %= 10;
    if (num == 9)
    {
        return res + "IX";
    }
    else if (num >= 5)
    {
        res += 'V';
        num -= 5;
    }
    else if (num == 4)
    {
        return res + "IV";
    }
    res += string(num, 'I');
    return res;
}

/**
 * 方法 2
*/
string intToRoman2(int num)
{
    string res = "";
    vector<char> roman{'M', 'D', 'C', 'L', 'X', 'V', 'I'};
    vector<int> value{1000, 500, 100, 50, 10, 5, 1};
    for (int n = 0; n < 7; n += 2)
    {
        int x = num / value[n];
        if (x < 4)
        {
            for (int i = 1; i <= x; ++i)
                res += roman[n];
        }
        else if (x == 4)
        {
            res = res + roman[n] + roman[n - 1];
        }
        else if (x > 4 && x < 9)
        {
            res += roman[n - 1];
            for (int i = 6; i <= x; ++i)
                res += roman[n];
        }
        else if (x == 9)
        {
            res = res + roman[n] + roman[n - 2];
        }
        num %= value[n];
    }
    return res;
}

/**
 * 方法 3，对于上面方法 1的写法上的优化
*/
string intToRoman3(int num)
{
    string res = "";
    vector<int> val{1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    vector<string> str{"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    for (int i = 0; i < val.size(); ++i)
    {
        while (num >= val[i])
        {
            num -= val[i];
            res += str[i];
        }
    }
    return res;
}
int main()
{
    cout << intToRoman3(45) << endl;
}