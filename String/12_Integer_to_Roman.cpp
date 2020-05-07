#include <iostream>
#include <vector>
#include <string>
using namespace std;

/**
 * 左减只能是1位，左边减法不能跨级，右加不能超过3位，
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

int main()
{
    cout << intToRoman(45) << endl;
}