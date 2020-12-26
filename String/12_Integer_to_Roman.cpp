#include <iostream>
#include <vector>
#include <string>
using namespace std;

/**
 * 左减只能是1位，左边减法不能跨级，右加不能超过3位，
*/
/**
 * 方法 1，因为通过整张表显示1000,900，500，400，100，90，50，40，0，9, 5, 4, 1
 * 这些数比较特殊，所以可以使用这些数构成一个罗马数字
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
 * 方法 2 直接使用上面的特殊的字段,所有的数字都可以使用下面的这几个数字来凑一个整数出来
*/
string intToRoman2(int num)
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
    cout << intToRoman2(45) << endl;
}